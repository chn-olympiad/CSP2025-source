#include <bits/stdc++.h>
using namespace std;
int n, m, a[105];

bool cmp(int x, int y)
{
	return x > y;
}

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) cin >> a[i];
	int x = a[1], pos;
	sort(a + 1, a + n * m + 1, cmp);
	int c = 1, r = 1;
	for (int i = 1; i <= n * m; i++)
	{
		if (a[i] == x)
		{
			cout << c << " " << r << endl;
			return 0;
		}
		if (c % 2 == 1)
		{
			r++;
			if (r > n)
			{
				r = n;
				c++;
			}
		}
		else
		{
			r--;
			if (r < 1)
			{
				r = 1;
				c++;
			}
		}
	}
	return 0;
}
