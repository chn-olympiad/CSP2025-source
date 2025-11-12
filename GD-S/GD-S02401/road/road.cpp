#include <cstdio>
#include <numeric>
#include <algorithm>
using namespace std;
using ll=long long;
const int N=1e4+20,M=1e6,K=10;
int n,m,k,pa[N+2],c[K+2],a[K+2][N+2];
inline char gc() {
	static char *l,*r,buf[1<<16];
	return l==r&&(r=(l=buf)+fread(buf,1,1<<16,stdin),l==r)?-1:*l++;
}
inline int read() {
	int x=0;
	char c=gc();
	for(; c<'0'||c>'9'; c=gc());
	for(; c>='0'&&c<='9'; c=gc()) x=x*10+c-'0';
	return x;
}
struct Edge {
	int u,v,w;
} g[M+2];
struct TEdge {
	int u,v,w,k;
} f[N+K*N+2];
int find(int u) { return pa[u]==u?u:pa[u]=find(pa[u]); }
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1; i<=m; ++i) g[i].u=read(),g[i].v=read(),g[i].w=read();
	for(int i=1; i<=k; ++i) {
		c[i]=read();
		for(int j=1; j<=n; ++j) a[i][j]=read();
	}
	sort(g+1,g+m+1,[](auto x,auto y) { return x.w<y.w; });
	iota(pa,pa+n+1,0);
	for(int i=1,j=0; i<=m; ++i)
		if(find(g[i].u)!=find(g[i].v)) {
			pa[find(g[i].u)]=find(g[i].v);
			f[++j]={g[i].u,g[i].v,g[i].w,0};
		}
	m=n-1;
	for(int i=1; i<=k; ++i)
		for(int j=1; j<=n; ++j)
			f[++m]={j,n+i,a[i][j],i};
	sort(f+1,f+m+1,[](auto x,auto y) { return x.w<y.w; });
	ll ans=1ll<<60;
	for(int i=0; i<1<<k; ++i) {
		iota(pa,pa+n+k+1,0);
		ll res=0;
		for(int j=0; j<k; ++j) if(i>>j&1) res+=c[j+1];
		for(int j=1; j<=m; ++j) {
			if((f[j].k&&(i>>f[j].k-1&1)==0)||find(f[j].u)==find(f[j].v)) continue;
			pa[find(f[j].u)]=find(f[j].v);
			res+=f[j].w;
		}
		ans=min(ans,res);
	}
	printf("%lld\n",ans);
	return 0;
}