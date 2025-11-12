#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
const int N = 1e3 + 10;
long long n, m, a[N], xr_a, xr_s, ans_n, ans_m, s, nm;
bool f;
bool cmp(long long x, long long y)
{
	return x > y;
}
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	nm = n * m;
	for (int i = 1; i <= nm; i++)
	{
		cin >> a[i];
	}
	xr_a = a[1];
	sort(a + 1, a + nm + 1, cmp);
	for (int i = 1; i <= nm; i++)
	{
		if (a[i] == xr_a)
		{
			xr_s = i;
			break;
		}
	}
	s = 0, f = false;
	while (s < xr_s)
	{
		s += n;
		ans_n++;
	}
	ans_m = xr_s - (ans_n - 1) * m;
	if (ans_n % 2 == 0) ans_m = n - ans_m + 1;
	cout << ans_n << ' ' << ans_m;
	return 0;
}