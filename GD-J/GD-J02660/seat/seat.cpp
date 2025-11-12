#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
int a[105];
int temp, rk, cnt, r, c;
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1, to = n * m; i <= to; i++)
		cin >> a[i];
	temp = a[1];
	sort(a + 1, a + n * m + 1, greater<int>());
	for (int i = 1, to = n * m; i <= to; i++)
		if (a[i] == temp)
		{
			rk = i;
			break;
		}
	bool flag = false;
	for (int i = 1; i <= m; i++)
	{
		if (i & 1)
		{
			for (int j = 1; j <= n; j++)
			{
				cnt++;
				if (cnt == rk)
				{
					r = j, c = i;
					flag = true;
					break;
				}
			}
			if (flag)
				break;
		}
		else
		{
			for (int j = n; j >= 1; j--)
			{
				cnt++;
				if (cnt == rk)
				{
					r = j, c = i;
					flag = true;
					break;
				}
			}
			if (flag)
				break;
		}
	}
	cout << c << ' ' << r;
}
