#include<bits/stdc++.h>
using namespace std;
int n,m,k; 
int a[15][10005],c[15];
vector<vector<pair<int,int>>> g(m);
void dfs(int sum,int st,int u){
	if(st==n){
		return ;
	}
	dfs(sum+g[u].front().second,st+1,g[u].front().first);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin>>n>>m>>k;
	
	for(int i=1; i<=m; i++){
		int u,v,w;
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	for(int i=1; i<=k; i++){
		cin>>c[i];
		for(int j=1; j<=n; j++){
			cin>>a[i][j];
		}
	}
	int sum=0;
	dfs(0,0,1);
	cout<<sum;
	return 0;
}