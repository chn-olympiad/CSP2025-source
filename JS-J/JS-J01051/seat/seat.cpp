#include<bits/stdc++.h>
using namespace std;
int n, m;
int a[1000];
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)
	{
		cin >> a[i];
	}
	int k = a[1];
	int ans = 0;
	for (int i = 1; i < n * m; i++)
	{
		for (int j = 1; j <= n * m - i; j++)
		{
			if (a[j] <= a[j + 1]) swap(a[j], a[j + 1]);
		}
	}
 	for (int i = 1; i <= m; i++)
	{
		if (i % 2 == 1)
		{
			for (int j = 1; j <= n; j++)
			{
				ans++;
				if (k == a[ans])
				{
					cout << i << " " << j;
					return 0;
				}
			}
		}
		else
		{
			for (int j = n; j >= 1; j--)
			{
				ans++;
				if (k == a[ans])
				{
					cout << i << " " << j;
					return 0;
				}
					}
				}
			}
	return 0;
}

