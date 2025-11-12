#include <bits/stdc++.h>
#define ll long long
#define pi pair<ll, ll>
#define fre(c) freopen(c".in", "r", stdin); freopen(c".out", "w", stdout);
using namespace std;
const ll N = 1e6 + 5;
const ll inf = 0x3f3f3f3f;
ll n, m, k, fa[N], ans, sum = inf, mn;
set<ll> st[N]; 
ll find(ll x) {
	return fa[x] = (fa[x] == x ? x : find(fa[x]));
}
struct node {
	ll u, v, w;
}e[N];
struct edge {
	ll mar, s, a[N];
}o[N];
bool cmp(node x, node y) {
	return x.w < y.w;
}
bool c(edge x, edge y) {
	return x.s < y.s;
}
int main() {
	fre("road");
	cin >> n >> m >> k;
	for(ll i = 1; i <= n; i++) fa[i] = i;
	for(ll i = 1; i <= m; i++) cin >> e[i].u >> e[i].v >> e[i].w;
	for(ll i = 1; i <= k; i++) {
		cin >> o[i].mar;
		for(ll j = 1; j <= n; j++) {
			cin >> o[i].a[j];
			o[i].s += o[i].a[j];
		}
	}
	sort(o + 1, o + k + 1, c);
	ans += o[1].mar;
 	sort(e + 1, e + n + 1, cmp);
	for(ll i = 1; i <= m; i++) {
		ll fu = find(e[i].u);
		ll fv = find(e[i].v);
		if(fu != fv) ans += e[i].w, fa[fu] = fv;
		ll last = ans;
		st[fv].insert(e[i].u); st[fv].insert(e[i].v);
		for(ll j = 1; j <= n; j++) {
			mn = inf;
			for(auto q : st[i]) 
				mn = min(mn, 1LL * o[1].a[q]);
			ans += mn;
		}
		sum = min(sum, ans);
		ans = last;
	}
	cout << sum << endl;
	return 0;
}
