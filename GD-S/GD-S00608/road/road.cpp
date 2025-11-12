#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=1e4+20,M=1e6+10;
LL n,m,k,f[N],c[N],tot;
struct edge { LL u,v,w; }e[M],g[M];
bool cmp(edge a,edge b) { return a.w<b.w; }
LL find(LL u) { return f[u]==u?u:f[u]=find(f[u]); }
bool mango(LL u,LL v)
{
	u=find(u),v=find(v);
	if(u==v) return 0;
	f[u]=v; return 1;
}
void cgly()
{
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++)
		if(mango(e[i].u,e[i].v))
			g[++tot]=e[i];
}
LL ans=1e18;
void MST(LL s)
{
	for(int i=1;i<=n+k;i++) f[i]=i;
	LL res=0;
	for(int i=1;i<=k;i++) if(s>>(i-1)&1) res+=c[i];
	for(int i=1;i<=tot;i++)
		if(g[i].u<=n||(s>>(g[i].u-n-1)&1))
			if(mango(g[i].u,g[i].v))
				res+=g[i].w;
	ans=min(ans,res);
}
void solve()
{
	sort(g+1,g+tot+1,cmp);
	for(int s=0;s<(1<<k);s++) MST(s);
	printf("%lld",ans);
}
void read(LL &x)
{
	x=0; char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while('0'<=c&&c<='9') x=x*10+c-'0',c=getchar();
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n),read(m),read(k);
	for(int i=1;i<=m;i++)
	{
		LL u,v,w; read(u),read(v),read(w);
		e[i]={u,v,w};
	}
	for(int i=1;i<=k;i++)
	{
		read(c[i]); LL val;
		for(int j=1;j<=n;j++) read(val),g[++tot]={i+n,j,val};
	}
	cgly();
	solve();
	return 0;
}
