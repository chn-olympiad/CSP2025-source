#include <bits/stdc++.h>
using namespace std;
int n, m, cnt;
int mp[101][101];
int a1, a;
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	cin >> a1;
	for (int i = 2; i <= n * m; i++)
	{
		cin >> a;
		if (a > a1)
		{
			cnt++;
		}
	}
	cnt++;
	int lie = (cnt - 1) / m + 1;
	if (lie % 2 == 1)
	{
		if (cnt % n == 0)
		{
			cout << lie << ' ' << n;
		}
		else
		{
			cout << lie << ' ' << cnt % n;
		}
	}
	else
	{
		if (cnt % n == 0)
		{
			cout << lie << ' ' << 1;
		}
		else
		{
			cout << lie << ' ' << n - cnt % n + 1;
		}
	}
	return 0;
}
