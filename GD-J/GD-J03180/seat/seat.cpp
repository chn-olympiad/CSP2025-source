#include <bits/stdc++.h>
using namespace std;
int n, m, a[105], x = 1, y = 1, R;
bool down = true;
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)
	{
		cin >> a[i];
	}
	R = a[1];
	sort(a + 1, a + n * m + 1, greater<int>());
	for (int i = 1; i <= n * m; i++)
	{
		if (a[i] == R)
		{
			cout << y << " " << x << endl;
			return 0;
		}
		if (down && x != n)
		{
			x++;
		}
		else if (down && x == n)
		{
			y++;
			down = false;
		}
		else if (!down && x != 1)
		{
			x--;
		}
		else if (!down && x == 1)
		{
			y++;
			down = true;
		}
	}
	return 0;
}
/*
1 4
3 2 4 1

2 1
*/

/*
5 1
4 2 3 1 5

1 2
*/
