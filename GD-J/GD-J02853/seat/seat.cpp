#include <bits/stdc++.h>
using namespace std;

int a[120];

bool cmp(int x, int y)
{
	return x > y;
}

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	int n, m, R, sz, pos, x, y;
	cin >> n >> m;
	sz = n * m;
	
	for (int i = 1; i <= sz; i++)
	{
		cin >> a[i];
	}
	
	R = a[1];
	sort(a + 1, a + sz + 1, cmp);
	
	for (int i = 1; i <= sz; i++)
	{
		if (a[i] == R)
		{
			pos = i;
			break;
		}
	}
	
	if (pos % n == 0)
	{
		x = pos / n;
		
		if (x % 2 == 1)
		{
			y = n;
		}
		else
		{
			y = 1;
		}
	}
	else
	{
		y = pos % n;
		x = pos / n + 1;
		
		if (x % 2 == 0)
		{
			y = n - y + 1;
		}
	}
	
	cout << x << " " << y;
	return 0;
}

