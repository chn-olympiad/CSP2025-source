#include <bits/stdc++.h>
using namespace std;
#define fr first
#define sc second
typedef long long LL;
const int N=1e4+20,T=10,M=1e6+10;
const LL INF=1e18;
int n,m,t,ln,pi[2*T];
int a[T][N],fa[N],siz[N];
LL ans=INF;
int get(int x)
{
	return fa[x]==x?x:fa[x]=get(fa[x]);
}
void merge(int x,int y)
{
	if (siz[x]<siz[y]) swap(x,y);
	fa[y]=x;
	siz[x]+=siz[y];
}
struct edge
{
	int u,v,w;
	bool operator<(const edge &x)const
	{
		return w<x.w;
	}
}e[M],b[T][N],tr[N],tmp[M];
typedef pair<edge,int> PEI;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>t;
	for (int i=1;i<=m;i++)
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
	sort(e+1,e+m+1);
	for (int i=0;i<t;i++)
	{
		scanf("%d",a[i]+0);
		for (int j=1;j<=n;j++)
		{
			scanf("%d",a[i]+j);
			b[i][j]=(edge){n+1+i,j,a[i][j]};
		}
		sort(b[i]+1,b[i]+n+1);
	}
	iota(fa+1,fa+n+1,1);
	fill(siz+1,siz+n+1,1);
	for (int i=1;i<=m;i++)
	{
		int u=e[i].u,v=e[i].v;
		u=get(u),v=get(v);
		if (u==v) continue;
		merge(u,v);
		tr[++ln]=e[i];
	}
	for (int s=0;s<1<<t;s++)
	{
		iota(fa+1,fa+n+t+1,1);
		fill(siz+1,siz+n+t+1,1);
		copy(tr+1,tr+n,e+1);
		ln=n-1;
		LL res=0;
		for (int i=0;i<t;i++)
			if (s>>i&1)
			{
				res+=a[i][0];
				for (int j=1;j<=n;j++)
					e[++ln]=b[i][j];
			}
		sort(e+1,e+ln+1);
		for (int i=1;i<=ln;i++)
		{
			int u=e[i].u,v=e[i].v,w=e[i].w;
			u=get(u),v=get(v);
			if (u==v) continue;
			merge(u,v);
			res+=w;
		}
		ans=min(ans,res);
	}
	cout<<ans;
	return 0;
}
