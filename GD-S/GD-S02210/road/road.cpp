//road
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+100;
long long n,m,k,u,v,w,dp[1005][1005],cl[N];
unsigned long long ans;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k; 
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		dp[u][v]=w;
		dp[v][u]=w;
	}
	for(int i=1;i<=k;i++){
		long long c;
		cin>>c;
		for(int j=1;j<=n;j++){
			cin>>cl[j];
		}
		for(int j=1;j<=n;j++){
			for(int o=j+1;o<=n;o++){
				if(cl[j]+cl[o]+c<dp[j][o]){
					dp[j][o]=cl[j]+cl[o]+c;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			long long a=-1;
			for(int t=1;t<=n;t++){
				if(dp[i][j]>dp[i][t]+dp[t][j]){
					//cout<<i<<j<<t;
					dp[i][j]=dp[i][t]+dp[t][j];
				    dp[j][i]=dp[i][t]+dp[t][j];
				    
				    a=t;
				}
			}
			ans+=dp[i][j];
			dp[i][a]=0;
			dp[a][i]=0;
			dp[j][a]=0;
			dp[a][j]=0;
			dp[i][j]=0;
			dp[j][i]=0;
		}
	}
	/*for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			ans+=dp[i][j];
		}
	}*/
	cout<<ans;
	return 0;
}
