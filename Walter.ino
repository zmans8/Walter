#define NONE  48
#define UP  49
#define DOWN 50
#define LEFT 51
#define RIGHT 52
#define X 53
#define O 54
#define SQUARE 55
#define TRIANGLE 56
#define SELECT 57
#define START 65

// Looking at Walter head on with both H-drives at the back wheels
// below is the listing for the pins on the left H_drive
int leftEnableA = 2;
int leftP1 = 3;
int leftP2 = 4;
int leftP3 = 5;
int leftP4 = 6;
int leftEnableB = 7;

// below is the listing for the right H-drive
int rightEnableA = 8;
int rightP1 = 9;
int rightP2 = 10;
int rightP3 = 11;
int rightP4 = 12;
int  rightEnableB= 13;
// variable to recieve data from serial port
char val;

////function to set all pins low

void pinLow ()
{
  digitalWrite(rightEnableA,LOW);
  digitalWrite(rightEnableB,LOW);
  digitalWrite(rightP1, LOW);
  digitalWrite(rightP2, LOW);
  digitalWrite(rightP3, LOW);
  digitalWrite(rightP4, LOW);
  
  digitalWrite(leftEnableA,LOW);
  digitalWrite(leftEnableB,LOW);
  digitalWrite(leftP1,LOW);
  digitalWrite(leftP2,LOW);
  digitalWrite(leftP3,LOW);
  digitalWrite(leftP4,LOW);
} 
  
///////setup functions for turning
///left side first
void motorBackLeftForward ()
{
  digitalWrite(leftEnableA,HIGH);
  digitalWrite(leftP1,HIGH);
  digitalWrite(leftP2,LOW);
}

void motorBackLeftBack()
{
 digitalWrite(leftEnableA,HIGH);
 digitalWrite(leftP2,HIGH);
 digitalWrite(leftP1,LOW); 
}

void motorFrontLeftForward()
{
 digitalWrite(leftEnableB,HIGH);
 digitalWrite(leftP3,HIGH);
 digitalWrite(leftP4,LOW); 
}

void motorFrontLeftBack()
{
 digitalWrite(leftEnableB,HIGH);
 digitalWrite(leftP4,HIGH);
 digitalWrite(leftP3,LOW);
}

//////
//// Right side functions
/*void motorBackRightForward()
{
 digitalWrite(rightEnableB,HIGH);
 digitalWrite(rightP3,HIGH);
 digitalWrite(rightP4,LOW); 
}

void motorBackRightBack()
{
 digitalWrite(rightEnableB,HIGH);
 digitalWrite(rightP4,HIGH);
 digitalWrite(rightP3,LOW); 
}

void motorFrontRightForward()
{
 digitalWrite(rightEnableA,HIGH);
 digitalWrite(rightP1,HIGH);
 digitalWrite(rightP2,LOW);
}

void motorFrontRightBack()
{
 digitalWrite(rightEnableA,HIGH);
 digitalWrite(rightP2,HIGH);
 digitalWrite(rightP1,LOW); 
}
*/
/// Functions for turning left right backwards and forwards

void turnRight ()
{
  digitalWrite(rightEnableA,HIGH);
  digitalWrite(rightEnableB,HIGH);
  digitalWrite(rightP1,HIGH);
  digitalWrite(rightP2,LOW);
  digitalWrite(rightP3,HIGH);
  digitalWrite(rightP4,LOW);
  
  
  digitalWrite(leftEnableA,HIGH);
  digitalWrite(leftEnableB,HIGH);
  digitalWrite(leftP1,LOW);
  digitalWrite(leftP2,HIGH);
  digitalWrite(leftP3,LOW);
  digitalWrite(leftP4,HIGH);
}

void turnLeft()
{
  digitalWrite(rightEnableA,HIGH);
  digitalWrite(rightEnableB,HIGH);
  digitalWrite(rightP1,LOW);
  digitalWrite(rightP2,HIGH);
  digitalWrite(rightP3,LOW);
  digitalWrite(rightP4,HIGH);
  
  
  digitalWrite(leftEnableA,HIGH);
  digitalWrite(leftEnableB,HIGH);
  digitalWrite(leftP1,HIGH);
  digitalWrite(leftP2,LOW);
  digitalWrite(leftP3,HIGH);
  digitalWrite(leftP4,LOW);
}

void goForward()
{
  digitalWrite(rightEnableA,HIGH);
  digitalWrite(rightEnableB,HIGH);
  digitalWrite(rightP1,HIGH);
  digitalWrite(rightP2,LOW);
  digitalWrite(rightP3,HIGH);
  digitalWrite(rightP4,LOW);
  
  
  digitalWrite(leftEnableA,HIGH);
  digitalWrite(leftEnableB,HIGH);
  digitalWrite(leftP1,HIGH);
  digitalWrite(leftP2,LOW);
  digitalWrite(leftP3,HIGH);
  digitalWrite(leftP4,LOW);
}

void goBack()
{
  digitalWrite(rightEnableA,HIGH);
  digitalWrite(rightEnableB,HIGH);
  digitalWrite(rightP1,LOW);
  digitalWrite(rightP2,HIGH);
  digitalWrite(rightP3,LOW);
  digitalWrite(rightP4,HIGH);
  
  
  digitalWrite(leftEnableA,HIGH);
  digitalWrite(leftEnableB,HIGH);
  digitalWrite(leftP1,LOW);
  digitalWrite(leftP2,HIGH);
  digitalWrite(leftP3,LOW);
  digitalWrite(leftP4,HIGH);
}

// set up all the pins on both H-drives to outputs
void setup()
 {
   ///Left side
   pinMode(leftEnableA,OUTPUT);
   pinMode(leftP1,OUTPUT);
   pinMode(leftP2,OUTPUT);
   pinMode(leftP3,OUTPUT);
   pinMode(leftP4,OUTPUT);
   pinMode(leftEnableB,OUTPUT);
   //////////
   
   ///Right side
   pinMode(rightEnableA,OUTPUT);
   pinMode(rightP1,OUTPUT);
   pinMode(rightP2,OUTPUT);
   pinMode(rightP3,OUTPUT);
   pinMode(rightP4,OUTPUT);
   pinMode(rightEnableB,OUTPUT);
   Serial.begin(9600);
   
  
 }
 
 ///////////////////////////*
 
 
 
 
 ////////////*/
 void loop ()
 {
   
   if (Serial.available())    /// if data is available
   {
    val = Serial.read();
   
   if (val == UP)
   {
    goForward(); 
   }
   if (val== LEFT)
   {
    turnLeft(); 
   }
   if (val== RIGHT)
   {
     turnRight();
   }
   if (val==DOWN)
   {
    goBack(); 
   }
 /*  if(val=='Q')
   {
     digitalWrite(rightEnableA,LOW);
     digitalWrite(rightEnableB,HIGH);
     digitalWrite(rightP4,HIGH); 
     delay(5000);
     digitalWrite(rightEnableB,LOW);
     digitalWrite(rightP4,LOW); 
   }*/
   if (val == NONE)
   {
     pinLow();
   }
   //val = 0;
   }
   /*
   
   digitalWrite(rightEnableA, HIGH);
   digitalWrite(rightEnableB, HIGH);
   digitalWrite(rightP1, HIGH);
   digitalWrite(rightP2, LOW);
   digitalWrite(rightP3, HIGH);
   digitalWrite(rightP4, LOW);
   delay(1000);
   digitalWrite(rightP1, LOW);
   digitalWrite(rightP2, HIGH);
   digitalWrite(rightP3, LOW);
   digitalWrite(rightP4, HIGH);
   delay(1000);
   digitalWrite(rightP1, HIGH);
   digitalWrite(rightP2, LOW);
   digitalWrite(rightP3, HIGH);
   digitalWrite(rightP4, LOW);
   delay(1000);
   digitalWrite(rightP1, LOW);
   digitalWrite(rightP2, HIGH);
   digitalWrite(rightP3, LOW);
   digitalWrite(rightP4, HIGH);
   delay(1000);
   */
 }

   
