#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int n,m,k,ans=0;
struct edge{
	int u,w;
};
vector<edge>g[1005];
int c[15][1005];
int f[15];
struct node{
	int u,data;
};
int d[1005];
bool inque[1005];
bool vis[15];
bool visl[15][1005];
void bfs(int x){
	queue<node>q;
	q.push(node{x,0});
	memset(inque,false,sizeof(inque));
	memset(d,127,sizeof(d));
	memset(vis,false,sizeof(vis));
	memset(visl,false,sizeof(visl));
	inque[1]=true;
	d[1]=0;
	while(!q.empty()){
		node now=q.front();
		q.pop();
		inque[now.u]=false;
		for(int i=0;i<g[now.u].size();i++){
			int v=g[now.u][i].u;
			int w=g[now.u][i].w;
			if(!inque[v]&&d[now.u]+w<d[v]){
				
				q.push(node{v,d[v]});
			}
			if(!inque[v]){
				bool flag=false;
				if(d[now.u]+w<d[v]){
					d[v]=d[now.u]+w;
					flag=true;
				}
				for(int j=1;j<=k;j++){
					if(!vis[j]&&!visl[j][v]){
						if(d[now.u]+f[j]+c[j][v]<d[v]){
							d[v]=d[now.u]+f[j]+c[j][v];
							vis[j]=true;
							visl[j][v]=true;
							flag=true;
						}
					}
				}
				if(flag){
					q.push(node{v,d[v]});
					inque[v]=true;
				}
			}
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		g[u].push_back(edge{v,w});
		g[v].push_back(edge{u,w});
	}
	for(int i=1;i<=k;i++){
		cin>>f[i];
		for(int j=1;j<=n;j++){
			cin>>c[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		bfs(i);
		for(int j=1;j<=n;j++){
			if(d[j]==d[0])	continue;
			ans=max(ans,d[j]);
		}
	}
	cout<<ans;
	return 0;
}
//4 4 2
//1 4 6
//2 3 7
//4 2 5
//4 3 4
//1 1 8 2 4
//100 1 3 2 4


