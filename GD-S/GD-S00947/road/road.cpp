#include <bits/stdc++.h>
using namespace std;
const int N=1e4+10;
const int inf=0x3f3f3f3f;
struct edge{
	int v,w;
};
vector<edge> g[N];
int vis[N],dep[N],fa[N];
int dis[N][N];
int n,m,k;
int tot=0;
void dfs(int pos){
	int find=0;
	vis[pos]=1;
	for(int i=0;i<g[pos].size();i++){
		int next=g[pos][i].v;
		if(g[pos][i].w+dep[pos]<dep[next]){
			dep[next]=dep[pos]+g[pos][i].w;
			fa[next]=fa[i];
		}
		if(!vis[next]&&dep[next]<dep[find])find=next;
	}
	dfs(find);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	memset(dep,inf,sizeof inf);
	for(int i=1;i<=n;i++){
		int u,v,w;
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
		dis[u][v]=dis[v][u]=w;
		tot+=w;
	}
	dfs(1);
	//for(int i=1;i<=n;i++)
	for(int i=1;i<=n;i++){
		if(fa[i])tot+=dis[i][fa[i]];
	}
	if(k==0){
		cout<<tot<<endl;
		return 0;
	}
	return 0;
}
