#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e5 + 10;
struct node {
	ll x, y, z;
	int xx, b, c, d;
} a[maxn];
ll m;
int tt, n, x, y, z;
bool cmp(node xa, node ya) {
	if (xa.xx == ya.xx) return xa.c < ya.c;
	return xa.xx < ya.xx;
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &tt);
	while (tt--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%lld%lld%lld", &a[i].x, &a[i].y, &a[i].z);
		for (int i = 1; i <= n; i++) {
			m = max(a[i].x, max(a[i].y, a[i].z));
			if (a[i].x == m) {
				x++;
				a[i].b = 1;
			}
			else if (a[i].y == m) {
				y++;
				a[i].b = 2;
			}
			else if (a[i].z == m) {
				z++;
				a[i].b = 3;
			}
		}
		if (x * 2 > n) {
			for (int i = 1; i <= n; i++) {
				if (a[i].x == a[i].y) {
					x--;
					y++;
					a[i].b = 2;
					if (x * 2 <= n) break;
				}
				else if (a[i].x == a[i].z) {
					x--;
					z++;
					a[i].b = 3;
					if (x * 2 <= n) break;
				}
			}
			if (x * 2 > n) {
				for (int i = 1; i <= n; i++) {
					if (a[i].b == 1) a[i].xx = -1;
					else a[i].xx = 0;
				}
				for (int i = 1; i <= n; i++) {
					if (a[i].y > a[i].z) {
						a[i].c = a[i].x - a[i].y;
						a[i].d = 2;
					}
					else {
						a[i].c = a[i].x - a[i].z;
						a[i].d = 3;
					}
				}
				sort(a + 1, a + n + 1, cmp);
				int t = x - n / 2;
				for (int i = 1; i <= t; i++) a[i].b = a[i].d;
			}
		}
		else if (y * 2 > n) {
			for (int i = 1; i <= n; i++) {
				if (a[i].x == a[i].y) {
					x++;
					y--;
					a[i].b = 1;
					if (y * 2 <= n) break;
				}
				else if (a[i].y == a[i].z) {
					y--;
					z++;
					a[i].b = 3;
					if (y * 2 <= n) break;
				}
			}
			if (y * 2 > n) {
				for (int i = 1; i <= n; i++) {
					if (a[i].b == 2) a[i].xx = -1;
					else a[i].xx = 0;
				}
				for (int i = 1; i <= n; i++) {
					if (a[i].x > a[i].z) {
						a[i].c = a[i].y - a[i].x;
						a[i].d = 1;
					}
					else {
						a[i].c = a[i].y - a[i].z;
						a[i].d = 3;
					}
				}
				sort(a + 1, a + n + 1, cmp);
				int t = y - n / 2;
				for (int i = 1; i <= t; i++) a[i].b = a[i].d;
			}
		}
		else if (z * 2 > n) {
			for (int i = 1; i <= n; i++) {
				if (a[i].x == a[i].z) {
					x++;
					z--;
					a[i].b = 1;
					if (z * 2 <= n) break;
				}
				else if (a[i].y == a[i].z) {
					z--;
					y++;
					a[i].b = 2;
					if (z * 2 <= n) break;
				}
			}
			if (z * 2 > n) {
				for (int i = 1; i <= n; i++) {
					if (a[i].b == 3) a[i].xx = -1;
					else a[i].xx = 0;
				}
				for (int i = 1; i <= n; i++) {
					if (a[i].y > a[i].x) {
						a[i].c = a[i].z - a[i].y;
						a[i].d = 2;
					}
					else {
						a[i].c = a[i].z - a[i].x;
						a[i].d = 1;
					}
				}
				sort(a + 1, a + n + 1, cmp);
				int t = z - n / 2;
				for (int i = 1; i <= t; i++) a[i].b = a[i].d;
			}
		}
		ll ans = 0;
		for (int i = 1; i <= n; i++) {
			if (a[i].b == 1) ans += a[i].x;
			if (a[i].b == 2) ans += a[i].y;
			if (a[i].b == 3) ans += a[i].z;
		}
		printf("%lld\n", ans);
		for (int i = 1; i <= n; i++) {
			a[i].x = a[i].y = a[i].z = a[i].xx = a[i].b = a[i].c = a[i].d = 0;
			x = y = z = m = 0;
		}
	}
	return 0;
}
