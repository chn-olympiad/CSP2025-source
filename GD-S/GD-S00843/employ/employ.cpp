#include <bits/stdc++.h>
using namespace std;

#define int long long
#ifndef LOCAL_TEST
#define endl '\n'
#endif

const int mod = 998244353;
int n, m;

namespace bf {
	int c[20];
	string s;

	void add(int &x, int y) {
		x += y;
		if (x >= mod) x -= mod;
	}

	void work() {
		cin >> s; s = ' ' + s;
		for (int i = 0; i < n; ++i)
			cin >> c[i];
		vector<vector<int>> f(n + 1, vector<int>(1ll << n));
		vector<int> T;
		for (int i = 1; i < (1ll << n); ++i) 
			T.push_back(i);
		sort(T.begin(), T.end(), [](int x, int y) {
			return __builtin_popcountll(x) < __builtin_popcountll(y);
		});
		// cerr << "Sorted" << T.size() << endl;
		f[0][0] = 1;
		for (auto S:T) {
			// cerr << "dp" << S << endl;
			int i = __builtin_popcountll(S); // 当前是第 i 天
			for (int j = 0; j <= i; ++j) { // 有 j 个人失败了
				// cerr << "dp" << S << ' ' << j << endl;
				for (int k = 0; k < n; ++k) {
					if (!(S >> k & 1)) continue;
					// 当前失败
					if (s[i] == '0') {
						if (j > 0) add(f[j][S], f[j - 1][S ^ (1ll << k)]);
					} else {
						// 之前失败 j - 1 次
						if (j > 0 && j - 1 >= c[k]) add(f[j][S], f[j - 1][S ^ (1ll << k)]);
					}
					// 当前成功
					if (s[i] == '1') {
						if (j < c[k]) {
							add(f[j][S], f[j][S ^ (1ll << k)]);
						}
					}
				}
				// cerr << j << ' ' << S << ' ' << f[j][S] << endl;
			}
		}
		int ans = 0;
		for (int i = m; i <= n; ++i) { // i 人成功
			add(ans, f[n - i][(1ll << n) - 1]);
		}
		cout << ans << endl;
	} 
}

void work() {
	cin >> n >> m;
	if (n <= 18) return bf::work();
	if (n == m) {
		string s; cin >> s;
		if (count(s.begin(), s.end(), '0') != 0) return cout << 0 << endl, void();
		vector<int> c(n + 1);
		int ans = 1;
		for (int i = 1; i <= n; ++i) {
			cin >> c[i];
			if (c[i] == 0) return cout << 0 << endl, void();
			ans = ans * i % mod;
		}
		cout << ans << endl;
		return;
	}
}

signed main(void) {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	work();
	return 0;
}
