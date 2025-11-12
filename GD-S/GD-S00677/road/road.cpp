#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	int n,m,k;
	cin >> n >> m >> k;
	vector<vector<int> > road(n+1);
	vector<vector<int> > money(n+1,vector<int>(n+1,0));
	vector<int> cts(k+1);
	vector<vector<int> > c_road(k+1,vector<int>(n+1));
	
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		road[u].push_back(v);
		road[v].push_back(u);
		money[u][v]=w;
		money[v][u]=w;
	}
	
	for(int i=1;i<=k;i++){
		cin >> cts[i];
		for(int j=1;j<=n;j++){
			cin >> c_road[i][j];
		}
	}
	
	int mix=1e9+5;
	for(int j=1;j<=n;j++)
	{
	
	vector<int> dp(n+1,-1);
//	vector<int> visited(n+1);
	queue<int> q;
	int ans=0;
	
	q.push(j);
	dp[j]=0;
	while(!q.empty()){
		int u;
		u=q.front();
		q.pop();
		
		for(int v : road[u]){
			if(dp[v]!=-1)continue;
			q.push(v);
			dp[v]=money[u][v]+dp[u];
			ans=max(ans,dp[v]);
		}
	}
	mix=min(mix,ans);
	}
	
	cout << mix << endl;
	
	return 0;
}
