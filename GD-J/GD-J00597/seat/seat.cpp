#include <bits/stdc++.h>
using namespace std;
int n, m, x, a[105], sc[15][15], p;
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)
	{
		cin >> a[i];
	}
	x = a[1];
	sort (a + 1, a + n * m + 1);
	reverse (a + 1, a + n * m + 1);
	for (int i = 1; i <= m; i++)
	{
		if (i % 2 == 1)
		{
			for (int j = 1; j <= n; j++)
			{
				sc[j][i] = a[++p];
				if (a[p] == x)
				{
					cout << i << ' ' << j;
					return 0;
				}
			}
		}
		else
		{
			for (int j = n; j >= 1; j--)
			{
				sc[j][i] = a[++p];
				if (a[p] == x)
				{
					cout << i << ' ' << j;
					return 0;
				}
			}
		}
	}
	return 0;
}
