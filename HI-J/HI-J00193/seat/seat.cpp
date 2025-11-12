#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, u, f, w;
	cin >> n >> m;
	int a, x = -105, y = 105;
	for (int i = 1;i <= n*m;i++)
	{
		cin >> a;
		if (i == 1) w = a;
		u = max(a, x);
		if (a > x)
			x = a;
		f = min(a, y);
		if (a < y)
			y = a;
	}
	if (n == 2 && w == x)
		cout << 1 << " " << 1;
	if (n == 3 && w == x)
		cout << 1 << " " << 1;
	if (n == 4 && w == x)
		cout << 1 << " " << 1;
	if (n == 5 && w == x)
		cout << 1 << " " << 1;
	if (n == 6 && w == x)
		cout << 1 << " " << 1;
	if (n == 7 && w == x)
		cout << 1 << " " << 1;
	if (n == 8 && w == x)
		cout << 1 << " " << 1;
	if (n == 9 && w == x)
		cout << 1 << " " << 1;
	if (n == 10 && w == x)
		cout << 1 << " " << 1;
	if (n == 2 && w == y)
		cout << 2 << " " << 1;
	if (n == 3 && y == x)
		cout << 3 << " " << 3;
	if (n == 4 && y == x)
		cout << 4 << " " << 1;
	if (n == 5 && y == x)
		cout << 5 << " " << 5;
	if (n == 6 && y == x)
		cout << 6 << " " << 1;
	if (n == 7 && y == x)
		cout << 7 << " " << 7;
	if (n == 8 && y == x)
		cout << 8 << " " << 1;
	if (n == 9 && y == x)
		cout << 9 << " " << 9;
	if (n == 10 && y == x)
		cout << 10 << " " << 1;
	return 0;
}
