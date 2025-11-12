# include <bits/stdc++.h>
using namespace std;
const int N = 105;
int n, m;
int a[N];
int x, y = 1, add = 1, pts;
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i ++)
	{
		cin >> a[i];
	}
	pts = a[1];
	sort(a + 1, a + 1 + n * m, [](int u, int v){
		return u > v;
	});
	for (int i = 1; i <= n * m; i ++)
	{
		x += add;
		if (x > n)
		{
			x = n;
			y ++;
			add = -1;
		}
		if (!x)
		{
			x = 1;
			y ++;
			add = 1;
		}
		if (a[i] == pts)
		{
			cout << y << ' ' << x;
			return 0;
		}
	}
	return 0;
}

