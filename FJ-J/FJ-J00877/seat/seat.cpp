#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.ans", "w", stdout);
	
	int n, m;
	cin >> n >> m;
	int qwe;
	cin >> qwe;
	int cnt = 1;
	for (int i = 2;i <= n * m;i++)
	{
		int x;
		cin >> x;
		if (qwe < x) cnt++;
	}
	
	int x, y;
	x = cnt / n + 1;
	if (cnt % n == 0) x--;
	if (x % 2 == 1)
	{
		y = cnt % n;
		if (y == 0)
		{
			y = n;
		}
	}
	else
	{
		if (cnt % n == 0)
		{
			y = 1;
		}
		y = n - (cnt % n) + 1;
	}
	
	cout << x << " " << y;
	return 0;
}
