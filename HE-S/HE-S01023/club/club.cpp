#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 10;
int n, T, a[N][4], ans, f[N], cnt[4], lw[N], num;
signed main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while (T--)
	{
		scanf("%lld", &n);
		ans = num = cnt[1] = cnt[2] = cnt[3] = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= 3; j++)
				scanf("%lld", &a[i][j]);
			f[i] = 1;
			if (a[i][2] > a[i][1])
				f[i] = 2;
			if (a[i][3] > max(a[i][1], a[i][2]))
				f[i] = 3;
			ans += a[i][f[i]], cnt[f[i]]++;
		}
		if (cnt[1] > n / 2)
		{
			for (int i = 1; i <= n; i++)
				if (f[i] == 1)
					lw[++num] = a[i][1] - max(a[i][2], a[i][3]);
			sort(lw + 1, lw + 1 + num);
			for (int i = 1; i <= cnt[1] - n / 2; i++)
				ans -= lw[i];
		}
		if (cnt[2] > n / 2)
		{
			for (int i = 1; i <= n; i++)
				if (f[i] == 2)
					lw[++num] = a[i][2] - max(a[i][1], a[i][3]);
			sort(lw + 1, lw + 1 + num);
			for (int i = 1; i <= cnt[2] - n / 2; i++)
				ans -= lw[i];
		}
		if (cnt[3] > n / 2)
		{
			for (int i = 1; i <= n; i++)
				if (f[i] == 3)
					lw[++num] = a[i][3] - max(a[i][2], a[i][1]);
			sort(lw + 1, lw + 1 + num);
			for (int i = 1; i <= cnt[3] - n / 2; i++)
				ans -= lw[i];
		}
		cout << ans << '\n';
	}
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
