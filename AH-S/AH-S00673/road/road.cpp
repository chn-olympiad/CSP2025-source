#include <bits/stdc++.h>
using namespace std;

struct road
{
	int u,v,w;//u、v是连通的两个城市，w为修复所需费用
}rd[1000005];
struct village
{
	int c,a[10005];
}ve[11];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,sum=0;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>rd[i].u>>rd[i].v>>rd[i].w;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>ve[i].c;
		for(int j=1;j<=n;j++)
		{
			cin>>ve[i].a[j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			for(int k=1;k<=m;k++)
			{
				if((rd[k].u==i && rd[k].v==j) || (rd[k].u==j && rd[k].v==i))
				{
					sum+=rd[k].w;
					int mincp=INT_MAX;
					for(int l=1;l<=k;l++)
					{
						mincp=min(ve[l].a[i]+ve[l].a[j]+ve[l].c,mincp);
					}
					if(mincp<=rd[k].u)
					{
						sum=sum-rd[k].w+mincp;
					}
				}
				
			}
		}
	}
	cout<<sum;
}
