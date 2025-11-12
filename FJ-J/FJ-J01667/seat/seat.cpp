#include<bits/stdc++.h>
#define MAX_N 15
using namespace std;
int n,m,k;
int a[MAX_N*MAX_N];
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) {
		cin>>a[i];
	}
	k = a[1];
	sort(a+1,a+1+(n*m),[](int x,int y){return x>y;});
	for(int i=1;i<=n*m;i++) {
		if(a[i]==k) {
			int coll = ceil(1.0*i/n);
			int mod = i%n;
			if(mod==0) mod=n;
			int roww = (coll%2)?(mod):(n-mod+1);
			cout<<coll<<" "<<roww<<endl;
			return 0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
3 3
94 95 96 97 98 99 100 93 92
*/
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
