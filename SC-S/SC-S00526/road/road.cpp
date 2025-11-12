#include<bits/stdc++.h>
using namespace std;
#define ll long long

const ll N=10000,K=10,INF=1e18;

int n,m,k;
struct edge {int to,w;};
vector<edge> g[N+K+1];
int c[K+1];
bool ins[N+K+1];
int vis[N+K+1],T=0;
ll ans=INF;
ll check(int state){
	for(int i=0;i<k;i++) ins[n+i+1]=(state>>i)&1;
	ll res=0;
	for(int i=1;i<=k;i++) if(ins[n+i]) res+=c[i];
	priority_queue<pair<int,int>> qu;
	qu.push(make_pair(0,1));
	while(!qu.empty()){
		pair<int,int> x=qu.top();
		qu.pop();
		if(vis[x.second]==T) continue;
		res-=x.first,vis[x.second]=T;
		for(auto i: g[x.second])
			if(vis[i.to]!=T&&ins[i.to])
				qu.push(make_pair(-i.w,i.to));
	}
	return res;
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL),cout.tie(NULL);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;cin>>u>>v>>w;
		g[u].push_back(edge{v,w});
		g[v].push_back(edge{u,w});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			int t;cin>>t;
			g[n+i].push_back(edge{j,t});
			g[j].push_back(edge{n+i,t});
		}
	}
	for(int i=1;i<=n;i++) ins[i]=1;
	for(int i=(1<<k)-1;i>=0;i--)
		T++,ans=min(ans,check(i));
	cout<<ans<<endl;
	return 0;
}