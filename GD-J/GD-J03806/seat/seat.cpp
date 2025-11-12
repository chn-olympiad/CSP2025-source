#include <bits/stdc++.h>
using namespace std;

const int N = 200000, M = 5001, inf = 0x3f3f3f3f, dx[] = {0, 0, -1, 1}, dy[] = {1, -1, 0, 0}, mod = 1e9 + 7;

int a[N];

bool cmp (int a, int b)
{
	return a > b;
}

signed main ()
{
	ios::sync_with_stdio (0); cin.tie (0); cout.tie (0);
	freopen ("seat.in", "r", stdin);
	freopen ("seat.out", "w", stdout);
	int n, m, p = 0;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)
	{
		cin >> a[i];
		p = a[1];
	}
	sort (a + 1, a + (n * m) + 1, cmp);
	for (int i = 1; i <= n * m; i++)
	{
		if (a[i] == p)
		{
			cout << ((i % n == 0) ? (i / n) : ((i / n) + 1)) << " " << ((((i % n == 0) ? (i / n) : ((i / n) + 1)) % 2 == 1) ? (((i % n == 0) ? (n) : (i % n))) : (n - ((i % n == 0) ? (n) : (i % n)) + 1));
			return 0;
		}
	}
	cout << -1;
	return 0;
}

/*
2 2
99 100 97 98

1 2

----------

2 2
98 99 100 97

2 2

----------

2 2
97 99 98 100

2 1

----------

3 3
94 95 96 97 98 99 100 93 92

3 1
*/
