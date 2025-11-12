#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,f[10005],si[10005];
struct t2
{
	int u,v,w;
}e[10005];
bool cmp(t2 a,t2 b)
{
	return a.w<b.w;
}
void ds()
{
	for(int i=1;i<=n;i++)f[i]=i;
}
int fi(int u)
{
	return (f[u]==u?u:fi(f[u]));
}
bool tg(int a,int b)
{
	return fi(a)==fi(b);
}
void hb(int a,int b)
{
	f[fi(a)]=f[fi(b)];
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int l=0;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		e[++l].u=u;
		e[l].v=v;
		e[l].w=w;
	}
	ds();
	for(int i=1+n;i<=k+n;i++)
	{
		int gz;
		cin>>gz;
		for(int j=1;j<=n;j++)
		{
			int w;
			cin>>w;
			if(j>1)hb(j,j-1);
		}
	}
	sort(e+1,e+l+1,cmp);
	int ans=0;
	for(int i=1;i<=l;i++)
	{
		int p=e[i].u;
		int q=e[i].v;
		int r=e[i].w;
		if(!tg(p,q))
		{
			hb(p,q);
			ans+=r;
		}
	}
	cout<<ans;
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
