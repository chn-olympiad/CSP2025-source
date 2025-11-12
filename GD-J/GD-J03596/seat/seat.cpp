#include <bits/stdc++.h>
using namespace std;
int n, m, a[400], s;
int wz, l, h;
bool cmp (int x, int y)
{
	return x > y;
}
int main ()
{
	freopen ("seat.in", "r", stdin);
	freopen ("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; ++i)
	{
		cin >> a[i];
	} 
	s = a[1];
	sort (a + 1, a + n * m + 1, cmp);
	
	for (int i = 1; i <= n * m; ++i)
	{
		if (s == a[i])
		{
			wz = i % (2 * n);
			if (!wz) wz = 2 * n;
			l = (i - 1) / (2 * n) * 2 + 1;
			if (wz >= (n + 1) && wz <= (2 * n))
			{
				l++;
			}
			if (wz >= 1 && wz <= n)
			{
				h = wz;
			}else{
				h = 2 * n + 1 - wz;
			}
			cout << l << " " << h;
			return 0;
			
		}
	}
	fclose (stdin);
	fclose (stdout);
	return 0;
}
