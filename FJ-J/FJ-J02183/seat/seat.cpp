#include <bits/stdc++.h>
using namespace std;
int n, m, a[105], x, y;
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
	sort(a + 1, a + n * m + 1);
	for (int i = 1; i <= n * m; i++)
	{
		if (a[i] == x)
		{
			y = n * m - i + 1;
			break;
		}
	}
	if (y % n == 0)
	{
		if (y / n % 2 == 0)
		{
			cout << y / n << " " << 1;
		}
		else
		{
			cout << y / n << " " << n;
		}
	}
	else
	{
		if (y / n % 2 == 0)
		{
			cout << y / n + 1 << " " << y % n;
		}
		else
		{
			cout << y / n + 1 << " " << n - y % n + 1;
		}
	}
	return 0;
}
