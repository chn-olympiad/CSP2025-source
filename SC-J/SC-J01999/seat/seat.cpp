#include <bits/stdc++.h>
using namespace std;
int a[105], n, m;
bool cmp(int a, int b)
{
	return a > b;
}
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= m; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			cin >> a[(i - 1) * n + j];
		}
	}
	int f = a[1], idx = 1, idy = 0;
	sort(a + 1, a + n * m + 1, cmp);
	for(int i = 1; i <= m; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			if(idx % 2 == 1)
			{
				idy++;
			}
			else
			{
				idy--;
			}
			if(a[(i - 1) * n + j] == f)
			{
				cout << idx << " " << idy;
				return 0;
			}
		}
		idx++;
	}
	return 0;
}