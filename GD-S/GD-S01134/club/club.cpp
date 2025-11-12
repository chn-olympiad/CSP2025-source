#include<bits/stdc++.h>
using namespace std;
const long long N=1e5+5;
long long T,n,a[N][3],ans;
struct nome{
	long long x,a,b,c;
}dp[N][3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		memset(dp,0,sizeof dp);
		scanf("%lld",&n);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				scanf("%lld",&a[i][j]);
				dp[i][j].x=a[i][j];
			}
		} 
		for(int i=2;i<=n;i++){
			if(dp[i-1][1].a+1<=n/2&&dp[i-1][1].x+a[i][1]>dp[i][1].x)dp[i][1].x=dp[i-1][1].x+a[i][1],dp[i][1].a=dp[i-1][1].a+1,dp[i][1].b=dp[i-1][1].b,dp[i][1].c=dp[i-1][1].c;
			if(dp[i-1][2].a+1<=n/2&&dp[i-1][2].x+a[i][1]>dp[i][1].x)dp[i][1].x=dp[i-1][2].x+a[i][1],dp[i][1].a=dp[i-1][2].a+1,dp[i][1].b=dp[i-1][2].b,dp[i][1].c=dp[i-1][2].c;
			if(dp[i-1][3].a+1<=n/2&&dp[i-1][3].x+a[i][1]>dp[i][1].x)dp[i][1].x=dp[i-1][3].x+a[i][1],dp[i][1].a=dp[i-1][3].a+1,dp[i][1].b=dp[i-1][3].b,dp[i][1].c=dp[i-1][3].c;
			if(dp[i-1][1].b+1<=n/2&&dp[i-1][1].x+a[i][2]>dp[i][2].x)dp[i][2].x=dp[i-1][1].x+a[i][2],dp[i][2].b=dp[i-1][1].b+1,dp[i][2].a=dp[i-1][1].a,dp[i][2].c=dp[i-1][1].c;
			if(dp[i-1][2].b+1<=n/2&&dp[i-1][2].x+a[i][2]>dp[i][2].x)dp[i][2].x=dp[i-1][2].x+a[i][2],dp[i][2].b=dp[i-1][2].b+1,dp[i][2].a=dp[i-1][2].a,dp[i][2].c=dp[i-1][2].c;
			if(dp[i-1][3].b+1<=n/2&&dp[i-1][3].x+a[i][2]>dp[i][2].x)dp[i][2].x=dp[i-1][3].x+a[i][2],dp[i][2].b=dp[i-1][3].b+1,dp[i][2].a=dp[i-1][3].a,dp[i][2].c=dp[i-1][3].c;
			if(dp[i-1][1].c+1<=n/2&&dp[i-1][1].x+a[i][3]>dp[i][3].x)dp[i][3].x=dp[i-1][1].x+a[i][3],dp[i][3].c=dp[i-1][1].c+1,dp[i][3].b=dp[i-1][1].b,dp[i][3].a=dp[i-1][1].a;
			if(dp[i-1][2].c+1<=n/2&&dp[i-1][2].x+a[i][3]>dp[i][3].x)dp[i][3].x=dp[i-1][2].x+a[i][3],dp[i][3].c=dp[i-1][2].c+1,dp[i][3].b=dp[i-1][2].b,dp[i][3].a=dp[i-1][2].a;
			if(dp[i-1][3].c+1<=n/2&&dp[i-1][3].x+a[i][3]>dp[i][3].x)dp[i][3].x=dp[i-1][3].x+a[i][3],dp[i][3].c=dp[i-1][3].c+1,dp[i][3].b=dp[i-1][3].b,dp[i][3].a=dp[i-1][3].a;
			
		}
		printf("%lld\n",max(dp[n][1].x,max(dp[n][2].x,dp[n][3].x)));
	}
	return 0;
} 
/*3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0*/
