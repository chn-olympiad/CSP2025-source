#include <bits/stdc++.h>
using namespace std;
int n, m, a[105], x;
bool cmp(int a, int b)
{
	return a > b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> a[i * m + j];
		}
	}
	x = a[1];
	sort(a + 1, a + n * m + 1, cmp);
	for (int i = 1; i <= n * m; i++)
	{
		if (a[i] == x)
		{
			int y = i + n - 1;
			if (i % n == 0)
			{
				if (y / n % 2 == 1)
				{
					cout << y / n << " " << n;
				}
				else
				{
					cout << y / n << " " << 1;
				}
			}
			else
			{
				if (y / n % 2 == 1)
				{
					cout << y / n << " " << i % n;
				}
				else
				{
					cout << y / n << " " << n - i % n + 1;
				}
			}
			break;
		}
	}
	return 0;
}
