#include<bits/stdc++.h>
#define int long long
#define MAX_N 5010
#define MOD 998244353
using namespace std;

int n,ans=0;
int a[MAX_N],vis[MAX_N];
void dfs(int x,int sum,int cnt,int max_a,int is_chk) {
	if(sum>=3 && cnt>(2*max_a) && is_chk) {
		ans=(ans+1)%MOD;
	}
	if(x>n) {
		return ;
	}
	dfs(x+1,sum+1,cnt+a[x],max(max_a,a[x]),true);
	dfs(x+1,sum,cnt,max_a,false);
	return ;
}
signed main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	dfs(1,0,0,0,false);
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
