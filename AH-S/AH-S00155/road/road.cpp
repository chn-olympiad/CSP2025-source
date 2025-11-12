#include<bits/stdc++.h>
#define N 1005
using namespace std;
int n,m,k;
int u,v,cost,len;
int c[N],a,dis[N],vis[N];
struct edge{
	int nxt,w;
};
struct node{
	int id,d;
	bool operator >(const node &b) const {
		return d>b.d;
	}
};
vector<edge> g[N];
priority_queue<node,vector<node>,greater<node> > q;
void prim(int st){
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	q.push({st,0});
	vis[st]=1;
	dis[st]=0;
	while(!q.empty()){
		node u=q.top(); q.pop();
		if(vis[u.id]) continue;
		vis[u.id]=1;
		for(int i=0;i<g[u.id].size();i++){
			edge x=g[u.id][i];
			if(dis[x.nxt]>u.d+x.w){
				dis[x.nxt]=u.d+x.w;
				len+=x.w;
				q.push(node{x.nxt,dis[x.nxt]});
			}
		}
	}
	return ;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>cost;
		g[u].push_back({v,cost});
		g[v].push_back({u,cost});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		g[i].push_back({i+n,c[i]});
		g[i+n].push_back({i,c[i]});
		for(int j=1;j<=n;j++){
			cin>>a;
			g[i+n].push_back({j+n,a}),g[j+n].push_back({i+n,a});
		}
	}
	prim(1);
	for(int i=1;i<=n;i++) cout<<dis[i]<<" ";
	cout<<endl;
	cout<<len;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
