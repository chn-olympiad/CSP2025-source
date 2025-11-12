#include<bits/stdc++.h>
using namespace std;
const long long MAXN=1010000,MAXP=20101;
struct edg
{
	long long u,v,val;
};
bool cmp(edg ta,edg tb)
{
	return ta.val<tb.val;
}
long long n,c[MAXP],m,k,fa[MAXP],M,ans;
edg redg[MAXN],nedg[12][MAXP],kedg[12][MAXP],sedg[MAXN];
long long find(long long x)
{
	while(x!=fa[x])
	{
		fa[x]=fa[fa[x]];
		x=fa[x];
	}
	return x;
}
void merge(long long x,long long y)
{
	x=find(x);
	y=find(y);
	fa[x]=y;
	return;
}
void init()
{
	long long i;
	for(i=1;i<=n+10;i++)
	{
		fa[i]=i;
	}
	return;
}
long long calc(long long x,long long d)
{
	long long i,t=0;
	for(i=1;i<=n-1+d;i++)
	{
		t+=nedg[x][i].val;
	}
	return t;
}
void dfs(long long x,long long lst,long long cost,long long d)
{
	if(x==k+1)
	{
		ans=min(ans,calc(lst,d)+cost);
		return;
	}
	dfs(x+1,lst,cost,d);
	long long ta,tb,tc,i;
	ta=1;
	tb=1;
	tc=0;
	init();
	for(tc=1;(tb<=n)||(ta<=n-1+d);tc++)
	{
		if(tb==n+1)
		{
			sedg[tc]=nedg[lst][ta];
			ta++;
		}
		else if(ta==n+d)
		{
			sedg[tc]=kedg[x][tb];
			tb++;
		}
		else
		{
			if(nedg[lst][ta].val<kedg[x][tb].val)
			{
				sedg[tc]=nedg[lst][ta];
				ta++;
			}
			else
			{
				sedg[tc]=kedg[x][tb];
				tb++;
			}
		}
	}
	M=0;
	d++;
	for(i=1;i<=tc&&M<n-1+d;i++)
	{
		if(find(sedg[i].u)!=find(sedg[i].v))
		{
			merge(sedg[i].u,sedg[i].v);
			M++;
			nedg[x][M]=sedg[i];
		}
	}
	dfs(x+1,x,cost+c[x],d);
	return;
}
void read(long long &x)
{
	x=0;
	char c=getchar();
	while(!((c>='0')&&(c<='9')))
	{
		c=getchar();
	}
	while((c>='0')&&(c<='9'))
	{
		x=x*10+c-48;
		c=getchar();
	}
	return;
}
void work()
{
	M=ans=0;
	long long i,j,ta,tb,tc;
//	scanf("%lld%lld%lld",&n,&m,&k);
	read(n),read(m),read(k);
	for(i=1;i<=m;i++)
	{
//		scanf("%lld%lld%lld",&ta,&tb,&tc);
		read(ta),read(tb),read(tc);
		redg[i]=edg{ta,tb,tc};
	}
	sort(redg+1,redg+1+m,cmp);
	for(i=1;i<=k;i++)
	{
//		scanf("%lld",&c[i]);
		read(c[i]);
		for(j=1;j<=n;j++)
		{
//			scanf("%lld",&tc);
			read(tc);
			kedg[i][j]=edg{n+i,j,tc};
		}
		sort(kedg[i]+1,kedg[i]+1+n,cmp);
	}
	for(i=1;i<=n;i++)
	{
		fa[i]=i;
	}
	M=0;
	for(i=1;i<=m&&M<n-1;i++)
	{
		if(find(redg[i].u)!=find(redg[i].v))
		{
			merge(redg[i].u,redg[i].v);
			M++;
			nedg[0][M]=redg[i];
			ans+=redg[i].val;
		}
	}
	dfs(1,0,0,0);
	printf("%lld\n",ans);
	return;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
//	long long T;
//	scanf("%lld",&T);
//	while(T--)
//	{
		work();
//	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
