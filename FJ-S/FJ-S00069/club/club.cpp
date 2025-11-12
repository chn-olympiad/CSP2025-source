#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
int t, n, ans;
struct Club{
	int p1, p2, p3, maxx, max_id, s_maxx, s_id;
}a[MAXN];
bool cmp(Club x, Club y)
{
	if (x.maxx - x.s_maxx == y.maxx - y.s_maxx)
		return x.maxx > y.maxx;
	return x.maxx - x.s_maxx > y.maxx - y.s_maxx;
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> t;
	while (t --)
	{
		ans = 0;
		cin >> n;
		for (int i = 1; i <= n; i ++)
		{
			cin >> a[i].p1 >> a[i].p2 >> a[i].p3;
			if (a[i].p1 >= a[i].p2 && a[i].p2 >= a[i].p3)
				{ a[i].maxx = a[i].p1; a[i].max_id = 1; a[i].s_maxx = a[i].p2; a[i].s_id = 2; }
			if (a[i].p1 >= a[i].p3 && a[i].p3 >= a[i].p2)
				{ a[i].maxx = a[i].p1; a[i].max_id = 1; a[i].s_maxx = a[i].p3; a[i].s_id = 3; }
			if (a[i].p2 >= a[i].p1 && a[i].p1 >= a[i].p3)
				{ a[i].maxx = a[i].p2; a[i].max_id = 2; a[i].s_maxx = a[i].p1; a[i].s_id = 1; }
			if (a[i].p2 >= a[i].p3 && a[i].p3 >= a[i].p1)
				{ a[i].maxx = a[i].p2; a[i].max_id = 2; a[i].s_maxx = a[i].p3; a[i].s_id = 3; }
			if (a[i].p3 >= a[i].p1 && a[i].p1 >= a[i].p2)
				{ a[i].maxx = a[i].p3; a[i].max_id = 3; a[i].s_maxx = a[i].p1; a[i].s_id = 1; }
			if (a[i].p3 >= a[i].p2 && a[i].p2 >= a[i].p1)
				{ a[i].maxx = a[i].p3; a[i].max_id = 3; a[i].s_maxx = a[i].p2; a[i].s_id = 2; }
		}
		sort(a + 1, a + n + 1, cmp);
		int cnt[4] = {0, 0, 0, 0};
		for (int i = 1; i <= n; i ++)
		{
			if (cnt[a[i].max_id] < n/2)
				{ ans += a[i].maxx; cnt[a[i].max_id] ++; }
			else
			{
				ans += a[i].s_maxx; cnt[a[i].s_id] ++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
