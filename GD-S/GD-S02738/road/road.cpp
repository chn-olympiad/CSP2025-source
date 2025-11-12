#include <bits/stdc++.h>
#define ll long long
using namespace std; int read() {int x=0, f=1; char c=getchar();
while(c<48 || c>57) f=c=='-'?-1:1, c=getchar(); while(c>47 && c<58)
x=(x<<1)+(x<<3)+c-48, c=getchar(); return x*f;} void write(ll x)
{ll st[41], tp=0; if(x<0) putchar('-'), x=-x; do st[tp++]=x%10,
x/=10; while(x); while(tp) putchar(st[--tp]+48);} ll n,m,k,c[11],
a[11][10001],fa[10001],bz[11]={1},x=1,y,cnt,res,ans=1e18; struct edge
{ll u,v,w,t;} e[6000001]; bool cmp(edge x, edge y) {return x.w<y.w;}
int find(int x) {if(fa[x]!=x) fa[x]=find(fa[x]); return fa[x];}

void dfs(int x)
{
	if(x>k)
	{
		for(int i=1; i<=n; ++i) fa[i]=i; cnt=0; res=0;
		
		for(int i=1; i<=m; ++i)
		{
			if(!bz[e[i].t]) continue; x=find(e[i].u);
			y=find(e[i].v); if(x!=y) {fa[x]=y; res+=e[i].w+
			c[e[i].t]; if(++cnt==n-1 || res>=ans) break;}
		}

		if(cnt==n-1) ans=min(ans,res); return;
	}
	
	dfs(x+1); bz[x]=1; dfs(x+1); bz[x]=0;
}

int main()
{
	freopen("road.in","r",stdin); freopen("road.out","w",stdout);
	n=read(); m=read(); k=read(); for(int i=1; i<=m; ++i)
	e[i]={read(),read(),read()}; for(int i=1; i<=k; ++i)
	{c[i]=read(); x=c[i]?0:x; for(int j=1; j<=n; ++j) a[i][j]=read();}
	if(x) {for(int i=2; i<=n; ++i) {for(int j=1; j<i; ++j)
	{e[++m]={j,i,(ll)1e18}; for(int x=1; x<=k; ++x) e[m].w=
	min(e[m].w,a[x][i]+a[x][j]);}}} else {for(int i=1; i<=k; ++i)
	{for(int j=1; j<=n; ++j) {for(int x=1; x<j; ++x)
	e[++m]={x,j,a[i][x]+a[i][j],i};}}} sort(e+1,e+m+1,cmp); if(x)
	{ans=0; for(int i=1; i<=n; ++i) fa[i]=i; for(int i=1; i<=m; ++i)
	{x=find(e[i].u); y=find(e[i].v); if(x!=y) {fa[x]=y; ans+=e[i].w;
	if(++cnt==n-1) break;}}} else dfs(1); write(ans); return 0;
}
