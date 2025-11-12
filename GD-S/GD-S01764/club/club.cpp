#include <bits/stdc++.h>
#define int long long
#define r(x) for (int i = 1; i <= x; i++)
#define rep(i, a, b) for (int i = a; i <= b; i++)
using namespace std;

const int N = 2e5 + 50;
int t, n, a[N][4], flag[N], dif[N];
int c1, c2, c3, s1, s2, s3, cnt;

signed main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin >> t;
	while (t--)
	{
		cin >> n; int p = n / 2;
		s1 = s2 = s3 = c1 = c2 = c3 = 0;
		memset(flag, 0, sizeof flag);
		r(n) 
		{
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			if (a[i][1] >= a[i][2] && a[i][1] >= a[i][3])
				s1 += a[i][1], c1++, flag[i] = 1;
			else if (a[i][2] >= a[i][1] && a[i][2] >= a[i][3])
				s2 += a[i][2], c2++, flag[i] = 2;
			else if (a[i][3] >= a[i][1] && a[i][3] >= a[i][2])
				s3 += a[i][3], c3++, flag[i] = 3;
		}
		if (c1 <= p && c2 <= p && c3 <= p)
		{
			cout << s1 + s2 + s3 << "\n";
			continue;
		}
		if (c2 > p)
		{
			r(n) swap(a[i][1], a[i][2]);
			r(n)
			{
				if (flag[i] == 1) flag[i] = 2;
				if (flag[i] == 2) flag[i] = 1;
			}
			swap(s1, s2), swap(c1, c2);
		}
		else if (c3 > p)
		{
			r(n) swap(a[i][1], a[i][3]);
			r(n)
			{
				if (flag[i] == 1) flag[i] = 3;
				if (flag[i] == 3) flag[i] = 1;
			}
			swap(s1, s3), swap(c1, c3);
		}
		int k = c1 - p, ans = s1 + s2 + s3;
		r(n)
		{
			if (flag[i] == 1) 
				k--, dif[++cnt] = min(a[i][1] - a[i][2], a[i][1] - a[i][3]);
		}
		sort(dif + 1, dif + cnt + 1);
		r(c1 - p) ans -= dif[i];
		cout << ans << "\n";
	}
	return 0;
}
