#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 10;

int n, m;

int a[N];

int resx, resy;

int cmp(const int &x, const int &y)
{
	return x > y;
}

signed main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> m;
	
	int k = n * m;
	
	for (int i=1; i<=k; i++)
		cin >> a[i];
	
	int value = a[1];
	
	sort (a+1, a+k+1, cmp);
	
	int x = 1, y = 1;
	
	for (int i=1; i<=k; i++)
	{
		if (a[i] == value)
		{
			resx = x, resy = y;
			
			break;
		}
		
		if (x & 1)
		{
			++y;
			
			if (y == n + 1)
				y = n, ++x;
		}
		else
		{
			--y;
			
			if (y == 0)
				y = 1, ++x;
		}
	}
	
	cout << resx << ' ' << resy << '\n';
	
	return 0;
}
