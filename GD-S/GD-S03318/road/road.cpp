#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,m,k,fa[N],sum=0,ls,point=0,point2=0;
struct node
{
	int u,v,w,vprice=0;
	bool operator <(const node &t)const
	{
		return w+(!vprice?0:vprice)<t.w+(!t.vprice?0:t.vprice);
	}
}e[N];

inline int find(int x)
{
	if(x==fa[x])
	{
		return x;
	}
	return fa[x]=find(fa[x]);
}
inline void rkruskal()
{
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
	}
	sort(e+1,e+m+1);
	for(int i=1;i<=m;i++)
	{
		int nx=find(e[i].u),ny=find(e[i].v);
		if(nx!=ny)
		{
			fa[nx]=ny;
			sum+=e[i].w;
		}
	}
}

inline void kruskal()
{
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
	}
	sort(e+1,e+point+1);
	for(int i=1;i<=point;i++)
	{
		int nx=find(e[i].u),ny=find(e[i].v);
		if(nx!=ny)
		{
			fa[nx]=ny;
			sum+=e[i].w;
			if(e[i].vprice)
			{
				sum+=e[i].vprice;
				e[i].vprice=0;
			}
		}
	}
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	if(k)
	{
		for(int i=1;i<=m;i++)
		{
			point++;
			scanf("%d%d%d",&e[point].u,&e[point].v,&e[point].w);
		}
		for(int i=1;i<=k;i++)
		{
			scanf("%d",&ls);
			point2++;
			for(int j=1;j<=n;j++)
			{
				point++;
				e[point].u=n+point2;
				e[point].v=j;
				scanf("%d",&e[point].w);
				e[point].vprice=ls;
			}
		}
		kruskal();
		printf("%d",sum);
	}
	else
	{
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
		}
		rkruskal();
		printf("%d",sum);
	}
	return 0;
}
