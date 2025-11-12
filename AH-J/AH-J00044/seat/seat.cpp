#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 9;
int a[N];
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	int q;
	for (int i = 1; i <= n * m; ++i)
		scanf("%d", &a[i]);
	q = a[1];
	sort(a + 1, a + n * m + 1, greater<int>());
	for (int i = 1, x = 1, y = 1; i <= n * m; ++i)
	{
		if (a[i] == q) { printf("%d %d", y, x); return 0; }
		// printf("%d %d\n", x, y);
		if (y & 1)
		{
			if (x == m)
				++y;
			else
				++x;
		}
		else
		{
			if (x == 1)
				++y;
			else
				--x;
		}
	}
	return 0;
}

