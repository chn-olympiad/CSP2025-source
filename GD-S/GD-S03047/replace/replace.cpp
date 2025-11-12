#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define ll long long
#define pii pair<ll, ll>
#define mkpr make_pair
using namespace std;
const ll N = 2e5 + 5, M = 5e6 + 5, bs = 131;
const pii mod = {998244353, 1000000021};
int n, q;
pii p[M];
pair<pii, pii> a[N];
pii operator+ (pii x, ll y) {
	return mkpr(x.first + y, x.second + y);
}
pii operator+ (pii x, pii y) {
	return mkpr(x.first + y.first, x.second + y.second);
}
pii operator- (pii x, pii y) {
	return mkpr(x.first - y.first, x.second - y.second);
}
pii operator* (pii x, ll y) {
	return mkpr(x.first * y, x.second * y);
}
pii operator* (pii x, pii y) {
	return mkpr(x.first * y.first, x.second * y.second);
}
pii operator% (pii x, pii y) {
	return mkpr(x.first % y.first, x.second % y.second);
}
char s[M], s1[M], s2[M], t1[M], t2[M];
pii h1[M], h2[M];
bool B = true;
struct BB {
	ll x, l, r;
	bool operator< (const BB &u) const {
		if (x == u.x) {
			if (l == u.l) return r < u.r;
			return l < u.l;
		}
		return x < u.x;
	}
	bool operator== (const BB &u) const {return x == u.x && l == u.l && r == u.r;}
	BB(ll x_ = 0, ll l_ = 0, ll r_ = 0): x(x_), l(l_), r(r_) {}
} b[N];
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	p[0] = {1, 1};
	for (int i = 1; i <= 5e6; i++) p[i] = p[i - 1] * bs % mod;
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) {
		pii x = {0, 0}, y = {0, 0};
		scanf("%s", s1 + 1);
		for (int j = 1; s1[j]; j++) x = (x * bs % mod + (ll)s1[j]) % mod;
		scanf("%s", s2 + 1);
		for (int j = 1; s2[j]; j++) y = (y * bs % mod + (ll)s2[j]) % mod;
		if (B) {
			int len = strlen(s1 + 1), p1 = 0, p2 = 0;
			for (int j = 1; B && j <= len; j++) {
				if ((s1[j] != 'a' && s1[j] != 'b') || (s2[j] != 'a' && s2[j] != 'b')) {B = false; break;}
				if (s1[j] == 'b') p1 = j;
				if (s2[j] == 'b') p2 = j;
			}
			b[i] = {p2 - p1, min(p1, p2) - 1, len - max(p1, p2)};
		}
		a[i] = {x, y};
	}
	sort(a + 1, a + n + 1);
	if (B) sort(b + 1, b + n + 1);
	if (B) unique(b + 1, b + n + 1);
	n = unique(a + 1, a + n + 1) - a - 1;
	while (q--) {
		scanf("%s%s", t1 + 1, t2 + 1);
		int len = strlen(t1 + 1);
		for (int i = 1; i <= len; i++) h1[i] = (h1[i - 1] * bs % mod + (ll)t1[i]) % mod, h2[i] = (h2[i - 1] * bs % mod + (ll)t2[i]) % mod;
		if (len <= 2000) {
			int l = 0, r = 0;
			for (int i = 1; i <= len; i++) if (t1[i] != t2[i]) {
				if (!l) l = r = i;
				else r = i;
			}
			ll ans = 0;
			for (int u = 1; u <= l; u++) for (int v = r; v <= len; v++) {
				pii x = ((h1[v] - h1[u - 1] * p[v - u + 1] % mod) % mod + mod) % mod;
				pii y = ((h2[v] - h2[u - 1] * p[v - u + 1] % mod) % mod + mod) % mod;
				pair<pii, pii> tg = *lower_bound(a + 1, a + n + 1, mkpr(x, y));
				if (tg == mkpr(x, y)) ans++;
			}
			printf("%lld\n", ans);
		}
		else if (B) {
			int p1 = 0, p2 = 0, l, r, x;
			for (int i = 1; i <= len; i++) {
				if (s1[i] == 'b') p1 = i;
				if (s2[i] == 'b') p2 = i;
			}
			l = min(p1, p2) - 1, r = len - max(p1, p2), x = p2 - p1;
			ll ans = 0;
			for (int i = 0; i <= l; i++)
				ans += upper_bound(b + 1, b + n + 1, BB(x, i, r)) - lower_bound(b + 1, b + n + 1, BB(x, i, 0));
			printf("%lld\n", ans);
		}
	}
	return 0;
}
