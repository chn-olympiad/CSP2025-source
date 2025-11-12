#include <bits/stdc++.h>

using namespace std;

#define lowbit(x) ((x) & -(x))
template<typename T> void chk_min(T &x, const T &y) { x = min(x, y); }
template<typename T> void chk_max(T &x, const T &y) { x = max(x, y); }
typedef pair<int, int> pii;
typedef long long ll;
const int N = 1e5 + 5;

int T, n, a[N][3], pos[N], cnt[3];
ll ans;
vector<int> d;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while (T--) {
		cin >> n, ans = cnt[0] = cnt[1] = cnt[2] = 0;
		for (int i = 1; i <= n; ++i) {
			int mx = 0;
			for (int j = 0; j < 3; ++j) cin >> a[i][j], chk_max(mx, a[i][j]);
			for (int j = 0; j < 3; ++j) if (mx == a[i][j]) { ans += a[i][pos[i] = j], ++cnt[j]; break; }
		}
		int p = -1;
		for (int i = 0; i < 3; ++i) if (cnt[i] > n >> 1) { p = i; break; }
		if (p == -1) { cout << ans << '\n'; continue; }
		d.clear(), d.reserve(n);
		for (int i = 1; i <= n; ++i) if (pos[i] == p) {
			int mx = 0;
			for (int j = 0; j < 3; ++j) if (j ^ pos[i]) chk_max(mx, a[i][j]);
			d.push_back(a[i][pos[i]] - mx);
		}
		sort(d.begin(), d.end());
		int i = 0;
		while (cnt[p] > n >> 1) --cnt[p], ans -= d[i++];
		cout << ans << '\n';
	}
	return 0;
} 
