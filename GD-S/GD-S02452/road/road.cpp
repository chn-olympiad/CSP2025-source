#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e4+10;
const int MAXM=1e6+10;
typedef long long ll;
struct edges{
	int u,v;
	ll w;
}e[MAXM<<1];
int n,m,k;
ll a[11][MAXN];
bool cmp(edges a,edges b)
{
	return a.w<b.w;
}
int fa[MAXN];
int Find(int x)
{
	if(fa[x]==x) return x;
	else return fa[x]=Find(fa[x]);
}
bool merge(int x,int y)
{
	int aa=Find(x),bb=Find(y);
	if(aa!=bb)
	{
		fa[bb]=aa;
		return true;
	}
	return false;
}
ll ans[MAXN];
int Kruskal()
{
	int num=0;
	ll res=0;
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		int u=e[i].u;
		int v=e[i].v;
		if(merge(u,v))
		{
			num++;
			res+=e[i].w;
			if(num==n-1) return res;
		}
	}
	return -1;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
	}
	for(int i=1,u,v,w;i<=m;i++)
	{
		scanf("%d %d %d",&u,&v,&w);
		e[i]={u,v,w};
	}
	int x;
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&x);
		for(int j=1;j<=n;j++)
		{
			scanf("%lld",&a[i][j]);
		}
	}
	if(k==0)
	{
		printf("%d\n",Kruskal());
	}
	return 0;
}
