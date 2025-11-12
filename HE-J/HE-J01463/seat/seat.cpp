#include<bits/stdc++.h>
using namespace std;
int n, m;
int a[110];
int x, y;
bool cmp(int x, int y)
{
	return x > y;
}
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	cout.tie(nullptr)->ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)
		cin >> a[i];
	int k = a[1];
	sort(a + 1, a + n * m + 1, cmp);
	x = 0;
	y = 0;
	int r = 1;
	for (int i = 1; i <= n * m; i++)
	{
		x += r;
		if (x == n + 1)
		{
			r = -1;
		}
		if (x == 0)
		{
			r = 1;
		}
		if (i != 1 && (x == n || x == 1))
		{
			y++;
		}
		if (a[i] == k)
		{
			cout << y << " " << x;
			break;
		}
	}
	return 0;
}

