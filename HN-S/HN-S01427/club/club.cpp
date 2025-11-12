#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int T, n, a[N][3], id[N][3], cnt[3];

void Solve() {
	cin >> n, cnt[0] = cnt[1] = cnt[2] = 0;
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < 3; ++j) {
			cin >> a[i][j];
			id[i][j] = j;
		}
		sort(id[i], id[i] + 3, [&](int x, int y) { return a[i][x] > a[i][y]; });
		ans += a[i][id[i][0]], cnt[id[i][0]]++;
	}
	int x = -1;
	for (int i = 0; i < 3; ++i) {
		if (cnt[i] > n / 2) {
			x = i;
			break;
		}
	}
	if (x == -1) {
		cout << ans << '\n';
		return;
	}
	vector<int> v;
	for (int i = 1; i <= n; ++i) {
		if (id[i][0] == x) {
			v.emplace_back(a[i][x] - a[i][id[i][1]]);
		}
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < cnt[x] - n / 2; ++i) {
		ans -= v[i];
	}
	cout << ans << '\n';
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> T;
	while (T--) {
		Solve();
	}
	return 0;
}