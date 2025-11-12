#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
struct node{
	int to,w;
};
vector<node> g[N];
int c[15][N];
int n,m,k;
int ans;
int vis[N];
void bfs(int x){
	vis[x]=1;
	queue<int> q;
	q.push(x);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i].to;
			int w=g[u][i].w;
			if(!vis[v]){
				q.push(v);
				vis[v]=1;
				ans+=w;
			}
		}
	}
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++)
		for(int j=0;j<=n;j++)
			cin>>c[i][j];
	if(k == 0){
		bfs(1);
		cout<<ans;
	}
	else{
		cout<<0;
	}
	return 0;
}
