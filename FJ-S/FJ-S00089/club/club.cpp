#include <bits/stdc++.h>

using namespace std;

const int MAXN=505;

int dp[MAXN][MAXN][MAXN];
int val[MAXN][3];
int n;

void work(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d%d%d",&val[i][0],&val[i][1],&val[i][2]);
	for(int i=0;i<=n;++i)
		for(int j=0;j<=n;++j)
			dp[0][i][j]=-2e9;
	dp[0][0][0]=0;
	for(int i=1;i<=n;++i){
//		printf("%d\n",i);
		for(int j=0;j<=n/2;++j)
			for(int k=0;k<=n/2;++k){
				if(i-j-k<0) continue;
				dp[i][j][k]=0;
				dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+val[i][2]);
				if(k) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]+val[i][1]);
				if(j) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k]+val[i][0]);
//				printf("[%d,%d,%d]%d\n",j,k,i-j-k,dp[i][j][k]);
			}
	}
	int ans=0;
	for(int i=0;i<=n/2;++i)
		for(int j=0;j<=n/2;++j)
			if(n-i-j<=n/2) ans=max(ans,dp[n][i][j]);
//	printf("%lld\n",dp[n][2][3]);
//	for(int i=0;i<=n;++i)
//		for(int j=0;j<=n;++j)
//			printf("%d\n",dp[n][i][j]);
	printf("%d\n",ans);
}//

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int T;
	scanf("%d",&T);
	while(T--) work();
	return 0;
}
