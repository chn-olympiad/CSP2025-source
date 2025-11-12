#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10,inf=0x3f3f3f3f;
struct edge{
	int v,w;
	bool operator >(const edge e){
		return w<e.w;
	}
};
vector<edge> e[maxn];
int c[maxn],vis[maxn],dis[maxn],n,m,k;
void dijkstra(int s){
	priority_queue<int> q;
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[s]=0;
	vis[s]=1;
	q.push(s);
	while(!q.empty()){
		int u=q.top();
		q.pop();
		for(edge e:e[u]){
			int v=e.v,w=e.w;
			if(vis[v])continue;
			if(v<=n&&dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				q.push(v);
			}
			if(v>n&&dis[v]>dis[u]+w+c[v-n]){
				dis[v]=dis[u]+w+c[v-n];
				q.push(v);
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		int x;
		for(int j=1;j<=n;j++){
			cin>>x;
			e[n+i].push_back({j,x});
			e[j].push_back({n+i,x});
		}
	}
	dijkstra(1);
	int x=-1e9; 
	for(int i=1;i<=n;i++){
		x=max(dis[i],x);
	}
	cout<<x;
}
