#include <bits/stdc++.h>

#define debug(x) (cout << #x << " " << x << "\n")

using namespace std;

using ll = long long;

const int N = 2e4 + 5, M = 2e6 + 5;

struct Edge {
	ll u, v, w;
} e[M];

ll n, m, k, f[N], c[15], a[15][N];

ll findf(ll i) { return f[i] == i ? i : f[i] = findf(f[i]); }

bool merge(ll x, ll y) {
	x = findf(x), y = findf(y);
	if (x != y) {
		f[x] = y;
		return 1;
	}
	return 0;
}

void solve1() {
	sort(e + 1, e + 1 + m, [&](const Edge &x, const Edge &y) {
		return x.w < y.w;	
	});
	ll sum = 0, ans = 0;
	for (ll i = 1; i <= m; i++) {
		if (sum == n - 1) return cout << ans, void();
		if (merge(e[i].u, e[i].v)) {
			ans += e[i].w;
			++ sum;
		}
	}
}

void solve2() {
	ll cnt = m;
	for (ll i = 1; i <= k; i++) {
		for (ll j = 1; j <= n; j++) {
			++ cnt;
			e[cnt].u = n + i, e[cnt].v = j, e[cnt].w = a[i][j];
		}
	}
	sort(e + 1, e + 1 + cnt, [&](const Edge &x, const Edge &y) {
		return x.w < y.w;	
	});
	ll sum = 0, ans = 0;
	for (ll i = 1; i <= cnt; i++) {
		if (sum == n + k - 1) return cout << ans, void();
		if (merge(e[i].u, e[i].v)) {
			ans += e[i].w;
			++ sum;
		}
	}	
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> k;
	for (ll i = 1; i <= n + k; i++) f[i] = i;
	for (ll i = 1; i <= m; i++) cin >> e[i].u >> e[i].v >> e[i].w;
	if (!k) return solve1(), 0;
	ll flag = 1;
	for (ll i = 1; i <= k; i++) {
		cin >> c[i];
		if (c[i]) flag = 0;
		bool fflag = 0;
		for (ll j = 1; j <= n; j++) {
			cin >> a[i][j];
			if (!a[i][j]) fflag = 1;
		}
		if (!fflag) flag = 0;
	}
	if (flag) return solve2(), 0;
	if (m > 1e5) return solve1(), 0;
	ll mini = 1e18;
	for (ll st = 0; st < (1 << k); st++) {
		ll cnt = m, cntcur = 0, ans = 0;
		for (ll i = 1; i <= k; i++) if ((st >> (i - 1)) & 1) {
			++ cntcur;
			ans += c[i];
			for (ll j = 1; j <= n; j++) {
				++ cnt;
				e[cnt].u = n + i, e[cnt].v = j, e[cnt].w = a[i][j];
			}
		}
		sort(e + 1, e + 1 + cnt, [&](const Edge &x, const Edge &y) {
			return x.w < y.w;	
		});
		for (ll i = 1; i <= n + k; i++) f[i] = i;
		ll sum = 0;
		for (ll i = 1; i <= cnt; i++) {
			if (sum == n + cntcur - 1) {
				mini = min(mini, ans);
				break;
			}
			if (merge(e[i].u, e[i].v)) {
				ans += e[i].w;
				++ sum;
			}
		}
	}
	cout << mini;
	return 0;
}

