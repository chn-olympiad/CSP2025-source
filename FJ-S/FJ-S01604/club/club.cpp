#include <bits/stdc++.h>
using namespace std;
int T, a[100005][3], f[100005], b[10005], x, y, z, sum, n, ans;
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while (T--)
	{
		cin >> n;
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		x = 0, y = 0, sum = 0;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i][0] >> a[i][1] >> a[i][2];
			b[i] = max(a[i][0] ,max(a[i][1], a[i][2]));
			if (a[i][1] == 0 && a[i][2] == 0)
			{
				x++;
			}
			if (a[i][2] == 0)
			{
				y++;
			}
		}
		if (x == n)
		{
			sort(b + 1, b + n + 1);
			for (int i = n / 2 + 1; i <= n; i++)
			{
				sum += b[i];
			}
			cout << sum << endl;
		}
		else
		{
			for (int i = 1; i <= n; i++)
			{
				sum += b[i];
			}
			cout << sum << endl;
		}
	}
	return 0;
}
