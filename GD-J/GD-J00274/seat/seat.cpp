#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, x, y, r = 0, cnt = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			int a;
			cin >> a;
			if (i == 1 && j == 1) r = a;
			else if (a > r) cnt++;
		}
	}
	x = cnt / n;
	y = cnt - x * n;
	if (x % 2 == 0) cout << (x + 1) << " " << (y + 1);
	else cout << (x + 1) << " " << (n - y);
	return 0;
}
