#include <bits/stdc++.h>
using namespace std;

int n, m, r;
int a[1005];
int w[20][20];

bool cmp (int x, int y)
{
	return x > y;
} 

int main()
{
	freopen ("seat.in", "r", stdin);
	freopen ("seat.out", "w", stdout);
	
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)
	{
		cin >> a[i];
	}
	r = a[1];
	sort (a + 1, a + n * m + 1, cmp);
	int cur = 0;
	for (int i = 1; i <= m; i++)
	{
		if (i % 2 == 1)
		{
			for (int j = 1; j <= n; j++)
			{
				cur++;
				w[j][i] = a[cur];
			}
		}
		if (i % 2 == 0)
		{
			for (int j = n; j >= 1; j--)
			{
				cur++;
				w[j][i] = a[cur];
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (w[i][j] == r)
			{
				cout << j << ' ' << i << '\n';
				return 0;
			}
		}
	}
	
	return 0;
}

