#include <cstdio>
#include <algorithm>
int n, m, ansx = 1, ansy = 1, a[107];
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n * m; ++i)
		scanf("%d", &a[i]);
	a[0] = a[1], std::sort(a + 1, a + n * m + 1, [&](const int &x, const int &y) { return x > y; });
	for (int i = 1, x = 1, y = 1; x <= n && y <= m; ++i)
		if (a[i] == a[0] && (ansx = x, ansy = y, true))
			break;
		else
			y & 1 ? (x == n ? ++y : ++x) : (x == 1 ? ++y : --x);
	printf("%d %d", ansy, ansx);
	return 0;
}