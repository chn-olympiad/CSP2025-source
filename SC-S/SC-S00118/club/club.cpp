#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
ll T, n, fl1, fl2;
ll s, mx;
struct node {
	ll a, b, c, u;
} a[100005];
bool cmp1(node x, node y) {
	return x.a > y.a;
}
bool cmp2(node x, node y) {
	return (x.b - x.a) > (y.b - y.a);
}
bool cmp3(node x, node y) {
	return max(x.c - x.a, x.b - x.a) > max(y.c - y.a, y.b - y.a);
}
bool cmp4(node x, node y) {
	return max(x.c - x.b, x.a - x.b) > max(y.c - y.b, y.a - y.b);
}
bool cmp5(node x, node y) {
	return max(x.a - x.c, x.b - x.c) > max(y.a - y.c, y.b - y.c);
}
void dfs(ll x, ll s, ll ca, ll cb, ll cc) {
	if (x == n + 1) {
		mx = max(mx, s);
		return;
	}

	if (ca < n / 2) dfs(x + 1, s + a[x].a, ca + 1, cb, cc);
	if (cb < n / 2) dfs(x + 1, s + a[x].b, ca, cb + 1, cc);
	if (cc < n / 2) dfs(x + 1, s + a[x].c, ca, cb, cc + 1);
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.sync_with_stdio(0);
	cout.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while (T--) {
		cin >> n;
		mx = 0, fl1 = fl2 = 1;
		for (ll i = 1; i <= n; ++i) {
			cin >> a[i].a >> a[i].b >> a[i].c;
			if (a[i].b || a[i].c) fl1 = 0;
			if (a[i].c) {
				fl2 = 0;
			}
		}
		if (fl1) {
			s = 0;
			sort(a + 1, a + n + 1, cmp1);
			for (ll i = 1; i <= n / 2; ++i) s += a[i].a;
			cout << s << "\n";
			continue;
		} else if (fl2) {
			s = 0;
			for (ll i = 1; i <= n; ++i) s += a[i].a, a[i].u = 1;
			sort(a + 1, a + n + 1, cmp2);
			for (ll i = 1; i <= n / 2; ++i) s += (a[i].b - a[i].a), a[i].u = 2;
			cout << s << "\n";
			continue;
		} else if (n <= 10) {
			dfs(1, 0, 0, 0, 0);
			cout << mx << "\n";
		} else {
			mx = 0;
			s = 0;
			int ta = 0, tb = 0, tc = 0;
			for (ll i = 1; i <= n; ++i) s += a[i].a;
			sort(a + 1, a + n + 1, cmp3);
			for (ll i = 1; i <= n; ++i) {
				if (a[i].c - a[i].a > a[i].b - a[i].a && tc < n / 2) {
					s += (a[i].c - a[i].a);
					++tc;
				} else if (a[i].c - a[i].a < a[i].b - a[i].a && tb < n / 2) {
					s += (a[i].b - a[i].a);
					++tb;
				} else if (tc < n / 2) {
					s += (a[i].c - a[i].a);
					++tc;
				} else if (tb < n / 2) {
					s += (a[i].b - a[i].a);
					++tb;
				} else {
					break;
				}
				if (i >= n / 2) {
					mx = max(mx, s);
				}
			}

			s = 0;
			ta = 0, tb = 0, tc = 0;
			for (ll i = 1; i <= n; ++i) s += a[i].b;
			sort(a + 1, a + n + 1, cmp4);
			for (ll i = 1; i <= n; ++i) {
				if (a[i].a - a[i].b > a[i].c - a[i].b && ta < n / 2) {
					s += (a[i].a - a[i].b);
					++ta;
				} else if (a[i].a - a[i].b < a[i].c - a[i].b && tc < n / 2) {
					s += (a[i].c - a[i].b);
					++tc;
				} else if (tc < n / 2) {
					s += (a[i].c - a[i].b);
					++tc;
				} else if (ta < n / 2) {
					s += (a[i].a - a[i].b);
					++ta;
				} else {
					break;
				}
				if (i >= n / 2) {
					mx = max(mx, s);
				}
			}
			mx = max(mx, s);

			s = 0;
			ta = 0, tb = 0, tc = 0;
			for (ll i = 1; i <= n; ++i) s += a[i].c;
			sort(a + 1, a + n + 1, cmp5);
			for (ll i = 1; i <= n; ++i) {
				if (a[i].a - a[i].c > a[i].b - a[i].c && ta < n / 2) {
					s += (a[i].a - a[i].c);
					++ta;
				} else if (a[i].a - a[i].c < a[i].b - a[i].c && tb < n / 2) {
					s += (a[i].b - a[i].c);
					++tb;
				} else if (tb < n / 2) {
					s += (a[i].b - a[i].c);
					++tc;
				} else if (ta < n / 2) {
					s += (a[i].a - a[i].c);
					++ta;
				} else {
					break;
				}
				if (i >= n / 2) {
					mx = max(mx, s);
				}
			}
			mx = max(mx, s);
			cout << mx << "\n";
			continue;
		}
	}
	return 0;
}