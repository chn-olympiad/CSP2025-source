#include<iostream>
#include<vector>
using namespace std;
const int N=1e4+2;
int n,m,k;
int x,y,w;
struct node{
	int v,w;
};
vector<node> g[N];
int ans=0x3f3f3f3f;
bool vis[N];
void dfs(int u,int cnt,int w){
	bool flag=true;
	vis[u]=1;
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i].v;
		if(vis[v])continue;
		vis[v]=1;
		dfs(v,cnt+1,w+g[u][i].w);
		flag=false;
		vis[v]=0;
	}
	if(flag)ans=min(ans,w);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>x>>y>>w;
		g[x].push_back({y,w});
		g[y].push_back({x,w});
	}
	dfs(1,0,0);
	cout<<ans;
}
