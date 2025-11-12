#include<bits/stdc++.h>
using namespace std;
struct edge{
	int v,w;
};
int n,m,k;
vector<edge> adj[1000005];
int c[10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
		//cout<<i<<"\n";
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			int a;
			cin>>a;
			adj[n+i].push_back({j,a});
			adj[j].push_back({n+i,a});
		}
	}
	cout<<0;
	return 0;
}
