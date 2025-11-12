#include<bits/stdc++.h>
#define mk make_pair
#define int long long
using namespace std;
bool M_1;
const int N=10050,M=1e6+100;
int n,m,k,c[15],a[11][N],f[N][1105],g[N][15],tmp[2050];
int tot=1,head[N];struct edge{int to,nex,w;}e[M<<1];
void Add(int u,int v,int w){e[++tot]={v,head[u],w};head[u]=tot;}
void Clear(){tot=1;for(int i=1;i<=n;i++)head[i]=0;}
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
int dis[N],vis[N],fa[N],val[N];
void Dij(int s,int n) {
	for(int i=1;i<=n;i++) dis[i]=1e18,vis[i]=0,fa[i]=0;
	dis[s]=0;q.push(mk(0,s));
	while(q.size()) {
		int u=q.top().second;q.pop();
		if(vis[u]) continue;vis[u]=1;
		for(int i=head[u];i;i=e[i].nex) {
			int v=e[i].to;
			if(dis[v]>dis[u]+e[i].w) {
				dis[v]=dis[u]+e[i].w;
				fa[v]=u;val[v]=e[i].w;
				q.push(mk(dis[v],v));
			}
		}
	}
	Clear();
	for(int i=2;i<=n;i++) {
		Add(fa[i],i,val[i]);
		Add(i,fa[i],val[i]);
	}
	return;
}
void DFS(int u,int fa) {
	for(int S=0;S<(1ll<<k);S++) {
		f[u][S]=0;
		for(int i=1;i<=k;i++) 
			if((S>>i-1)&1) f[u][S]+=a[i][u];
	}
	for(int i=1;i<=k;i++) g[u][i]=a[i][u];
	for(int i=head[u];i;i=e[i].nex) {
		int v=e[i].to;if(v==fa) continue;
		DFS(v,u);
		for(int t=1;t<=k;t++) for(int S=0;S<(1ll<<k);S++) 
			if((S>>t-1)&1) {
				f[u][S]=min(f[u][S],f[u][S-(1ll<<t-1)]+g[u][t]);
				f[v][S]=min(f[v][S],f[v][S-(1ll<<t-1)]+g[v][t]);
			}
		
		for(int S=0;S<(1ll<<k);S++) tmp[S]=1e18;
		for(int S=0;S<(1ll<<k);S++) 
			tmp[S]=min(tmp[S],f[v][S]+e[i].w+f[u][S]);
		
		for(int S=0;S<(1ll<<k);S++) for(int T=0;T<(1ll<<k);T++) 
			if((S&T)!=0) tmp[S|T]=min(tmp[S|T],f[u][S]+f[v][T]);
		
		for(int t=1;t<=k;t++) g[u][t]=min(g[u][t],g[v][t]);
		for(int S=0;S<(1ll<<k);S++) f[u][S]=tmp[S];
	}
}
bool M_2;
signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) {
		int u,v,w;cin>>u>>v>>w;
		Add(u,v,w);Add(v,u,w);
	}
	for(int i=1;i<=k;i++) {
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>a[i][j];
	}
	if(k==0) {
		Dij(1,n);int ans=0;
		for(int i=2;i<=n;i++) ans=ans+val[i];
		cout<<ans<<"\n";return 0;
	}
	int tag=0;
	for(int i=1;i<=k;i++) {
		tag=max(tag,c[i]);int op=1e18;
		for(int j=1;j<=n;j++) op=min(op,a[j][i]);
		tag=max(tag,op);
	}
	if(tag==0) {
		for(int i=1;i<=k;i++) for(int j=1;j<=n;j++) 
		Add(n+i,j,a[j][i]),Add(j,n+i,a[j][i]);int ans=0;
		Dij(1,n+k);for(int i=1;i<=n;i++) ans=ans+val[i];
		cout<<ans<<"\n";return 0;
	}
	Dij(1,n);DFS(1,1);int ans=1e18;
	for(int S=0;S<(1ll<<k);S++) {
		for(int i=1;i<=k;i++) if((S>>i-1)&1) f[1][S]+=c[i];
		ans=min(ans,f[1][S]);
	}
	cout<<ans<<"\n";
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
