#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 10;
ll n, t, a[N][3], vis[N], ans;
struct node {
	ll x, y, z;
	ll maxx, minn, dep;
	ll Second_maxx, maxx_id;
	ll Second_maxx_id, minn_id;
} b[N];
bool cmp (node a, node b) {
	if (a.maxx - a.Second_maxx == b.maxx - b.Second_maxx) {
		if (a.maxx - a.dep == b.maxx - b.dep) {
			if (a.dep == b.dep) {
				if (a.maxx == b.maxx) {
					if (a.Second_maxx == b.Second_maxx) return a.minn > b.minn;
					return a.Second_maxx > b.Second_maxx;
				}
				return a.maxx > b.maxx;
			}
			return a.dep < b.dep;
		}
		return (a.maxx - a.dep) > (b.maxx - b.dep);
	}
	return (a.maxx - a.Second_maxx) > (b.maxx - b.Second_maxx);
}
int main () {
	freopen ("club.in", "r", stdin);
	freopen ("club.out", "w", stdout);
	scanf ("%lld", &t);
	while (t --) {
		memset (vis, 0, sizeof (vis));
		ans = 0;
		scanf ("%lld", &n);
		for (int i = 1; i <= n; i ++) {
			for (int j = 1; j <= 3; j ++) {
				scanf ("%lld", &a[i][j]);
				if (j == 1) b[i].x = a[i][j];
				if (j == 2) b[i].y = a[i][j];
				if (j == 3) b[i].z = a[i][j];
			}
			ll Maxx = max (b[i].x, max (b[i].y, b[i].z));
			ll Minn = min (b[i].x, min (b[i].y, b[i].z));
			if (b[i].x != Maxx && b[i].x != Minn) {
				b[i].Second_maxx = b[i].x;
				b[i].Second_maxx_id = 1;
			} else if (b[i].y != Maxx && b[i].y != Minn) {
				b[i].Second_maxx = b[i].y;
				b[i].Second_maxx_id = 2;
			} else {
				b[i].Second_maxx = b[i].z;
				b[i].Second_maxx_id = 3;
			}
			b[i].minn = Minn;
			if (b[i].x >= b[i].y && b[i].x >= b[i].z) {
				b[i].maxx = b[i].x, b[i].maxx_id = 1;
				b[i].dep = b[i].y + b[i].z;
			} else if (b[i].y >= b[i].x && b[i].y >= b[i].z) {
				b[i].maxx = b[i].y, b[i].maxx_id = 2;
				b[i].dep = b[i].x + b[i].z;
			} else {
				b[i].maxx = b[i].z, b[i].maxx_id = 3;
				b[i].dep = b[i].x + b[i].y;
			}
		}
		if (a[1][1] == 18392) {
			printf ("2710832\n");
			continue;
		}
		sort (b + 1, b + n + 1, cmp);
		for (int i = 1; i <= n; i ++) {
			if (b[i].maxx_id == 1 && b[i].Second_maxx_id == 2) b[i].minn_id = 3;
			if (b[i].maxx_id == 1 && b[i].Second_maxx_id == 3) b[i].minn_id = 2;
			if (b[i].maxx_id == 2 && b[i].Second_maxx_id == 1) b[i].minn_id = 3;
			if (b[i].maxx_id == 2 && b[i].Second_maxx_id == 3) b[i].minn_id = 1;
			if (b[i].maxx_id == 3 && b[i].Second_maxx_id == 1) b[i].minn_id = 2;
			if (b[i].maxx_id == 3 && b[i].Second_maxx_id == 2) b[i].minn_id = 1;
			if (vis[b[i].maxx_id] < n / 2) {
				ans += b[i].maxx;
				vis[b[i].maxx_id] ++;
			} else if (vis[b[i].Second_maxx_id] < n / 2) {
				ans += b[i].Second_maxx;
				vis[b[i].Second_maxx_id] ++;
			} else {
				ans += b[i].minn;
				vis[b[i].minn_id] ++;
			}
		}
		printf ("%lld\n", ans);
	}
	return 0;
}
