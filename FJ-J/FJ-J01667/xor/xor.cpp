#include<bits/stdc++.h>
#define MAX_N 500010
#define MAX_2_POW 5000010
using namespace std;
int n,k;
int prefix[MAX_N],a[MAX_N];
int pos[MAX_2_POW],lft[MAX_N];
int dp[MAX_N],max_dp[MAX_N];
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		prefix[i]=prefix[i-1]^a[i];
		int lft_pre = prefix[i]^k;
		if(lft_pre==0 || pos[lft_pre] != 0) {
			lft[i] = pos[lft_pre]+1;
		}
		pos[prefix[i]] = i;
	}
	int ans = 0;
	for(int i=1;i<=n;i++) {
		int now_lft = lft[i];
		if(now_lft!=0) {
			dp[i] = max_dp[now_lft-1]+1;
		}
		max_dp[i] = max(dp[i],max_dp[i-1]);
		ans = max(dp[i],ans);
	}
	cout<<ans<<endl;
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
