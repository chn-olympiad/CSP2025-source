#include<bits/stdc++.h>
using namespace std;
long long dp[1010][1010],vis[1010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long n,m,k;
	for(int i=1;i<=1000;i++){
		for(int j=1;j<=1000;j++){
			dp[i][j]=-1;
		}
		vis[i]=-1;
	}
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		long long a,b,c;
		cin>>a>>b>>c;
		dp[a][b]=c;
		dp[b][a]=c;
	}
	for(int i=1;i<=k;i++){
		long long a,b[1010];
		cin>>a;
		for(int j=1;j<=n;j++){
			cin>>b[j];
			for(int l=1;l<j;l++){
				if(dp[l][j]==-1){
					dp[l][j]=a+b[l]+b[j];
					dp[j][l]=a+b[l]+b[j];
				}else{
					dp[l][j]=min(dp[l][j],a+b[l]+b[j]);
					dp[j][l]=min(dp[j][l],a+b[l]+b[j]);
				}
			}
		}
	}
	long long u=1,ret=0;
	for(int i=1;i<=n;i++){
		vis[u]=1;
		long long mi=-1,id;
		for(int j=1;j<=n;j++){
			if(vis[j]==-1&&dp[u][j]!=-1){
				if(mi==-1||mi>dp[u][j]){
					mi=dp[u][j];
					id=j;
				}
			}
		}
		if(mi==-1){
			mi=0;
		}
		ret+=mi;
		u=id;
	}
	cout<<ret;
	return 0;
}
