#include <iostream>
#include <algorithm>
using namespace std;
const int N=1e4+20,M=1e6+5;
int n,m,k;
long long c[15],a[15][N],ans=0x3f3f3f3f3f3f3f3f;
struct node
{
	int u,v;
	long long w; 
}e[M],g[15][N],cs[M];
bool cmp(node x,node y)
{
	return x.w<y.w;
}
int dad[N];
int getfather(int x)
{
	if(dad[x]==x)return x;
	dad[x]=getfather(dad[x]);
	return dad[x];
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)cin>>e[i].u>>e[i].v>>e[i].w;
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=n;i++)dad[i]=i;
	int cnt=0,n_=0;
	for(int i=1;i<=m;i++)
	{
		int u=getfather(e[i].u);
		int v=getfather(e[i].v);
		if(u^v)
		{
			dad[u]=v;
			cnt++;
			e[++n_]=e[i];
		}
		if(cnt==n-1)break;
	}
	m=n_;
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)cin>>a[i][j];
	}
	for(int i=1;i<=k;i++)
	{
		int op=i+n;
		for(int j=1;j<=m;j++)cs[j]=e[j];
		for(int j=m+1;j<=m+n;j++)
		{
			cs[j].u=op;
			cs[j].v=j-m;
			cs[j].w=a[i][j-m];
		}
		sort(cs+1,cs+m+n+1,cmp);
		for(int j=1;j<=n+k;j++)dad[j]=j;
		cnt=0;
		for(int j=1;j<=m+n;j++)
		{
			int u=getfather(cs[j].u);
			int v=getfather(cs[j].v);
			if(u^v)
			{
				dad[u]=v;
				cnt++;
				if(cs[j].u==op)g[i][++g[i][0].w]=cs[j];
			}
			if(cnt==n)break;
		}
	}
	for(int S=0;S<(1<<k);S++)
	{
		int sl=0,gs=0;
		long long sum=0;
		for(int i=1;i<=m;i++)cs[i]=e[i];
		sl=m;
		for(int i=1;i<=k;i++)
		{
			if((S>>(i-1))&1)
			{
				gs++;
				for(int j=1;j<=g[i][0].w;j++)
				{
					sl++;
					cs[sl]=g[i][j];
				}
				sum+=c[i];
			}
		}
		sort(cs+1,cs+sl+1,cmp);
		cnt=0;
		for(int i=1;i<=n+k;i++)dad[i]=i;
		for(int i=1;i<=sl;i++)
		{
			int u=getfather(cs[i].u);
			int v=getfather(cs[i].v);
			if(u^v)
			{
				dad[u]=v;
				cnt++;
				sum+=cs[i].w;
			}
			if(cnt==n+gs-1)break;
		}
		ans=min(ans,sum);
	}
	cout<<ans;
	return 0;
}
