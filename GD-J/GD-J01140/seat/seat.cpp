#include <iostream>
#include <algorithm>
#include <cmath>
#define int long long
using namespace std;
const int N = 1e6 + 10;
int a[N], n, m, target, t;
bool cmp(int x, int y)
{
	return x > y;
}
signed main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; ++i)
	{
		cin >> a[i];
	}
	t = a[1];
	sort(a + 1, a + n * m + 1, cmp);
	for (int i = 1; i <= n * m; ++i)
	{
		if (a[i] == t)
		{
			target = i;
			break;
		}
	}
	int c = ceil(target * 1.0 / n);
	int r = (c & 1 ? target - c * n + n : c * n - target + 1);
	cout << c << ' ' << r;
	return 0;
}
