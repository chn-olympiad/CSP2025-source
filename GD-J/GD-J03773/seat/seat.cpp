#include <bits/stdc++.h>

using namespace std;

const int N = 107;

int n, m, a[N];

inline int cmp(int x, int y) { return x > y; }

int dfs(int r, int x, int y, int d)
{
	if (x < 1) 
	{
		if (dfs(r, 1, y + 1, d))
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	if (x > n) 
	{
		if (dfs(r, n, y + 1, d))
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	
	if (r == d) 
	{
		if (x >= 1 && x <= n && y >= 1 && y <= m) 
			cout << y << " " << x << endl;
		return 1;
	}
	
	if (y % 2 == 1) 
	{
		if (dfs(r + 1, x + 1, y, d)) 
		{
			return 1;
		}
	}
	else 
	{
		if (dfs(r + 1, x - 1, y, d)) 
		{
			return 1;
		}
	}
	return 0;
}

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	cin >> n >> m;
	for (int i = 1; i <= n * m; ++i)
		cin >> a[i];
	
	int x = a[1], r = 0;
	sort(a + 1, a + n * m + 1, cmp);
	for (int i = 1; i <= n * m; ++i)
		if (a[i] == x)
		{
			r = i;
			break;
		}
	dfs(1, 1, 1, r);
	
	return 0;
}
