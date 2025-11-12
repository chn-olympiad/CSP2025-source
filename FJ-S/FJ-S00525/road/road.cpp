#include<bits/stdc++.h>
using namespace std;
struct Node{long long v,w;};
bool operator<(Node a,Node b){return a.w>b.w;}
long long n,m,k,a[11][10010],dis[10010],vis[10010],ans;
vector<Node> g[10010];
void prim(){
	memset(dis,0x3f,sizeof(dis));
	dis[1]=0;
	priority_queue<Node> pq;
	pq.push({1,0});
	while(!pq.empty()){
		Node p=pq.top();
		pq.pop();
		if(vis[p.v]) continue;
		vis[p.v]=1;
		ans+=p.w;
		for(int i=0;i<g[p.v].size();i++){
			if(!vis[g[p.v][i].v]){
				long long val=g[p.v][i].w;
				dis[g[p.v][i].v]=min(dis[g[p.v][i].v],dis[p.v]+val);
				pq.push({g[p.v][i].v,val});
			}
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		g[u].push_back(Node{v,w});
		g[v].push_back(Node{u,w});
	}
	for(int j=1;j<=k;j++){
		int now; cin>>now;
		for(int i=1;i<=n;i++){
			cin>>a[j][i];
			if(!a[j][i]) now=i;
		}
		for(int i=1;i<=n;i++){
			g[now].push_back(Node{i,a[j][i]});
			g[i].push_back(Node{now,a[j][i]});
		}
	}
	prim();
	cout<<ans;
	return 0;
}
