#include <bits/stdc++.h>
using namespace std;
const int N=1e3+30;
const int INF=0x3f3f3f3f;
struct node{
	int v,w;
};
int n,m,k,vis[1030],dis[1030];
vector<node> G[1030];
long long sum=0;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
void dfs(int x){
	q.push({0,x});
	dis[x]=0;
	int nn=n+k;
	while(nn){
		int u=q.top().second;
		q.pop();
		if(vis[u]){
			continue;
		}
		nn--;
		vis[u]=1;
		sum+=dis[u];
		for(int i=1;i<int(G[u].size());i++){
			int v=G[u][i].v,w=G[u][i].w;
			if(vis[v]) continue;
			if(dis[v]<=w)continue;
			dis[v]=w;
			q.push({dis[v],v});
		}
	}
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	memset(dis,INF,sizeof(dis));
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		G[u].push_back({v,w});
		G[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		int b;
		scanf("%d",&b);
		for(int j=1;j<=n;j++){
			int v=j,w;
			int u=n+i;
			scanf("%d",&w);
			G[u].push_back({v,w});
			G[v].push_back({u,w});
		}
	}
	dfs(1);
	printf("%lld",sum);
} 
