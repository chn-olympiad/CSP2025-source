#include<bits/stdc++.h>
#define ll long long
#define str string
#define db double
using namespace std;
constexpr ll MAXN = 2e5+5;
ll n, q, ans;
str t1, t2;
pair<str, str> a[MAXN];
inline void work() {
	for (ll i = 1; i <= n; ++i) {
		ll st = t1.find(a[i].first), ed = 0;
		while (st != -1) {
			ed = st + a[i].second.size();
			str cp = t1;
			for (ll j = st; j < ed; ++j) cp[j] = a[i].second[j - st];
			if (cp == t2) ans++;
			st = t1.find(a[i].first, st + 1);
		}
	}
}
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	cin >> n >> q;
	for (ll i = 1; i <= n; ++i) cin >> a[i].first >> a[i].second;
	while (q--) {
		cin >> t1 >> t2;
		ans = 0, work();
		cout << ans << '\n';
	}
	return 0;
}