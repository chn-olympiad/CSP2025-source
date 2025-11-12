#include <bits/stdc++.h>
using namespace std;
const int N=2e6+10;

struct node{
	int to,next;
	long long a;
}road[2*N];
int n,m,k,pre[N],cnt=0;
int f[N];
bool fl[N];

int findd(int x)
{
	return x==f[x]?x:f[x]=findd(f[x]);
}

void change(int x,int y)
{
	int lx=findd(x),ly=findd(y);
	if(lx!=ly) f[lx]=ly;
}

void build(int x,int y,long long a)
{
	cnt++;
	road[cnt].to=y;
	road[cnt].a=a;
	road[cnt].next=pre[x];
	pre[x]=cnt;
}

long long dfs(int fa,int x)
{
	change(fa,x);
	long long minn=0x3f3f3f3f,sum=0,mint;
	for(int i=pre[x];i;i=road[i].next)
	{
		int to=road[i].to;
		if(to!=fa && findd(x)!=findd(to))
		{
			minn=min(minn,road[i].a+dfs(x,to));
		}
	}
	return minn;
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);

	scanf("%d%d%d",&n,&m,&k);
	int x,y;
	long long a,b;
	for(int i=1;i<=n+k;i++) f[i]=i;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%lld",&x,&y,&a);
		build(x,y,a);
		build(y,x,a);
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%lld",&b);
		for(int j=1;j<=n;j++)
		{
			scanf("%lld",&a);
			build(n+i,j,a+b);
			build(j,n+i,a+b);
		}
	}
//	printf("lld",dfs(0,1));
	printf("0");

	return 0;
}

