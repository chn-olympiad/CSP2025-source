#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int n, m;
struct Node
{
	int id, cnt;
}a[1001];
bool cmp(Node x, Node y)
{
	return x.cnt > y.cnt;
}
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)
	{
		cin >> a[i].cnt;
	}
	a[1].id = 1;
	sort(a + 1, a + n * m + 1, cmp);
	int x = 1, y = 1;
	for (int i = 1; i <= n * m; i++)
	{
		if (a[i].id == 1)
		{
			cout << x << " " << y;
			return 0;
		}
		if (x % 2 == 1 && y < n)
		{
			y++;
		}
		else if (x % 2 == 0 && y > 1)
		{
			y--;
		}
		else if (x % 2 == 1 && y == n)
		{
			x++;
		}
		else if (x % 2 == 0 && y == 1)
		{
			x++;
		}
	}
	return 0;
}
