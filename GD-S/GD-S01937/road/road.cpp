#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, m, k, c[11], fa[20100], b[11], g[11];
ll ans, mx = 0;
struct hies {
	ll u, v, len;
	hies(ll x, ll y, ll z) {
		len = z, u = x, v = y;
	}
};
vector<hies> edge;

ll find(ll x) {
	if (fa[x] == x)
		return x;
	return fa[x] = find(fa[x]);
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%lld%lld%lld", &n, &m, &k);
	for (ll i = 1; i <= n + k; i++)
		fa[i] = i;
	for (ll i = 1; i <= m; i++) {
		ll u, v, w;
		scanf("%lld%lld%lld", &u, &v, &w);
		edge.push_back(hies(u, v, w));
	}
	if (k == 0) {
		sort(edge.begin(), edge.end(), [&](const hies &a, const hies &b) {
			return a.len < b.len;
		});
		for (auto i : edge) {
			ll x = find(i.u), y = find(i.v);
			if (x != y) {
				fa[fa[i.v]] = i.u;
				ans += i.len;
			}
		}
		printf("%lld\n", ans);
		return 0;
	}
	for (ll i = 1; i <= k; i++) {
		scanf("%lld", &c[i]);
		mx = max(mx, c[i]);
		for (ll j = 1; j <= n; j++) {
			ll a;
			scanf("%lld", &a);
			mx = max(mx, a);
			edge.push_back(hies(j, n + i, a + c[i]));
		}
	}
	if (mx == 0) {
		puts("0");
		return 0;
	}
	sort(edge.begin(), edge.end(), [&](const hies &a, const hies &b) {
		return a.len < b.len;
	});
	for (auto i : edge) {
		ll x = find(i.u), y = find(i.v);
		if (x != y) {
			fa[fa[i.v]] = i.u;
			ans += i.len;
			if (i.v > n) 
				b[i.v - n]++, g[i.v - n] += i.len;
		}
	}
	for (ll i = 1; i <= k; i++)
		if (b[i] > 1)
			ans += (b[i] - 1) * c[i];
		else
			ans -= g[i];
	printf("%lld\n", ans);
}