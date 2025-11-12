#include <cstdio>
#include <algorithm>

typedef long long ll;

const int N=1e4+10;
const int M=1e6+10;
const int K=15;

struct edge {
	int u,v;
	ll w;
}G[M];

int n,m,k;
ll a[K][N];
int vis[N][N];

int fa[N];

int f(int x) {
	if(fa[x]==x) return x;
	return fa[x]=f(fa[x]);
}

int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++) scanf("%d%d%lld",&G[i].u,&G[i].v,&G[i].w);
	for(int i=1;i<=m;i++) vis[G[i].u][G[i].v]=vis[G[i].v][G[i].u]=i;
	for(int i=1;i<=k;i++) for(int j=0;j<=n;j++) scanf("%lld",&a[i][j]);
	for(int j=1;j<=k;j++) {
		for(int u=1;u<=n;u++) {
			for(int v=1;v<=n;v++) {
				if(vis[u][v]) {
					int id=vis[u][v];
					G[id].w=std::min(G[id].w,a[j][u]+a[j][v]);
				} else {
					G[++m]={u,v,a[j][u]+a[j][v]};
					vis[u][v]=vis[v][u]=m;
				}
			}
		}
	}
	std::sort(G+1,G+1+m,[](edge a,edge b) {
		return a.w<b.w;
	});
	ll ans=0;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++) {
		int u=G[i].u,v=G[i].v,w=G[i].w;
		int fx=f(u),fy=f(v);
		if(fx==fy) continue;
		ans+=w;fa[fx]=fy;
	}
	printf("%lld\n",ans);
	return 0;
}
