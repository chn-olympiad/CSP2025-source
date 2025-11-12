#include <bits/stdc++.h>
using namespace std;
const int N = 11;
int n, m, s, a[N * N];
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)
		cin >> a[i];
	s = a[1];
	sort(a + 1, a + n * m + 1, greater<int>());
	for (int i = 1, r = 1, c = 1; i <= n * m; i++)
	{
		if (a[i] == s)
		{
			cout << c << ' ' << r;
			return 0;
		}
		if (c % 2)
			if (r == n) c++;
			else r++;
		else
			if (r == 1) c++;
			else r--;
	}
	return 0;
}
