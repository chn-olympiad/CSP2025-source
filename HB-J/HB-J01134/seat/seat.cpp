/*
#include <bits/stdc++.h>
using namespace std;

int n = 2, m = 2, x = 1, y = 1;

int main()
{
    // 蛇形分配
	while (1)
	{
		cout << y << " " << x << endl;
		if (x == 1)
		{
			for (int i = 1; i < n; i++)
			{
				x++;
				cout << y << " " << x << endl;
			}
			if (y + 1 <= m)
				y++;
			else
				break;
		}
		else if (x == n)
		{
			for (int i = n; i > 1; i--)
			{
				x--;
				cout << y << " " << x << endl;
			}
			if (y + 1 <= m)
				y++;
			else
				break;
		}
	}
}
*/

#include <bits/stdc++.h>
using namespace std;

int n, m, a[105], r, id, cnt = 1, x = 1, y = 1;

bool cmp(int a, int b)
{
	return a > b;
}

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)
		cin >> a[i];
	r = a[1];
	sort(a + 1, a + n * m + 1, cmp);
	for (int i = 1; i <= n * m; i++)
	{
		if (a[i] == r)
			id = i;
	}
	while (1)
	{
		if (x == 1)
		{
			for (int i = 1; i < n; i++)
			{
				x++;
				cnt++;
				if (cnt == id)
				{
					cout << y << " " << x << endl;
					return 0;
				}
			}
			if (y + 1 <= m)
			{
				y++;
				cnt++;
				if (cnt == id)
				{
					cout << y << " " << x << endl;
					return 0;
				}
			}
			else
				break;
		}
		else if (x == n)
		{
			for (int i = n; i > 1; i--)
			{
				x--;
				cnt++;
				if (cnt == id)
				{
					cout << y << " " << x << endl;
					return 0;
				}
			}
			if (y + 1 <= m)
			{
				y++;
				cnt++;
				if (cnt == id)
				{
					cout << y << " " << x << endl;
					return 0;
				}
			}
			else
				break;
		}
	}
	return 0;
}
