#include<bits/stdc++.h>
using namespace std;

int const MAX_N = (int)1e5 + 1;

int n, a[MAX_N][3], dp_p[MAX_N][3], dp_g[MAX_N][3][3], lim, res;

/*
about dp_p[i][j] -> when i choose j -> max res
about dp_g[i][j][k] -> when i choose j -> member of group k
*/

void read()
{
	scanf("%d", &n);
	
	for (int i = 1; i <= n; i ++)
	{
		scanf("%d %d %d", &a[i][0], &a[i][1], &a[i][2]);
	}
}

void slove_v1()
{
	// init
	lim = n / 2;
	res = 0;
	
	for (int i = 1; i <= n; i ++)
	{
		for (int j = 0; j < 3; j ++)
		{
			dp_g[i][j][j] = dp_g[i - 1][j][j];
			dp_p[i][j] = max(dp_p[i - 1][0], max(dp_p[i - 1][1], dp_p[i - 1][2]));
			
			if (dp_g[i][j][j] <= lim)
			{
				dp_p[i][j] += a[i][j];
				dp_g[i][j][j] ++;
			}
			
			//printf("i %d j %d dpp %d dpg %d")
		}
	}
	
	printf("%d\n", max(dp_p[n][0], max(dp_p[n][1], dp_p[n][2])));
}

void slove_v2()
{
	// init
	lim = n / 2;
	res = 0;
	
	int maxn = 0;
	
	for (int i = 1; i <= n; i ++)
	{
		for (int j = 0; j < 3; j ++)
		{
			dp_p[i][j] = 0;
			
			for (int k = 0; k < 3; k ++)
			{				
				if (dp_g[i - 1][k][j] <= lim)
				{
					if (dp_p[i][j] < dp_p[i - 1][k] + a[i][j])
					{
						dp_p[i][j] = dp_p[i - 1][k] + a[i][j];
					}
					else
					{
						dp_p[i][j] = dp_p[i][j];
					}
					
					dp_g[i][j][j] = dp_g[i - 1][k][j] + 1;
				}
			}
		}
	}
	maxn = max(max(dp_p[n][0], max(dp_p[n][1], dp_p[n][2])), maxn);
	
	printf("%d\n", max(dp_p[n][0], max(dp_p[n][1], dp_p[n][2])));
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	int t;
	scanf("%d", &t); 
	
	while (t --)
	{
		read();
		slove_v2();
	}
		
	return 0;
}
