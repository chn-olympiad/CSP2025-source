#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[1000], c[100][100], x, cnt;
bool cmp(int x, int y)
{
	return x > y;
}
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1;i <= n * m;i++) cin >> a[i];
	x = a[1];
	sort (a + 1, a + n * m + 1, cmp);
 	for (int i = 1;i <= m;i++)
	{
		if (i % 2 == 1) 
		{
			for (int j = 1;j <= n;j++)
				c[j][i] = a[++cnt];
		}
		else 
		{
			for (int j = n;j >= 1;j --)
				c[j][i] = a[++cnt];
		}
	}
	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= m;j++)
		{
			if (c[i][j] == x) cout << j << " " << i;
		}
	}
	return 0;
}
