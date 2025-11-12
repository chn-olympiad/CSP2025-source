#include <bits/stdc++.h>
using namespace std;
int n, m, a[100000], R, r, c;
bool cmp (int a, int b)
{
	return a > b;
}
int main ()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i ++)
		cin >> a[i];
	R = a[1];
	sort(a + 1, a + n * m + 1, cmp);
	for (int i = 1; i <= m * n; i ++)
	{
		if (a[i] == R)
		{
			i --;
			c = i / n + 1;
			r = i % n + 1;
			if (c % 2 == 0) r = n - r + 1;
			cout << c << " " << r;
			break;
		}
	} 
	return 0;
}
