#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
int n,m,t,u,v,w,fa[114514],cnt,b[114514],c[14][11451],ans,mn=1e18;
bool havea=true;
//int tot=1,head[2114514],next_[2114514],end_[2114514],val[2114514];
struct edge
{
	int s,e,v,t;
	bool operator<(const edge x)const
	{
		return v<x.v;
	}
}a[2114514];
/*
void add(int x,int y,int z)
{
	tot++;
	end_[tot]=y;
	val[tot]=z;
	next_[tot]=head[x];
	head[x]=tot;
}
*/
void init()
{
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
	}
}
int find(int x)
{
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
bool join(int z)
{
	int x=a[z].s,y=a[z].e;
	int fx=find(x),fy=find(y);
	if(fx!=fy)
	{
		fa[fy]=fx;
		return true;
	}
	else
	{
		return false;
	}
}
int kruskal(int x)
{
	//printf("%lld ",x);
	int res=0,y=0;
	init();
	for(int i=1;i<=cnt;i++)
	{
		if(a[i].t==0||(x&(1<<(a[i].t-1)))!=0)
		{
			if(join(i))
			{
				res+=a[i].v;
				y++;
				if(y==n-1)
				{
					break;
				}
				//printf("[%lld %lld %lld] ",a[i].s,a[i].e,a[i].v);
			}
		}
	}
	//printf("\n");
	return res;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&t);
	for(int i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&u,&v,&w);
		//add(u,v,w);
		//add(v,u,w);
		cnt++;
		a[cnt]={u,v,w,0};
	}
	for(int i=1;i<=t;i++)
	{
		scanf("%lld",b+i);
		for(int j=1;j<=n;j++)
		{
			scanf("%lld",c[i]+j);
			cnt++;
			a[cnt]={i,j,c[i][j],i};
		}
		//printf("%lld %lld\n",b[i],c[i][i]);
	}
	sort(a+1,a+1+cnt);
	for(int i=0;i<=(1<<t)-1;i++)
	{
		ans=0;
		for(int j=1;j<=t;j++)
		{
			if((i&(1<<(j-1)))!=0)
			{
				ans+=b[j]+c[j][j];
			}
		}
		mn=min(mn,ans+kruskal(i));
		//printf("%lld %lld\n",i,ans+kruskal(i));
	}
	printf("%lld\n",mn);
	return 0;
}
