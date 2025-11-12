#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int N=10015;
struct Edge{
	int u,v,w;
}e[N*110];
bool cmp(const Edge &x,const Edge &y)
{
	return x.w<y.w;
}
ll ans,S;
int r[1025][N],g[11][N],fa[N],sz[N],p[N*11],n,m,k,it[15],c[15];
bitset<N*100>is;
inline void init()
{
	for(int i=1;i<=n+k;++i)
		fa[i]=i,sz[i]=1;
}
inline int Find(const int x)
{
	return fa[x]==x?x:fa[x]=Find(fa[x]);
}
inline bool Unite(int u,int v)
{
	u=Find(u),v=Find(v);
	if(u==v)
		return 0;
	if(sz[u]<sz[v])
		swap(u,v);
	fa[v]=u,sz[u]+=sz[v];
	return 1;
}
void solve(const int t)
{
	init(),S=0;
	int u=0;
	for(int i=k;i>=1;--i)
		if((t>>i-1)&1)
			S+=c[i],u=i;
	int pre=t-(1<<u-1);
	for(int i=1;i<n+k;++i)
		p[i]=r[pre][i];
	for(int i=1;i<=n;++i)
		p[i+n+k-1]=g[u][i];
	inplace_merge(p+1,p+n+k,p+n+n+k);
	u=0;
	for(int i=1;i<n+k+n;++i)
		if(p[i]<=m&&Unite(e[p[i]].u,e[p[i]].v))
			S+=e[p[i]].w,r[t][++u]=p[i];
	ans=min(ans,S);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i)
		cin>>e[i].u>>e[i].v>>e[i].w;
	sort(e+1,e+1+m,cmp);
	S=0,init();
	for(int i=1;i<=m;++i)
		if(Unite(e[i].u,e[i].v))
			is[i]=1,S+=e[i].w;
	ans=S;
	int u=0;
	for(int i=1;i<=m;++i)
		if(is[i])
			e[++u]=e[i];
	m=u;
	for(int i=1;i<=k;++i)
	{
		cin>>c[i];
		for(int j=1;j<=n;++j)
			++m,cin>>e[m].w,e[m].u=j,e[m].v=i+n;
	}
	sort(e+1,e+1+m,cmp);
	u=0;
	memset(r,0x1f,sizeof r);
	for(int i=1;i<=m;++i)
		if(e[i].v<=n)
			r[0][++u]=i;
		else
			g[e[i].v-n][++it[e[i].v-n]]=i;
	e[0].w=1000000005;
	for(int t=1;t<(1<<k);++t)
		solve(t);
	cout<<ans;
	return 0;
}
