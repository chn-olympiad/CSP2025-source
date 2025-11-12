#include<bits/stdc++.h>
using namespace std;
long long n,m,k,a[15][10005],c[15],fa[10005],ans=0;
bool f[15];
struct ea{
	long long from,to,w,xiancun=0;
}eage[1500010];
bool cmp(ea x,ea y)
{
	return x.w<=y.w;
}
long long ff(long long x)
{
	if(fa[x]==x)
		return x;
	else
		return fa[x]=ff(fa[x]);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		long long u,v,w;
		scanf("%lld%lld%lld",&u,&v,&w);
		eage[i].from=u;
		eage[i].to=v;
		eage[i].w=w;
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++)
			scanf("%lld",&a[i][j]);
	}
	int tot=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			int minn=INT_MAX,cc=0;
			for(int l=1;l<=k;l++)
			{
				if(a[l][j]+a[l][i]+c[l]<minn)
				{
					minn=a[l][i]+a[l][j]+c[l];
					cc=l;
				}
			}
			tot++;
			eage[m+tot].from=i;
			eage[m+tot].to=j;
			eage[m+tot].w=minn;
			eage[m+tot].xiancun=cc;
		}
	}
	sort(eage+1,eage+m+tot+1,cmp);
	for(long long i=1;i<=n;i++)	
		fa[i]=i;
	for(int i=1;i<=m+tot;i++)
	{
		long long u=eage[i].to,v=eage[i].from,w=eage[i].w;
		if(ff(fa[u])==ff(fa[v]))
			continue;
		if(eage[i].xiancun!=0)
		{
			if(f[eage[i].xiancun])
				w-=c[eage[i].xiancun];
			else
				f[eage[i].xiancun]=1;
		}
		ans+=w;
		fa[ff(u)]=ff(v);
	}
	printf("%lld",ans);
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
