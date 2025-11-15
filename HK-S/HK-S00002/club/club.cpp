#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
	int n; cin >> n;
	vector<int> a(n+1), b(n+1), c(n+1);
	for (int i = 1; i <= n; i++) cin >> a[i] >> b[i] >> c[i];
	vector<int> v(n+1,0);
	int ma = 0, mb = 0, mc = 0;
	for (int i = 1; i <= n; i++) {
		int m = max({a[i],b[i],c[i]});
		if (a[i] == m) ma++, v[i] = 1;
		else if (b[i] == m) mb++, v[i] = 2;
		else mc++, v[i] = 3;
	}
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		int m = max({a[i],b[i],c[i]});
		ans += m;
	}
	if (ma <= n/2 && mb <= n/2 && mc <= n/2) {
		cout << ans << '\n';
		return;	
	}
	if (ma > n/2) {
		vector<int> diff;
		for (int i = 1; i <= n; i++) if (v[i] == 1) diff.push_back(a[i] - max(b[i],c[i]));
		sort(diff.begin(),diff.end());
		for (int i = 0; i < ma - n/2; i++) ans -= diff[i];
		cout << ans << '\n';
		return;
	}
	else if (mb > n/2) {
		vector<int> diff;
		for (int i = 1; i <= n; i++) if (v[i] == 2) diff.push_back(b[i] - max(a[i],c[i]));
		sort(diff.begin(),diff.end());
		for (int i = 0; i < mb - n/2; i++) ans -= diff[i];
		cout << ans << '\n';
		return;
	}
	else if (mc > n/2) {
		vector<int> diff;
		for (int i = 1; i <= n; i++) if (v[i] == 3) diff.push_back(c[i] - max(a[i],b[i]));
		sort(diff.begin(),diff.end());
		for (int i = 0; i < mc - n/2; i++) ans -= diff[i];
		cout << ans << '\n';
		return;
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t; cin >> t;
	while (t--) solve();
	
	return 0;
	
}
