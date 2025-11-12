#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int n, m, a[N], s, t[N][N], pos = 1;

bool cmp (int x, int y)
{
	return x > y;
}

int main ()
{
	freopen ("seat.in", "r", stdin);
	freopen ("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1;i <= n * m;i ++)
	{
		cin >> a[i];
	}
	s = a[1];
	sort (a + 1, a + n * m + 1, cmp);
	int i = 1, j = 1;
	for (int l = 1;l <= m;l ++)
	{
		if (l % 2 == 1)
		{
			while (i <= n)
			{
				t[i][j] = a[pos];
				if (a[pos] == s)
				{
					cout << j << " " << i;
					return 0;
				}
				pos ++;
				i ++;
			}
			i --,j ++;
		}
		else
		{
			while (i >= 1)
			{
				t[i][j] = a[pos];
				if (a[pos] == s)
				{
					cout << j << " " << i;
					return 0;
				}
				pos ++;
				i --;
			}
			i ++, j ++;
		}
	}
	return 0;
}