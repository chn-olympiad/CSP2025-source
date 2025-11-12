#include<bits/stdc++.h>
using namespace std;
int n,t,ace[100001][3];
long long dp[100001][3];
long long maxn(long long a,long long b,long long c){
	if(a>b&&a>c) return a;
	else if(b>c) return b;
	else return c;
}
long long dpcmp(int x,int y){
	if(y==0) return dp[x][1]>=dp[x][2]?dp[x][1]:dp[x][2];
	else if(y==1) return dp[x][0]>=dp[x][2]?dp[x][0]:dp[x][2];
	else return dp[x][0]>=dp[x][1]?dp[x][0]:dp[x][1];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		memset(dp,0,sizeof(dp));
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d%d%d",&ace[i][0],&ace[i][1],&ace[i][2]);
		for(int i=1;i<=n;i++){
			if(i<=n/2){
				int ma=maxn(dp[i-1][0],dp[i-1][1],dp[i-1][2]);
				for(int j=0;j<3;j++) dp[i][j]=ma+ace[i][j];
			}
			else for(int j=0;j<3;j++)
				dp[i][j]=dpcmp(i-1,j)+ace[i][j];
		}
		printf("%lld\n",maxn(dp[n][0],dp[n][1],dp[n][2]));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
