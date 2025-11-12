#include <bits/stdc++.h>
using namespace std;

struct lu
{
	int u,v,w;
};
lu a[10010];

int dp[10010][10010] = {0};

int c[15] = {0};

int b[15][10010] = {0};

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= n;j++)
		{
			dp[i][j] = 1e9;
		}
	}
	for (int i = 1;i <= m;i++)
	{
		scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
	}
	for (int i = 1;i <= k;i++)
	{
		scanf("%d",&c[i]);
		for (int j = 1;j <= n;j++)
		{
			scanf("%d",&b[i][j]);
		}
	}
	for (int i = 1;i <= k;i++)
	{
		if (c[i] == 0)
		{
			int flag = 1;
			for (int j = 1;j <= n;j++)
			{
				if (b[i][j] != 0)
				{
					flag = 0;
					break;
				}
			}
			if (flag)
			{
				printf("0");
				return 0;
			}
		}
	}
	for (int i = 0;i <= (1 << k);i++)
	{
		int he = 0;
		for (int j = 0;j < k;j++)
		{
			if ((1 << j) & i)
			{
				he += c[j + 1];
			}
		}
		
	}
	return 0;
}
