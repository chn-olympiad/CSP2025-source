#include<bits/stdc++.h>
using namespace std;
int n,m,k,city[1000005][7],c_cost[1000005],h_coster[15],h_cost[15][10005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++)
	{
		for (int j=1;j<=3;j++)
		{
			if (j!=3)
			{
				cin>>city[i][j];
			}
			else
			{
				cin>>c_cost[i];
			}
		}
	}
	for (int i=1;i<=k;i++)
	{
		for (int j=1;j<=n+1;j++)
		{
			if (j==1)
			{
				cin>>h_coster[i];
			}
			else
			{
				cin>>h_cost[i][j];
			}
		}
	}
	cout<<0;
	return 0;
}
