#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
const int M=1e6+5,N=1e4+5,K=15;
struct node{
	int u,v,w;
//	bool operator <(const node &x)const {
//		return x.w<w;
//	}
};
struct edge{
	int v,w;
	bool operator <(const edge &x)const {
		return x.v<v;
	}
};
vector<edge>g[N];
//queue<edge>q;
node d[M];
int c[K],a[K][N];
bool vis[N];
int dis[N];
priority_queue<edge>q;
void bfs(int fa,int u,int l){
	vis[u]=1;
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i].v;
		if(v==fa)continue;
		q.push(g[u][i]);
	}
//	while(!q.empty()){
//		edge k=q.top();
//		
//		q.pop();
//		if(vis[k.v]==1){
//			
//		}
//	}
	return ;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&d[i].u,&d[i].v,&d[i].w);
		int u=d[i].u,v=d[i].v,w=d[i].w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
			g[i+n].push_back({j,a[i][j]});
			g[j].push_back({i+n,a[i][j]});
		}
	}
	bfs(1,1,0);
	cout<<m; 
	return 0;
}
