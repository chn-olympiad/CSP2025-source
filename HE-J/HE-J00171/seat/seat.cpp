#include<bits/stdc++.h>
using namespace std;

int a[105], n, m, x, y, cnt = 1;

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)
	{
		cin >> a[i];
		if (i != 1 && a[1] < a[i]) cnt += 1;
	}
	x = cnt / n;
	if (cnt % n != 0)
	{
		x++;
		cout << x << " ";
	}
	else cout << x << " ";
	y = cnt % n;
	if (y == 0) y = n;
	if (x % 2 == 1) cout << y;
	if (x % 2 == 0) cout << n - y + 1;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
