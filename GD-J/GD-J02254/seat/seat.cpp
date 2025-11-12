#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[105], f[11][11];
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	int num = n*m;
	f[1][1] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (i == 1 && j == 1) continue;
			if (i == 1)
			{
				if (j % 2 == 0) f[i][j] = f[i][j-1] + 2*n-1;
				else f[i][j] = f[i][j-1] + 1;
			}
			else
			{
				if (j % 2 == 0) f[i][j] = f[i-1][j] - 1;
				else f[i][j] = f[i-1][j] + 1;
			}
		}
	}
	for (int i = 1; i <= num; i++)
	{
		cin >> a[i];
	}
	int sum = a[1];
	sort(a+1, a+1+num);
	int cnt = 0, pm = 0;
	for (int i = num; i >= 1; i--)
	{
		cnt++;
		if (a[i] == sum) pm = cnt;
	}
	int c = 0, r = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (pm == f[i][j])
			{
				c = j;
				r = i;
			}
		}
	}
	cout << c << " " << r;
	return 0;
}
