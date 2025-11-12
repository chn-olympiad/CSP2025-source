#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<pair<int,int> >edge[2000205];
int n,m,k,c[15],dis[2000205];
inline void dfs(int x){
	for(auto i:edge[x]){
		if(dis[i.first]==-1)dis[i.first]=dis[x]+i.second,dfs(i.first);
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		edge[u].push_back({v,w});
		edge[v].push_back({u,w});
	}
	int opt=0;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			int w;
			cin>>w;
			opt++;
			edge[opt+n].push_back({j,w});
			edge[j].push_back({opt+n,w});
		}
	}
	for(int i=1;i<=2000200;i++)dis[i]=-1;
	for(int i=1;i<=n;i++)dfs(i);
//	for(int i=1;i<=n;i++)cout<<dis[i]<<" ";
	cout<<dis[n];
	return 0;
}
