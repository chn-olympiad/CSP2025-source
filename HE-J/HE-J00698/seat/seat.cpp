#include<bits/stdc++.h>
#define int long long

using namespace std;

int n, m, a[150], sum, x, y, h, l;

bool cmp(int x, int y)
{
	return x > y;
}

signed main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i ++)
	{
		cin >> a[i];
	}
	x = a[1];
	sort (a + 1, a + n * m + 1, cmp);
	for (int i = 1; i <= n * m; i ++)
	{
		if (a[i] == x)
		{
			y = i;
			break;
		}
	}
	if (y % n == 0) l = y / n;
	else l = y / n + 1;
	if (l % 2 == 1)
	{
		if (y % n == 0) h = n;
		else h = y % n;
	}
	else
	{
		if (y % n == 0)	h = 1;
		else h = n - y % n + 1;
	}
	cout << l << " " << h;
	return 0;
}

