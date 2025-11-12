#include<bits/stdc++.h>
using namespace std;
int a[105], b[15][15];
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, p;
	cin >> n >> m;
	for(int i = 1; i <= n * m; i ++)
		cin >> a[i];
	p = a[1];
	sort(a + 1, a + n * m + 1);
	for(int j = 1; j <= m; j += 2)
	{
		for(int i = 1; i <= n; i ++)
		{
			b[i][j] = a[n * m - ((j - 1) * n + i) + 1];
		}
	}
	for(int j = 2; j <= m; j += 2)
	{
		for(int i = 1; i <= n; i ++)
		{
			b[i][j] = a[n * m - (j * n - i + 1) + 1];
		}
	}
	for(int i = 1; i <= n; i ++)
	{
		for(int j = 1; j <= m; j ++)
		{
			if(b[i][j] == p)
			{
				cout << j << " " << i;
				return 0;
			}
		}
	}
	return 0;
} 
