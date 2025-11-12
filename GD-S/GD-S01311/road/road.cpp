#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int N=1e4+15;
int n,m,k,d[N],opp[N];
struct node{
	int v,w;
};
vector<node> G[N];
bool vis[N];
struct nodeq{
	int id,d;
	bool operator<(const nodeq &o)const{return d>o.d;}
};
void Dijkstra(int x){
	priority_queue<nodeq> q;
	memset(d,127,sizeof(d));
	d[x]=0;
	q.push((nodeq){x,d[x]});
	while(!q.empty()){
		int u=q.top().id;
		q.pop();
		vis[u]=1;
		for(int i=0;i<G[u].size();i++){
			int v=G[u][i].v,w=G[u][i].w;
			if(vis[v]) continue;
			if(d[v]>d[u]+w){
				d[v]=d[u]+w;
				opp[v]=i;
				q.push((nodeq){v,d[v]});
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
		G[u].push_back((node){v,w});
		G[v].push_back((node){u,w});
	}
	memset(opp,-1,sizeof(opp));
	Dijkstra(1);
	int ans=0;
	for(int i=1;i<=n;i++) if(opp[i]!=-1) ans+=G[i][opp[i]].w;
	cout<<ans;
	return 0;
}
