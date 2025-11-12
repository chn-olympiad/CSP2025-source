#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int t;
struct stu
{
	int x1, x2, x3;	
};
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--)
	{
		int n, max_1, max_2, max_3, x, y, z, e[20005], f[20005], d[20005];
		bool A = true, B = true;
		max_1 = max_2 = max_3 = -1;
		stu a[20005];
		ll ans = 0;
		cin >> n;
		for (int i{1}; i <= n; ++i)
		{
			cin >> a[i].x1 >> a[i].x2 >> a[i].x3;
			d[i] = a[i].x2, f[i] = a[i].x3, e[i] = a[i].x1;
			max_1 = max(max_1, a[i].x1), max_2 = max(max_2, a[i].x2), max_3 = max(max_3, a[i].x3);
			if (a[i].x2 != 0 || a[i].x3 != 0)
				A = false;
			if (a[i].x3 != 0)
				B = false;
		}
		stable_sort(a + 1, a + 1 + n, [](stu a, stu b) -> bool
		{
			if (a.x1 == b.x1)
			{
				if (a.x2 == b.x2)
					return a.x3 > b.x3;
				return a.x2 > b.x2;
			}
			return a.x1 > b.x1;
		});
		if (n == 2)
		{
			int x1 = a[1].x1, x2 = a[1].x2, x3 = a[1].x3;
			int d1 = a[2].x1, d2 = a[2].x2, d3 = a[2].x3;
			int ans1 = x1 + max(d2, d3), ans2, ans3, ans4, ans5;
			ans2 = x2 + max(d1, d3);
			ans3 = x3 + max(d1, d2);
			ans4 = d2 + max(x1, x3);
			ans5 = d3 + max(x1, x2);
			cout << max({ans1, ans2, ans3, ans4, ans5}) << '\n';
			continue;
		}
		if (A)
		{
			for (int i{1}; i <= n / 2; ++i)
			{
				ans += a[i].x1;
			}
			cout << ans << '\n';
			continue;
		}
		else if (B)
		{
			ll s1 = 0, s2 = 0, s3 = 0, s4 = 0;
			for (int i{1}; i <= n / 2; ++i)
			{
				s1 += a[i].x1, s2 += a[i].x2;
			}
			for (int i = n / 2 + 1; i <= n; ++i)
			{
				s3 += a[i].x1, s4 += a[i].x2;
			}
			int ans1 = max(s1 + s4, s2 + s3);
			stable_sort(a + 1, a + 1 + n, [](stu a, stu b) -> bool
			{
				if (a.x2 == b.x2)
				{
					if (a.x1 == b.x1)
						return a.x3 > b.x3;
					return a.x1 > b.x1;
				}
				return a.x2 > b.x2;
			});
			s1 = 0, s2 = 0, s3 = 0, s4 = 0;
			for (int i{1}; i <= n / 2; ++i)
			{
				s1 += a[i].x1, s2 += a[i].x2;
			}
			for (int i = n / 2 + 1; i <= n; ++i)
			{
				s3 += a[i].x1, s4 += a[i].x2;
			}
			int ans2 = max(s1 + s4, s2 + s3);
			cout << max(ans1, ans2) << '\n';
			continue;
		}
		else
		{
			cout << max_1 + max_2 + max_3 << '\n';
		}	
	}
	return 0;
}
