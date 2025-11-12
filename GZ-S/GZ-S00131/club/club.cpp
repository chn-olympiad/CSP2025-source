//GZ-S00131 贵阳市华师一学校 孙宇宸
#include <bits/stdc++.h>
using namespace std;

namespace skywave {
	using ll = long long;

	constexpr int N = 100100 + 1;
	int a[N][2], f[110][110];

	void solve() {
		int n;
		cin >> n;
		int hf = n >> 1, sm = 0;
		bool A = true, B = true;
		for (int i = 1; i <= n; ++i) {
			int x;
			cin >> a[i][0] >> a[i][1] >> x;
			A &= a[i][1] == 0 && x == 0;
			B &= x == 0;
			sm += x;
			a[i][0] -= x;
			a[i][1] -= x;
		}

		if (n <= 200) {
			for (int i = 0; i <= hf; ++i) {
				for (int j = 0; j <= hf; ++j) {
					f[i][j] = INT_MIN;
				}
			}
			f[0][0] = 0;
			for (int i = 1; i <= n; ++i) {
				for (int j = hf; ~j; --j) {
					for (int k = hf; ~k; --k) {
						if (j && f[j - 1][k] != INT_MIN) {
							f[j][k] = max(f[j][k], f[j - 1][k] + a[i][0]);
						}
						if (k && f[j][k - 1] != INT_MIN) {
							f[j][k] = max(f[j][k], f[j][k - 1] + a[i][1]);
						}
					}
				}
			}
			int ans = INT_MIN;
			for (int i = 0; i <= hf; ++i) {
				for (int j = 0; j <= hf; ++j) if (i + j >= hf) {
					ans = max(ans, f[i][j]);
				}
			}
			cout << ans + sm << '\n';
			return ;
		}
		vector<int> v;
		if (A) {
			for (int i = 1; i <= n; ++i) {
				v.push_back(a[i][0]);
			}
			sort(v.begin(), v.end(), greater<>());
			cout << accumulate(v.begin(), v.begin() + hf, 0) << '\n';
			return ;
		}
		sm = 0;
		for (int i = 1; i <= n; ++i) {
			sm += a[i][1];
			v.push_back(a[i][0] - a[i][1]);
		}
		sort(v.begin(), v.end(), greater<>());
		for (int i = 0; i < hf; ++i) {
			sm += v[i];
		}
		cout << sm << '\n';
	}

	void main() {
		freopen("club.in", "r", stdin);
		freopen("club.out", "w", stdout);

		ios::sync_with_stdio(false);
		cin.tie(nullptr);

		int t;
		cin >> t;
		while (t--) {
			solve();
		}
	}
}

int main() {
	skywave::main();
	return 0;
}
