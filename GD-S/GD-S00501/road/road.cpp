#include<iostream>
using namespace std;
long long n,m,k,d[1001],a[1001][1001],x,y,z,ans;
bool vis[1001];
struct intt{
	long long ccst,tcst[1001],zrp;
}cty[101];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)a[i][j]=1145141919810;
		a[i][i]=0;
	}
	for(int i=1;i<=m;i++)scanf("%lld%lld%lld",&x,&y,&z),a[x][y]=a[y][x]=min(a[x][y],z);
	if(k==0)
	{
		vis[1]=1;
		for(int i=2;i<=n;i++)d[i]=a[1][i];
		for(int _=1;_<n;_++)
		{
			long long p=0,minn=1145141919810;
			for(int i=2;i<=n;i++)if(!vis[i]&&d[i]<minn)p=i,minn=d[i];
			vis[p]=1;ans+=d[p];
			for(int i=1;i<=n;i++)if(!vis[i]&&d[i]>a[p][i])d[i]=a[p][i];
		}printf("%lld",ans);
		return 0;
	}
	else
	{
		bool flag=0;
		for(int i=1;i<=k;i++)
		{
			scanf("%lld",&cty[i].ccst);flag|=cty[i].ccst;
			for(int j=1;j<=n;j++)
			{
				scanf("%lld",&cty[i].tcst[j]);
				if(!cty[i].tcst[j]&&!flag)cty[i].zrp=j;
			}
		}
		if(!flag)
		{
			for(int i=1;i<=k;i++)
			{
				for(int j=1;j<=n;j++)
				{
					if(j==cty[i].zrp)continue;
					a[cty[i].zrp][j]=a[j][cty[i].zrp]=min(a[j][cty[i].zrp],cty[i].tcst[j]);
				}
			}
			vis[1]=1;
			for(int i=2;i<=n;i++)d[i]=a[1][i];
			for(int _=1;_<n;_++)
			{
				long long p=0,minn=1145141919810;
				for(int i=2;i<=n;i++)if(!vis[i]&&d[i]<minn)p=i,minn=d[i];
				vis[p]=1;ans+=d[p];
				for(int i=1;i<=n;i++)if(!vis[i]&&d[i]>a[p][i])d[i]=a[p][i];
			}printf("%lld",ans);
			return 0;
		}
	}
	return 0;
}

