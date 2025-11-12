#include<bits/stdc++.h>
using namespace std;
struct Node{
	int v,w;
};
int n,m,k;
long long ans;
vector<Node>g[10015];
long long dis[10015];
bool vis[10015];
void dij(){
	priority_queue<int,vector<int>,greater<int>>q;
	q.push(1);
	for(int i=2;i<=n;i++) dis[i]=1e14;
	while(!q.empty()){
		int t=q.top();
		q.pop();
		vis[t]=1;
		for(int i=0;i<g[t].size();i++){
			int v=g[t][i].v;
			if(dis[v]>dis[t]+g[t][i].w&&!vis[v]){
				dis[v]=dis[t]+g[t][i].w;
				ans+=g[t][i].w;
				q.push(v);
			}
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	for(int i=0;i<m;i++){
		int u,v,w;
		scanf("%d %d %d",&u,&v,&w);
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		int c;
		scanf("%d",&c);
		for(int j=1;j<=n;j++){
			int a;
			scanf("%d",&a);
		}
	}
	dij();
	printf("%lld",ans);
	return 0;
}

