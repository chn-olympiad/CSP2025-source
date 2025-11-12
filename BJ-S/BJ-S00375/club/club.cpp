#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n;
int a[N][4];
int d[N], dlt[N];
int cnt[4];

void solve() {
	cin >> n; cnt[1] = cnt[2] = cnt[3] = 0;
	
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		int f = 0, s = 0;
		for (int j = 1; j <= 3; ++j) {
			cin >> a[i][j];
			if (a[i][j] > f) s = f, f = a[i][j], d[i] = j;
			else s = max(s, a[i][j]);
		}
		dlt[i] = f - s;
		cnt[d[i]]++;
		ans += f;
	}
	
	for (int j = 1; j <= 3; ++j) if (cnt[j] > n / 2) {
		vector<int> v;
		for (int i = 1; i <= n; ++i) if (d[i] == j) v.emplace_back(dlt[i]);
		sort(v.begin(), v.end());
		for (int i = 0; i < cnt[j] - n / 2; ++i) ans -= v[i];
	}
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);

	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}