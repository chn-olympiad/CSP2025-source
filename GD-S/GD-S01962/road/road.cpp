#include<bits/stdc++.h>
using namespace std;

const int N=2e5+10;
int n,m,k;
vector < pair<int,long long> >adj[N];
int vis[N],h[N],f[N];
long long dis[N],ans;

void init(){
	memset(dis,0x3f,sizeof(dis));
	memset(h,0,sizeof(h));
	memset(f,0,sizeof(f));
	memset(vis,0,sizeof(vis));
}

void dijsk(){
	priority_queue < pair<long long,pair<int,int>> > q;
	q.push( {0,{0,1}} );
	dis[1]=0;
	while(!q.empty()){
		int u=q.top().second.second;
		int p=q.top().second.first;
		q.pop(); 
		if(vis[u])continue;
		vis[u]=1;
		for(int i=0;i<adj[u].size();i++){
			int v=adj[u][i].first;
			long long w=adj[u][i].second;
			if(dis[v]==dis[u]+w && p>w){
				h[v]=u;
			}
			else if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				h[v]=u;
				q.push( {-1*dis[v],{w,v}} );
			}
		}
	}
}

void solve(int t){
	if(t==1)return ;
	if(f[t]) return ; 
	f[t]=1;
	ans+=dis[t]-dis[h[t]];
	solve(h[t]);
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k; 
	init();
	for(int i=1;i<=m;i++){
		int u,v;
		long long w;
		cin>>u>>v>>w;
		adj[u].push_back( {v,w} );
		adj[v].push_back( {u,w} );
	}
	int len=n;
	for(int i=1;i<=k;i++){
		len++;
		long long x;cin>>x;
		for(int j=1;j<=n;j++){
			long long y;cin>>y;
			adj[len].push_back( {j,y} );
			adj[j].push_back( {len,y} );
		}
	} 
	dijsk();
	for(int i=2;i<=n;i++){
		solve(i);
	}
	cout<<ans;
	return 0;
}
