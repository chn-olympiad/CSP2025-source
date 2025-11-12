#include<bits/stdc++.h>
using namespace std;
int n, m, a[101];
bool cmp(int x, int y)
{
	return x > y;
}
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)
		cin >> a[i];
	int c = 1, r = 1, R = a[1], k = 1;
	sort(a + 1, a + n * m + 1, cmp);
	for (int i = 1; i <= m; i++)
	{
		if (a[k] == R) cout << c << ' ' << r << "  ";
		k++;
		for (int j = 1; j < n; j++)
		{
			if (i % 2 == 1) r++;
			else r--;
			if (a[k] == R) cout << c << ' ' << r << "  ";
			k++;
		}
		c++;
	}
	return 0;
}
