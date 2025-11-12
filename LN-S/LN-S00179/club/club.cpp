#include<bits/stdc++.h>
//#define int long long
#define rep(a,b,c) for(int a=b;a<=c;a++)
#define dep(a,b,c) for(int a=b;a>=c;a--)
#define pb push_back
using namespace std;
const int N = 1e5+10;

int T, n, c1, c2, c3, ans, cnt;
struct Q
{
	int x, y, z, mx;
}a[N];
struct F
{
	int id, del;
	bool operator< (const F &a) const
	{
		return del < a.del;
	}
}f[N];

signed main()
{
	freopen("club.in", "r", stdin);freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> T;
	while (T --)
	{
		ans = c1 = c2 = c3 = cnt = 0;
		cin >> n;
		rep(i, 1, n)
		{
			cin >> a[i].x >> a[i].y >> a[i].z;
			int x = a[i].x, y = a[i].y, z = a[i].z;
			int mx = max(max(x, y), z);
			a[i].mx = mx;
			if (mx == x) c1++;
			else if (mx == y) c2 ++;
			else c3 ++;
			ans += mx;
		}
		if (c1 <= n / 2 && c2 <= n / 2 && c3 <= n / 2)
		{
			cout << ans << endl;
			continue;
		}
		if (c1 > n / 2)
		{
			int de = c1 - n / 2;
			rep(i, 1, n)
			{
				if (a[i].mx != a[i].x) continue;
				f[++ cnt].id = i, f[cnt].del = min(a[i].x - a[i].y, a[i].x - a[i].z);
			}
			sort(f + 1, f + cnt + 1);
			rep(i, 1, de) ans -= f[i].del;
			cout << ans << endl;
			continue;
		}
		if (c2 > n / 2)
		{
			int de = c2 - n / 2;
			rep(i, 1, n)
			{
				if (a[i].mx != a[i].y) continue;
				f[++ cnt].id = i, f[cnt].del = min(a[i].y - a[i].x, a[i].y - a[i].z);
			}
			sort(f + 1, f + cnt + 1);
			rep(i, 1, de) ans -= f[i].del;
			cout << ans << endl;
			continue;
		}
		if (c3 > n / 2)
		{
			int de = c3 - n / 2;
			rep(i, 1, n)
			{
				if (a[i].mx != a[i].z) continue;
				f[++ cnt].id = i, f[cnt].del = min(a[i].z - a[i].y, a[i].z - a[i].x);
			}
			sort(f + 1, f + cnt + 1);
			rep(i, 1, de) ans -= f[i].del;
			cout << ans << endl;
			continue;
		}
	}
	return 0;
}
//Ren5Jie4Di4Ling5%
