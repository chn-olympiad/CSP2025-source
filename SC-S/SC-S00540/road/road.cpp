#include<bits/stdc++.h>
#define ll long long
#define str string
#define db double
using namespace std;
inline void read(ll & x) {
	x = 0;
	ll f = 1;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		x = (x << 1) + (x << 3) + (c ^ 48);
		c = getchar();
	}
	x *= f;
}
constexpr ll MAXN = 1e6 + 5;
ll n, m, k, top, ans = 1e18, add, fa[MAXN / 10 + 5];
class edge {
public:
	ll u, v, w;
	inline bool operator<(const edge & x)const {
		return w < x.w;
	}
} E[MAXN], may[MAXN * 2];
class city {
public:
	ll chg, road[MAXN / 10 + 5];
} hl[12];
vector<ll> vec;
inline ll find(ll x) {
	if (fa[x] == x) return x;
	return (fa[x] = find(fa[x]));
}
inline void work() {
	ll mst = 0, cnt = 0;
	for (const ll & v : vec)
		mst += hl[v].chg, add++;
	for (ll i = 1; i <= n + add; ++i) fa[i] = i;
	sort(may + 1, may + top + 1);
	for (ll i = 1; i <= top; ++i) {
		ll x = find(may[i].u), y = find(may[i].v);
		if (x == y) continue;
		fa[x] = y, mst += may[i].w, cnt++;
		if (mst > ans) break;
		if (cnt == n + add - 1) break;
	}
	add -= vec.size(), ans = min(ans, mst);
}
inline void dfs(ll now) {
	if (now == k + 1) {
		for (ll i = 1; i <= m; ++i) may[i] = E[i];
		top = m;
		ll cnt = 0;
		for (const ll & v : vec) {
			++cnt;
			for (ll i = 1; i <= n; ++i)
				may[++top] = {n + cnt, i, hl[v].road[i]};
		}
		work();
		return;
	}
	vec.emplace_back(now), dfs(now + 1), vec.pop_back(), dfs(now + 1);
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	read(n), read(m), read(k);
	for (ll i = 1; i <= m; ++i)
		read(E[i].u), read(E[i].v), read(E[i].w);
	if (k == 0) {
		ll cnt = 0;
		for (ll i = 1; i <= n; ++i) fa[i] = i;
		sort(E + 1, E + m + 1);
		for (ll i = 1; i <= m; ++i) {
			ll x = find(E[i].u), y = find(E[i].v);
			if (x == y) continue;
			fa[x] = y, cnt++, ans += E[i].w;
			if (cnt == n - 1) break;
		}
		cout << ans << '\n';
		return 0;
	}
	for (ll i = 1; i <= k; ++i) {
		read(hl[i].chg);
		if (hl[i].chg == 0) {
			ll w;
			k--, i--, add++;
			for (ll j = 1; j <= n; ++j)
				read(w), E[++m] = {n + add, j, w};
			continue;
		}
		for (ll j = 1; j <= n; ++j) read(hl[i].road[j]);
	}
	dfs(1);
	cout << ans << '\n';
	return 0;
}