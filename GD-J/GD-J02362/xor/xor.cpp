#include <bits/stdc++.h>
using namespace std;
bool cmp(pair <int, int> x, pair <int, int> y) {
	if (x.second != y.second)return x.second < y.second;
	return x.first < y.first;
}
signed main() {
	freopen("xor5.in", "r", stdin);
//	freopen("xor.out", "w", stdout);
	int n, k;
	scanf("%d%d", &n, &k);
	vector <int> a(n + 1);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	vector <int> xp (n + 1);
	xp[0] = 0;
	for (int i = 1; i <= n; i++) xp[i] = xp[i - 1] xor a[i];
	map <int, set <int> > m;
	for (int i = 0; i <= n; i++) m[xp[i]].insert(i);
	int ans = 0;
	vector <pair <int, int> > kl;
	for (int i = 0; i <= n; i++) {
		int ps = xp[i] xor k;
		m[xp[i]].erase(i);
		if (m[ps].empty()) {
			continue;
		}
		for (auto p : m[ps]) {
			kl.push_back({i + 1, p});
		}
	}
	sort (kl.begin(), kl.end(), cmp);
	int en = kl[0].second; ans = 1;
	for (int i = 1; i < kl.size(); i++) {
		if (kl[i].first > en) {
			en = kl[i].second;
			ans++;
		}
	}
	cout << ans;
	return 0;
}
