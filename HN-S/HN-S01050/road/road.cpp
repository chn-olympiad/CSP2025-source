#include<bits/stdc++.h>
//#define int long long
using namespace std;
int n,m,k,dp[(int)1e4+5][(int)1e4+5];
struct Node{
	int v,w;
};
vector<Node> vct[(int)1e6+5];
void add_edge(int u,int v,int w){
	vct[u].push_back({v,w});
	vct[v].push_back({u,w});
	dp[u][v]=dp[v][u]=w;
}
void floyd(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			for(int k=1;k<=n;k++){
				dp[i][j]=dp[j][i]=min(dp[i][k]+dp[k][j],dp[i][j]);
			}
		}
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	//
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dp[i][j]=1e9;
		}
	}
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		add_edge(u,v,w);
	}
	for(int i=1;i<=k;i++){
		int dq;
		cin>>dq;
		int a[n+5];
		for(int j=1;j<=n;j++){
			cin>>a[j];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++){
				add_edge(i,j,a[i]+a[j]+dq);
			}
		}
	}
	floyd();
	int maxi=-1e9+5;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			maxi=max(maxi,(dp[i][j]==1e9?0:dp[i][j]));
		}
	}
	cout<<maxi;
	return 0;
}
//
/*
 4 4 2
 1 4 6
 2 3 7
 4 2 5
 4 3 4
 1 1 8 2 4
 100 1 3 2 4

*/

