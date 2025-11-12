#include<bits/stdc++.h>

using namespace std;

string s;
long long t[15];
int lens;
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	lens=s.length();
	for(int i=0;i<lens;i++) {
		if(s[i]>='0'&&s[i]<='9') {
			t[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--) {
		while(t[i]>0) {
			cout<<i;
			t[i]--;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
Do NoT GO GENTle inTO THaT GOOd nighT.
----------------------------------------------
TTTTTTTT	H      H	EEEEEEEE
   TT   	H      H	E
   TT   	H      H	E
   TT   	HHHHHHHH	EEEEEEEE
   TT   	H      H	E
   TT   	H      H	E
   TT   	H      H	EEEEEEEE

33333333	RRRRRRRR	DDDD
       3	R      R	D   DD
       3	R      R	D     D
33333333	RRRRRRRR	D      D
       3	RRR    		D     D
       3	R  RR 		D   DD 
33333333	R    RRR	DDDD

CCCCCCCC	SSSSSSSS    PPPPPPPP
C       	S       	P      P
C       	S       	P      P
C       	SSSSSSSS	PPPPPPPP
C       	       S	P
C       	       S	P
CCCCCCCC	SSSSSSSS	P

H      H	AAAAAAAA	PPPPPPPP	PPPPPPPP	Y      Y 
H      H	A      A	P      P	P      P	 Y    Y
H      H	A      A	P      P	P      P	  Y  Y
HHHHHHHH	AAAAAAAA	PPPPPPPP	PPPPPPPP	   YY
H      H	A      A	P       	P       	   YY
H      H	A      A	P       	P       	   YY
H      H	A      A	P       	P       	   YY
----------------------------------------------
*/

