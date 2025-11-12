#include <bits/stdc++.h>

using namespace std;
int a[105];

int main()
{
	freopen ("seat.in", "r", stdin);
	freopen ("seat.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1;i <= n * m;i ++)
	{
		cin >> a[i];
	}
	int R = a[1];
	sort (a + 1, a + n * m + 1, greater<int>());
	int pm;
	for (int i = 1;i <= n * m;i ++)
	{
		if (a[i] == R)
		{
			pm = i;
			break;
		}
	}
	cout << ceil (pm * 1.0 / n) << " ";
	int ls = ceil (pm * 1.0 / (2 * n));
	int lm = pm - (ls - 1) * 2 * n;
	if (lm <= n)
	{
		cout << lm;
	}
	else
	{
		cout << 2 * n - lm + 1;
	}
	return 0;
}
