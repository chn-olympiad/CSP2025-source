#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5 + 5;

int n;
pair <ll, ll> a[N], b[N], c[N];
bool vis[N];

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].first >> b[i].first >> c[i].first;
		a[i].second = b[i].second = c[i].second = i;
	}
	sort(a + 1, a + n + 1);
	sort(b + 1, b + n + 1);
	sort(c + 1, c + n + 1);
	int a_, b_, c_, ans = 0;
	a_ = 0, b_ = 0, c_ = 0;
	set <pair<pair<int, int>,  int> > st;
	for (int i = 1; i <= n; i++) {
		st.insert({a[i], 1});
		st.insert({b[i], 2});
		st.insert({c[i], 3});
	}
	vector <pair<pair<int, int>,  int> > v;
	for (auto it : st) {
		v.push_back(it);
	}
	for (int i = v.size() - 1; i >= 0; i--) {
		auto it = v[i];
		if (vis[it.first.second]) continue;
		if (it.second == 1) {
			if (a_ == n / 2) continue;
			a_++;
		}
		if (it.second == 2) {
			if (b_ == n / 2) continue;
			b_++;
		}
		if (it.second == 3) {
			if (c_ == n / 2) continue;
			c_++;
		}
//		cout << it.first.first << ' ' << it.first.second << ' ' << it.second << '\n';
		vis[it.first.second] = 1;
		ans += it.first.first;
	}
	cout << ans << '\n';
	memset(vis, 0, sizeof vis);
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}
