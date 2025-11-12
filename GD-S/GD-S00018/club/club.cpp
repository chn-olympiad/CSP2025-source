#include <bits/stdc++.h>

using namespace std;

int t, n[11];
int b[6][100010][6];

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &t);
	for (int i = 1; i <= t; i++)
	{
		scanf("%d", &n[i]);
		for (int j = 1; j <= n[i]; j++)
		{
			int x, y, z;
			scanf("%d%d%d", &x, &y, &z);
			b[i][j][1] = x;
			b[i][j][2] = y;
			b[i][j][3] = z;
			int s = max(max(x, y), z);
			if (s == x)
			{
				b[i][j][4] = 1;
			}
			else
			{
				if (s == y)
				{
					b[i][j][4] = 2;
				}
				else
				{
					b[i][j][4] = 3;
				}
			}
		}
	}
	for (int i = 1; i <= t; i++)
	{
		int ans = 0;
		for (int j = 1; j <= 3; j++)
		{
			int sum = 0;
			while (sum < n[i] / 2)
			{
				int m = 0, s = 0;
				for (int l = 1; l <= n[i]; l++)
				{
					if (b[i][l][5] != 1 && b[i][l][j] > m && b[i][l][4] == j)
					{
						m = b[i][l][j];
						s = l;
					}
				}
				ans += b[i][s][j];
				b[i][s][5] = 1;
				++sum;
			}
		}
		printf("%d\n", ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
