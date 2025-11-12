#include<bits/stdc++.h>
using namespace std;
const long long jsljd=1000000000000005;
long long n,m,k,ans;
long long aaaaa[5005],
a[5005][5005],di[5005];
bool c,vis[10005];
void zxscs()
{
	for(int i=0;i<=5000;i++)
	{
		di[i]=jsljd;
	}
	di[1]=0;
	for(int i=1;i<=n;i++)
	{
		int x=0;
		for(int j=1;j<=n;j++)
		{
			if(di[x]>di[j]&&vis[j]==0)
			{
				x=j;
			}
		}
		vis[x]=1;
		for(int j=1;j<=n;j++)
		{
			if(di[j]>a[x][j]&&vis[j]==0)
			{
				di[j]=a[x][j];
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		ans+=di[i];
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	for(int i=0;i<=5000;i++)
	{
		for(int j=0;j<=5000;j++)
		{
			a[i][j]=jsljd;
			if(i==j)
			{
				a[i][j]=0; 
			}
		}
	}
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		long long u,v,w;
		scanf("%lld%lld%lld",&u,&v,&w);
		a[u][v]=a[v][u]=min(a[u][v],w);
	}
	for(int i=1;i<=k;i++)
	{
		long long c1;
		scanf("%lld",&c1);
		if(c1!=0)
		{
			c=1;
		}
		for(int j=1;j<=n;j++)
		{
			scanf("%lld",&aaaaa[j]);
			for(int i1=1;i1<j;i1++)
			{
				a[j][i1]=a[i1][j]=min(a[j][i1],aaaaa[j]+aaaaa[i1]);
			}
			a[j][j]=0;
		}
	}
	if(c==0)
	{
		zxscs();
		printf("%lld",ans);
		return 0; 
	}
	printf("0");
	return 0;
}
