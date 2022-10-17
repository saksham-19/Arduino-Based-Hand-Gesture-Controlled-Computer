const int trigger1 = 3; //Trigger pin of 1st Sesnor
const int echo1 = 4; //Echo pin of 1st Sesnor
const int trigger2 = 5; //Trigger pin of 2nd Sesnor
const int echo2 = 6;//Echo pin of 2nd Sesnor

int distL,distR;
long duration; 
float r; 
unsigned long temp=0;
int temp1=0;
int l=0;
void find_distance (void);
void find_distance (void)                   
{ 
  digitalWrite(trigger1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger1, LOW);
  duration = pulseIn(echo1, HIGH);
  r = 3.4 * duration / 2;                      
  distL = r / 100.00;
  if (distL>50)
  { distL=50;
    }
  //delay(100);
  digitalWrite(trigger2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger2, LOW);

  duration = pulseIn(echo2, HIGH);
  r = 3.4 * duration / 2;     
  distR = r / 100.00;
  if (distR>50)
  { distR=50;
    }
  
  delay(100);
}



  
 

void setup() {
Serial.begin(9600); 
  
pinMode(trigger1, OUTPUT); 
pinMode(echo1, INPUT); 
pinMode(trigger2, OUTPUT); 
pinMode(echo2, INPUT);
delay(1000); 
}

void loop() { //infinite loop

find_distance();

//Uncomment for debugging
Serial.print("L=");
Serial.println(distL);
Serial.print("R=");
Serial.println(distR);


//Pause Modes -Hold
if (distL <15 && distR<15) //Detect both hands
{Serial.println("Play/Pause"); 
delay (500);
find_distance();}


 
//Control Modes

//Rewind
if (distL<=15 && distR>=50)
{
      Serial.println ("Rewind");
     // Serial.println ("Down"); 
      delay (10);
}

//Forward
if (distL>=50 && distR<=10)
{
      Serial.println ("Forward"); 
     // Serial.println ("UP");
      delay (10);
}
//Next
if ((distL>15 && distL<50) && distR<=10)
{
      Serial.println ("Vup");
       
      delay (50);
}
//Previous
if (distL<=15 && (distR>15 && distR<50))
{
      Serial.println ("Vdown"); 
      delay (50);
}
//Scroll UP
/*if ((distL>=20 && distL<50) && (distR>=20 && distR<50))
{
      if(distL<distR)
      {Serial.println ("Down"); 
      delay (100);}
      if(distR<distL)
      {Serial.println ("UP"); 
      delay (100);}
}*/
/*if ((distL>15 && distL<50) && distR=50)
{
     // Serial.println ("Rewind");
      Serial.println ("Down"); 
      delay (10);
}
if (distL=50 && (distR>=15 && distR<50)
{
      //Serial.println ("Forward"); 
      Serial.println ("UP");
      delay (10);
}*/

delay(500);
}
