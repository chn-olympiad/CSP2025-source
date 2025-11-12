#include <bits/stdc++.h>
using namespace std;
int n, a[5][10007], b, c, d, t, peo[10005], sum;
int main()
{
	freopen ("club.in", "r", stdin);
	freopen ("club.out", "w", stdout);
	cin >> t;
	for (int j = 1; j <= t; j++)
	{
		sum = 0;
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[1][i] >> a[2][i] >> a[3][i];
			if (a[1][i] > max(a[2][i], a[3][i]))
			{
				peo[j] = 1;
				if (b > n / 2)
				{
					for (int k = 1; k <= n; k++)
					{
						if (a[1][k] < a[1][j] && peo[k] == 1)
						{
							sum -= a[1][k] - a[1][j];
							if (a[2][k] > a[3][k])
							{
								peo[k] = 2;
								sum += a[2][k];
							}
							else
							{
								peo[k] = 3;
								sum += a[3][k];
							}
							break;
						}
					}
				}
				sum += a[1][i];
				b++;
			}
			else if (a[2][i] > max(a[1][i], a[3][i]))
			{
				peo[j] = 2;
				if (c > n / 2)
				{
					for (int k = 1; k <= n; k++)
					{
						if (a[2][k] < a[2][j] && peo[k] == 2)
						{
							sum -= a[2][k] - a[2][j];
							if (a[1][k] > a[3][k])
							{
								peo[k] = 1;
								sum += a[1][k];
							}
							else
							{
								peo[k] = 3;
								sum += a[3][k];
							}
							break;
						}
					}
				}
				sum += a[2][i];
				c++;
			}
			else if (a[3][i] > max(a[2][i], a[1][i]))
			{
				peo[j] = 3;
				if (d > n / 2)
				{
					for (int k = 1; k <= n; k++)
					{
						if (a[3][k] < a[3][j] && peo[k] == 3)
						{
							sum -= a[3][k] - a[3][j];
							if (a[1][k] > a[2][k])
							{
								peo[k] = 1;
								sum += a[1][k];
							}
							else
							{
								peo[k] = 2;
								sum += a[2][k];
							} 
							break;
						}
					}
				}
				sum += a[3][i];
				d++;
			}
		}
		cout << sum << endl;
	}
	return 0;
}
