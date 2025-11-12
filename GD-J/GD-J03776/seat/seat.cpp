#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	freopen("seat.in", "w", stdin);
	freopen("seat.out", "r", stdout);
	int n = 0;
	int m = 0;
	int a[110]{};
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)
	{
		cin >> a[i];
	}
	int R = a[1];
	sort(a + 1, a + n * m + 1, greater<int>());
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (R == a[i * n + j + 1])
			{
				cout << i + 1 << " ";
				if (i % 2 == 0)
				{
					cout << j + 1;
				}
				else
				{
					cout << n - j;
				}
			}
		}
	}
	return 0;
}
