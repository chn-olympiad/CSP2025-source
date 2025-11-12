#include<iostream>
using namespace std;
int main()
{	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	struct node{
		int u;
		int val;
	};
	
	int dis[N],n,m,k;
	vec<pair<int,int>g[n];
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i){
	int u,v,w;
	cin>>u>>v>>w;
	g[u].push_back((v,w));
	g[v].push_back((u,w));
	}
	q.push((1,0));
	while(q.empty() ){
		node tmp=q.front();
		q.pop;
		if(vis[tmp,u]continue);
		for(int i=1;i<=int[g[tmp,u]]);
			if(dis[tmp,u])=dis[dis[tmp,u]]{
				dis[tmp,u]=dis[g[tmp,u]];
				
			}
	}
	cout<<dis[g[tmp,u]];
	return 0;}
	
