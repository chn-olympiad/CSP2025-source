#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n,m,k,N,c[11],fa[10011];
long long ans=1000000000000000000;
struct edge {
	int u,v,w;
}e0[1100001],e1[11][10001],e[1100001];
inline bool cmp(edge x,edge y) {
	return x.w<y.w;
}
int fnd(int x) {
	if(x==fa[x]) return x;
	return fa[x]=fnd(fa[x]);
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	N=n+k;
	for(int i=1;i<=m;++i) scanf("%d%d%d",&e0[i].u,&e0[i].v,&e0[i].w);
	for(int i=1,I=n+1;i<=k;++i,++I) {
		scanf("%d",&c[i]);
		for(int j=1;j<=n;++j) {
			e1[i][j].u=I;
			e1[i][j].v=j;
			scanf("%d",&e1[i][j].w);
		}
	}
	for(int s=(1<<k)-1;s>=0;--s) {
		int cnt=0;
		long long sum=0;
		for(int i=1;i<=N;++i) fa[i]=i;
		for(int i=1;i<=m;++i) e[++cnt]=e0[i];
		for(int i=1;i<=k;++i)
			if(s>>i-1&1) {
				sum+=c[i];
				for(int j=1;j<=n;++j) e[++cnt]=e1[i][j];
			}
		sort(e+1,e+cnt+1,cmp);
		for(int i=1;i<=cnt;++i) {
			int u=fnd(e[i].u),v=fnd(e[i].v);
			if(u==v) continue;
			fa[u]=v;
			sum+=e[i].w;
		}
		ans=min(ans,sum);
	}
	printf("%lld",ans);
	return 0;
}
