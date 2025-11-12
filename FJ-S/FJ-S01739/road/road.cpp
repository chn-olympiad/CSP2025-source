#include<bits/stdc++.h>
using namespace std;
int n,m,k,c;
int dp[10005][10005];
int main(){
	freopen("road1.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	int u,v,w;
	for(int i=1;i<=n+k;i++){
		for(int j=i+1;j<=n+k;j++){
			dp[i][j]=dp[j][i]=1e9;
		}
	}
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&u,&v,&w);
		dp[u][v]=dp[v][u]=w;
	}
	int cnt=n;
	for(int i=0;i<k;i++){
		cnt++;scanf("%d",&c);
		dp[cnt][cnt]=c;
		for(int j=1;j<=n;j++){
			scanf("%d",&w);
			dp[j][cnt]=dp[cnt][j]=w;
		}
	}
	for(int q=1;q<=n;q++){
	for(int i=1;i<=n;i++){
	for(int j=1;j<=n;j++){
		dp[i][j]=dp[j][i]=min(dp[i][j],dp[i][q]+dp[q][j]);
	}}}	
//	for(int i=1;i<=cnt;i++){
//	for(int j=1;j<=cnt;j++){
//			printf("%d ",dp[i][j]);
//		}printf("\n");
//	}	
	int ans=-1;
	for(int i=2;i<=n;i++){
		ans=max(dp[1][i],ans);
	}
	printf("%d",ans);
	return 0;
}
