#include<bits/stdc++.h>
using namespace std;
const long long N=2e4+7,M=2e6+7,T=11;
long long cnt;
struct node
{
	long long u,v,w;
}g[M];
long long f[N];
long long n,m,k;
long long c[T],a[T][N];
bool cmp(node xx,node yy)
{
	return xx.w<yy.w;
}
long long find(long long x)
{
	if(f[x]==x)
	return x;
	return f[x]=find(f[x]);
}
long long mn=1e18+7;
long long bz[T];
void solve(long long x)
{
	long long res=0;
	for(long long i=1;i<=k;i++)
	{
		if(bz[i]==1)
		res+=c[i];
	}
	for(long long i=1;i<=n+k;i++)
	f[i]=i;
	long long op=0;
	for(int i=1;i<=cnt;i++)
	{//cout<<"kfdkd";
		long long u=g[i].u,v=g[i].v,w=g[i].w;
		long long xx=find(u),yy=find(v);
		if(u<=n&&v<=n)
		{
			if(xx!=yy)
			{
				f[xx]=yy;
				cnt++;
				res+=w;
			}
		}
		else if(bz[v-n])
		{
			if(xx!=yy)
			{
				f[xx]=yy;
				cnt++;
				res+=w;
			}
		}
		if(res>mn)
		break;
		if(cnt==n+x-1)
		{
			break;
		}
		
	}
	mn=min(mn,res);
}
int pp;
void dfs(long long x,long long y)
{
	if(x==k+1)
	{
		pp++;
		solve(y);
		return ;
	}
	bz[x]=1;
	dfs(x+1,y+1);
	bz[x]=0;
	dfs(x+1,y);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(long long i=1;i<=m;i++)
	{
		++cnt;
		scanf("%lld%lld%lld",&g[cnt].u,&g[cnt].v,&g[cnt].w);
	}
	long long sum=0;
	for(long long i=1;i<=k;i++)
	{
		scanf("%lld",&c[i]);
		sum+=c[i];
		for(long long j=1;j<=n;j++)
		{
			scanf("%lld",&a[i][j]);
			g[++cnt]={j,n+i,a[i][j]};
			sum+=a[i][j];
		}
	}
//	cout<<cnt<<' ';
	if(sum==0)
	{
		cout<<0;
		return 0;
	}
	sort(g+1,g+cnt+1,cmp);
	dfs(1,0);
	printf("%lld",mn);
	return 0;
}


