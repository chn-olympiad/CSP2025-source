#include<bits/stdc++.h>
using namespace std;
int n,m,k,minn,u,sum,a[10015][10015],x,y,z,ans[10005],c[15],p[10005],l,pos;
bool bz[10005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for (int i=1;i<=n+k;i++) ans[i]=1000000000+1;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			a[i][j]=1000000000+1;
		}
	}
	for (int i=n+1;i<=n+k;i++)
	{
		for (int j=n+1;j<=n+k;j++)
		{
			a[i][j]=1000000000+1;
		}
	}
	for (int i=1;i<=m;i++)
	{
		scanf("%d %d %d",&x,&y,&z);
		a[x][y]=min(a[x][y],z);
		a[y][x]=min(a[x][y],z);
	}
	for (int i=n+1;i<=n+k;i++)
	{
		cin>>c[0];
		for (int j=1;j<=n;j++)
		{
			scanf("%d",&p[j]);
			a[i][j]=p[j];
			a[j][i]=p[j];
		}
	}
	n=n+k;
	bz[1]=true;l++;u=1;
	while (l<n)
	{
		bz[u]=true;
		for (int i=1;i<=n;i++)
		{
			ans[i]=min(ans[i],a[u][i]);
		}
		minn=1000000000+1;
		for (int i=1;i<=n;i++)
		{
			if (!bz[i]&&ans[i]<minn)
			{
				u=i;minn=ans[i];
			}
		}
		sum+=minn;l++;
	}
	cout<<sum;
	return 0;
}
