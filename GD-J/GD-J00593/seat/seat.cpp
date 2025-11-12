#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int a[107], s[17][17];

bool cmp(int x, int y)
{
	return x > y;
}

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n * m; i++)
	{
		cin >> a[i];
	}
	int R = a[0];
	sort(a, a + n * m, cmp);
	int cur = 0;
	for (int i = 1; i <= n; i++)
	{
		if (i & 1)
		{
			for (int j = 1; j <= m; j++)
			{
				s[i][j] = a[cur];
				cur++;
				if (s[i][j] == R)
				{
					cout << i << " " << j;
					return 0;
				}
			}
		}
		else
		{
			for (int j = m; j >= 1; j--)
			{
				s[i][j] = a[cur];
				cur++;
				if (s[i][j] == R)
				{
					cout << i << " " << j;
					return 0;
				}
			}
		}
	}
	return 0;
}
