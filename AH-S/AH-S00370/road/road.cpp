#include<bits/stdc++.h>
using namespace std;
int n,m,k,v,u,w,a,x,minn,vis[100005];
struct num{
	int pos,wei;
};
vector<num> g[100005];
void dfs(int a,int dis){
	for(int i=1;i<g[a].size();i++){
		if(!vis[g[a][i].pos]){
			vis[g[a][i].pos]=true;
			vis[g[i][a].pos]=true;
			dfs(g[a][i].pos,dis+g[a][i].wei);
			vis[g[a][i].pos]=false;
			vis[g[i][a].pos]=false;
		}
	}
	for(int i=1;i<=n;i++){
		if(vis[i]!=true) break;
	}
	minn=min(minn,dis);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>v>>u>>w;
		g[v].push_back({u,w});
		g[u].push_back({v,w});
	}
	for(int i=1;i<=k;i++){
		cin>>a;
		for(int j=1;j<=n;j++){
			cin>>x;
			g[i].push_back({j,a+x});
			g[j].push_back({i,a+x});
		}
	}
	dfs(1,0);
	cout<<minn;
	return 0;
}
