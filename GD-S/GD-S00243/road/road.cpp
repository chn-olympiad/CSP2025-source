#include<bits/stdc++.h>
using namespace std;
const long long M=2500000+5;
const long long N=10000+15;
long long n,m,k;
struct edge{
	long long nxt;
	long long zhi;
	long long to;
}e[M];
long long head[N],vis[N],cnt,c[15],a[15][N],ans=2e9;
void add(long long tu,long long tv,long long ts)
{
	e[++cnt].to=tv;
	e[cnt].zhi=ts;
	e[cnt].nxt=head[tu];
	head[tu]=cnt;
}
void dfs(long long x,long long sum,long long num)
{
	if(num==n)
	{
		ans=min(ans,sum);
		return ; 
	}
	for(long long i=head[x];i;i=e[i].nxt)
	{
		if(vis[e[i].to])
		{
			continue;
		}
		vis[e[i].to]=1;
		if(e[i].to>n)
		{
			dfs(e[i].to,sum+e[i].zhi+c[e[i].to-n],num);
		}
		else
		{
			dfs(e[i].to,sum+e[i].zhi,num+1);
		}
		vis[e[i].to]=0;
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(long long i=1;i<=m;i++)
	{
		long long tu,tv,ts;
		cin>>tu>>tv>>ts;
		add(tu,tv,ts);
		add(tv,tu,ts);
	}
	for(long long i=1;i<=k;i++)
	{
		cin>>c[i];
		for(long long j=1;j<=n;j++)
		{
			cin>>a[i][j];
			add(i+n,j,a[i][j]);
			add(j,i+n,a[i][j]);
		}
	}
	vis[1]=1;
	dfs(1,0,1);
	cout<<ans;
	return 0;
}
