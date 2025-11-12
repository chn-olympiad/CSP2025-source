#include <bits/stdc++.h>

using namespace std;
const int N = 100;
int n, m, a[N + 5], c = 1, r = 0, h;
bool cmp (int b, int d)
{
	return b > d;
}
int main ()
{
	freopen ("seat.in", "r", stdin);
	freopen ("seat.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n * m; ++i)
	{
		cin >> a[i];
	}
	h = a[0];
	sort (a, a + n * m, cmp);
	bool f = 1;
	for (int i = 0; i < n * m; ++i)
	{
		if (f)
		{
			r++;
			if (r > n)
			{
				r--;
				c++;
				f = 0;
			}
		}
		else
		{
			r--;
			if (r == 0)
			{
				r++;
				c++;
				f = 1;
			}
		}
		if (a[i] == h)
		{
			cout << c << " " << r;
			return 0;
		}
	}
	return 0;
}