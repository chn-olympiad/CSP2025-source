#include <bits/stdc++.h>
using namespace std;
int road[10010][10010];
int c[20],a[20][10010];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	memset(road,0x7f,sizeof(road));
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		road[u][v]=min(road[u][v],w);
	}
	if(k==0)
	{
		
	}
	else
	{
		for(int i=1;i<=k;i++)
		{
			scanf("%d",&c[i]);
			for(int j=1;j<=n;j++)
			{
				scanf("%d",&a[i][j]);
			}
		}
	}

	return 0;
}