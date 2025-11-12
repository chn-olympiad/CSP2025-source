#include <bits/stdc++.h>
using namespace std;

int a[105], b[15][15], n, m, k, cur, s, tag;

bool cmp(int x, int y)
{
	return x > y;
}

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	k = n * m;
	for (int i = 1; i <= k; i++) cin >> a[i];
	tag = a[1];
	sort(a + 1, a + k + 1, cmp);
	for (int j = 1; j <= m; j++)
	{
		if (j % 2)
		{
			for (int i = 1; i <= n; i++) 
				b[i][j] = a[++cur];
		}
		else
		{
			for (int i = n; i >= 1; i--)
				b[i][j] = a[++cur];
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (b[i][j] == tag)
			{
				cout << j << " " << i;
				return 0;
			}
		}
	 } 
	return 0;
}
