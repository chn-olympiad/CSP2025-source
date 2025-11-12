//GZ-S00332 贵州省实验中学 王满霖
#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int dp[N][N];
int b[12][1000010];
int main(){
	freopen("road.in","w",stdin);
	freopen("road.out","r",stdout);
	int n,m,K;cin>>n>>m>>K;
	int sum=0;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		dp[u][v]=w;
	}
	for(int j=1;j<=K;j++){
		cin>>b[j][0];
		for(int i=1;i<=n;i++) cin>>b[j][i];
	}
	for(int k=1;k<=K;k++){
		int sb=b[k][0];
		for(int i=1;i<=n;i++){
			bool sbsb=false;
			for(int j=i+1;j<=n;j++){
				if(dp[i][j]>(b[k][i]+b[k][j])) sb-=dp[i][j]-(b[k][i]+b[k][j]);
				if(sb<=0){
					sum+=b[k][0];
					b[k][0]=-1;
					sbsb=true;
					break;
				}
			}
			if(sbsb) break;
		} 
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=1;k<=K;k++){
				if(b[k][0]==-1){
					dp[i][j]=min(dp[i][j],b[k][i]+b[k][j]);
				}
			}
			sum+=dp[i][j];
		}
	}
	cout<<sum;
	return 0;
} 
