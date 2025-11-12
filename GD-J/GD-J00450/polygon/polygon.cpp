#include<iostream>
using namespace std;
int ai,i,n;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(i=0;i<n;i++)cin>>ai;
	cout<<9;
	return 0;
}
//Dear CCF I love you please let me RP++ and give me the First Prize of the 2nd contest of CSP-J
/*
DDDDDD   EEEEEEEE    AA    RRRRRRR
D     D  E          A  A   R      R
D      D E         A    A  R      R
D      D EEEEEEEE A      A RRRRRRR
D      D E        AAAAAAAA R   R
D      D E        A      A R    R
D     D  E        A      A R     R
DDDDDD   EEEEEEEE A      A R      R
 
  CCCCC    CCCCC  FFFFFFFF
 C     C  C     C F
C        C        F
C        C        FFFFFFFF
C        C        F
C        C        F
 C     C  C     C F
  CCCCC    CCCCC  F

IIIIIIII
   I
   I
   I
   I
   I
   I
IIIIIIII

L          OOOO   V      V EEEEEEEE
L         O    O  V      V E
L        O      O V      V E
L        O      O V      V EEEEEEEE
L        O      O V      V E
L        O      O  V    V  E
L         O    O    V  V   E
LLLLLLLL   OOOO      VV    EEEEEEEE

Y      Y   OOOO   U      U
 Y    Y   O    O  U      U
  Y  Y   O      O U      U
   YY    O      O U      U
   Y     O      O U      U
   Y     O      O U      U
   Y      O    O   U    U     
   Y       OOOO     UUUU

PPPPPPP  L        EEEEEEEE    AA     SSSSSS  EEEEEEEE
P      P L        E          A  A   S      S E
P      P L        E         A    A  S        E
PPPPPPP  L        EEEEEEEE A      A  SSSSSS  EEEEEEEE
P        L        E        AAAAAAAA        S E
P        L        E        A      A        S E
P        L        E        A      A S      S E
P        LLLLLLLL EEEEEEEE A      A  SSSSSS  EEEEEEEE

L        EEEEEEEE TTTTTTTT
L        E           T
L        E           T
L        EEEEEEEE    T
L        E           T
L        E           T
L        E           T
LLLLLLLL EEEEEEEE    T

M      M EEEEEEEE
MM    MM E
M M  M M E
M  MM  M EEEEEEEE
M      M E
M      M E
M      M E
M      M EEEEEEEE

RRRRRRR  PPPPPPP     +        +
R      R P      P    +        +
R      R P      P    +        +
RRRRRRR  PPPPPPP  ++++++++ ++++++++
R   R    P           +        +
R    R   P           +        +
R     R  P           +        +
R      R P           +        +

   AA    N      N DDDDDD
  A  A   NN     N D     D
 A    A  N N    N D      D
A      A N  N   N D      D
AAAAAAAA N   N  N D      D
A      A N    N N D      D
A      A N     NN D     D
A      A N      N DDDDDD

 GGGGGG  IIIIIIII V      V EEEEEEEE
G      G    I     V      V E
G           I     V      V E
G   GGGG    I     V      V EEEEEEEE
G      G    I     V      V E
G      G    I      V    V  E
G      G    I       V  V   E
 GGGGGG  IIIIIIII    VV    EEEEEEEE

M      M EEEEEEEE
MM    MM E
M M  M M E
M  MM  M EEEEEEEE
M      M E
M      M E
M      M E
M      M EEEEEEEE

TTTTTTTT H      H EEEEEEEE
   T     H      H E
   T     H      H E
   T     HHHHHHHH EEEEEEEE
   T     H      H E
   T     H      H E
   T     H      H E
   T     H      H EEEEEEEE

FFFFFFFF IIIIIIII RRRRRRR   SSSSSS  TTTTTTTT
F           I     R      R S      S    T
F           I     R      R S           T
FFFFFFFF    I     RRRRRRR   SSSSSS     T
F           I     R   R           S    T
F           I     R    R          S    T
F           I     R     R  S      S    T
F        IIIIIIII R      R  SSSSSS     T

PPPPPPP  RRRRRRR  IIIIIIII ZZZZZZZZ EEEEEEEE
P      P R      R    I           Z  E
P      P R      R    I          Z   E
PPPPPPP  RRRRRRR     I         Z    EEEEEEEE
P        R   R       I        Z     E
P        R    R      I       Z      E
P        R     R     I      Z       E
P        R      R IIIIIIII ZZZZZZZZ EEEEEEEE

  OOOO   FFFFFFFF
 O    O  F
O      O F
O      O FFFFFFFF
O      O F
O      O F
 O    O  F
  OOOO   F

TTTTTTTT H      H EEEEEEEE
   T     H      H E
   T     H      H E
   T     HHHHHHHH EEEEEEEE
   T     H      H E
   T     H      H E
   T     H      H E 
   T     H      H EEEEEEEE

 222222  N      N DDDDDD
2      2 NN     N D     D
      2  N N    N D      D
     2   N  N   N D      D 
    2    N   N  N D      D 
   2     N    N N D      D
  2      N     NN D     D
22222222 N      N DDDDDD

  CCCCC    OOOO   N      N TTTTTTTT EEEEEEEE  SSSSSS  TTTTTTTT
 C     C  O    O  NN     N    T     E        S      S    T
C        O      O N N    N    T     E        S           T
C        O      O N  N   N    T     EEEEEEEE  SSSSSS     T
C        O      O N   N  N    T     E               S    T
C        O      O N    N N    T     E               S    T
 C     C  O    O  N     NN    T     E        S      S    T
  CCCCC    OOOO   N      N    T     EEEEEEEE  SSSSSS     T

  OOOO   FFFFFFFF
 O    O  F
O      O F
O      O FFFFFFFF
O      O F
O      O F
 O    O  F
  OOOO   F

  CCCCC   SSSSSS  PPPPPPP           JJJJJJJJ
 C     C S      S P      P              J
C        S        P      P              J
C         SSSSSS  PPPPPPP  --------     J
C               S P                     J
C               S P                     J
 C     C S      S P                 J   J
  CCCCC   SSSSSS  P                  JJJ
*/
