#include <bits/stdc++.h>
using namespace std;
const int N = 11;
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	int a[N * N + 1] = {0};
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)
		cin >> a[i];
	int r = a[1];
	sort(a + 1, a + n * m + 1, greater<int>());
	int ind;
	for (int i = 1; i <= n * m; i++)
		if (a[i] == r)
		{
			ind = i;
			break;
		}
	int x = 0, y = 1;
	int dirx = 0, dx[] = {1, -1}, i = 0;
	while (i != ind)
	{
		x += dx[dirx];
		i++;
		if (i == ind)
			break;
		if (i != 1 && (x == 1 || x == n))
		{
			dirx = dirx == 0? 1 : 0;
			y++;
			i++;
		}
	}
	cout << y << " " << x;
	return 0;
}
