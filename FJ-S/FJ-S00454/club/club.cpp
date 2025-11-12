#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5+5;
int a[N][4];
int dr[4][4] = {
	{0, 0, 0, 0}, 
	{0, 0, 3, 2}, 
	{0, 3, 0, 1}, 
	{0, 2, 1, 0}
};
struct Dif {
	int df;
	short i1, i2;
	int id;
	
	inline bool operator < (const Dif& dif) const
	{
		return this->df < dif.df;
	}
} d[N];
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t --)
	{
		int n, c1 = 0, c2 = 0, c3 = 0, ans = 0;
		cin >> n;
		int mn = (n >> 1);
		for (int i = 1; i <= n; i ++)
		{
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			if (a[i][1] >= a[i][2] && a[i][1] >= a[i][3])
			{
				++ c1;
				ans += a[i][1];
				d[i] = {a[i][1] - max(a[i][2], a[i][3]), 1, (a[i][2] > a[i][3] ? 2 : 3), i};
			}
			else if (a[i][2] >= a[i][1] && a[i][2] >= a[i][3])
			{
				++ c2;
				ans += a[i][2];
				d[i] = {a[i][2] - max(a[i][1], a[i][3]), 2, (a[i][1] > a[i][3] ? 1 : 3), i};
			}
			else
			{
				++ c3;
				ans += a[i][3];
				d[i] = {a[i][3] - max(a[i][2], a[i][1]), 3, (a[i][2] > a[i][1] ? 2 : 1), i};
			}
		}
		if (c1 <= mn && c2 <= mn && c3 <= mn)
		{
			cout << ans << '\n';
			
			// dif set
			continue;
		}
		sort (d + 1, d + n + 1);
		if (c1 > mn)
		{
			for (int i = 1; i <= n && c1 > mn; i ++)
				if (d[i].i1 == 1)
				{
					-- c1;
					if (d[i].i2 == 2)
						++ c2;
					else ++ c3;
					ans -= d[i].df;
					d[i] = {a[d[i].id][d[i].i2] - a[d[i].id][dr[1][d[i].i2]], d[i].i2, dr[1][d[i].i2], d[i].id};
				}
//			if (c2 <= mn && c3 <= mn)
//			{
//				cout << ans << '\n';
//				continue;
//			}
//			sort (d + 1, d + n + 1);
		}
		else if (c2 > mn)
		{
			for (int i = 1; i <= n && c2 > mn; i ++)
				if (d[i].i1 == 2)
				{
					-- c2;
					if (d[i].i2 == 1)
						++ c1;
					else ++ c3;
					ans -= d[i].df;
					d[i] = {a[d[i].id][d[i].i2] - a[d[i].id][dr[2][d[i].i2]], d[i].i2, dr[2][d[i].i2], d[i].id};
				}
		}
		else
		{
			for (int i = 1; i <= n && c3 > mn; i ++)
				if (d[i].i1 == 3)
				{
					-- c3;
					if (d[i].i2 == 1)
						++ c1;
					else ++ c2;
					ans -= d[i].df;
					d[i] = {a[d[i].id][d[i].i2] - a[d[i].id][dr[3][d[i].i2]], d[i].i2, dr[3][d[i].i2], d[i].id};
				}
		}
		cout << ans << '\n';
	}
	return 0;
}
