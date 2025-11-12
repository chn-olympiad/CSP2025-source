#include <bits/stdc++.h>
using namespace std;
struct int1
{
	int val;
	int idx;
}a[110];
bool cmp1(int1 a, int1 b)
{
	return a.val > b.val;
}
int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, x = 1, y = 1; cin >> n >> m;
	for (int i = 1; i <= m*n; i++)
	{
		cin >> a[i].val;
		a[i].idx = i;
	}
	int R = a[1].val;
	sort(a+1, a+m*n, cmp1);
	//for (int i = 1; i <= m*n; i++) cout << a[i].val << ' ';
	//cout << '\n';
	for (int i = 1; i <= m*n; i++)
	{
		if (a[i].val == R)
		{
			if (i % n != 0)
			{
				x = i / n + 1;
				//printf("%d / %d + 1 = %d\n", i, n, x);
			} else {
				x = i / n;
				//printf("%d / %d = %d\n", i, n, x);
			}
			if (x % 2 == 1)
			{
				y = i % n;
				if (y == 0) y = n;
				//printf("%d mod %d = %d\n", i, n, y);
			} else {
				y = m - (i % n) + 1;
				if (y == m + 1) y %= m;
				//printf("%d - %d mod %d + 1 = %d\n", m, i, n, y);
			}
		}
	}
	cout << x << ' ' << y;
}