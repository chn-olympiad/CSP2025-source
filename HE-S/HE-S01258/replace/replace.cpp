#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int MAXN = 5e6 + 10;
int n, q;

namespace work1 {
	const int MOD = 1e9 + 7, base = 1145141;
	map<pii, int> cnt;
	void solve() {
		for (int i = 1; i <= n; i++) {
			string s1, s2; cin >> s1 >> s2;
			int l = s1.size();
			s1 = " " + s1; s2 = " " + s2;
			int sum1 = 0, sum2 = 0;
			for (int j = 1; j <= l; j++) {
				sum1 = (1ll * sum1 * base + s1[j]) % MOD;
				sum2 = (1ll * sum2 * base + s2[j]) % MOD;
			}
			// cerr << sum1 << " " << sum2 << endl;
			cnt[{sum1, sum2}]++;
		}

		for (int i = 1; i <= q; i++) {
			string t1, t2;
			cin >> t1 >> t2;
			int l = t1.size();
			t1 = " " + t1; t2 = " " + t2;
			int sum1 = 0, sum2 = 0;
			for (int j = 1; j <= l; j++) {
				sum1 = (1ll * sum1 * base + t1[j]) % MOD;
				sum2 = (1ll * sum2 * base + t2[j]) % MOD;
			}
			int lp = 1; while (t1[lp] == t2[lp]) lp++;
			int rp = l; while (t1[rp] == t2[rp]) rp--;
			int ans = 0;
			for (int j = lp; j >= 1; j--) {
				int s1 = 0, s2 = 0;
				for (int k = j; k < rp; k++) {
					s1 = (1ll * s1 * base + t1[k]) % MOD;
					s2 = (1ll * s2 * base + t2[k]) % MOD;
				}
				for (int k = rp; k <= l; k++) {
					s1 = (1ll * s1 * base + t1[k]) % MOD;
					s2 = (1ll * s2 * base + t2[k]) % MOD;
					// cerr << j << " " << k << " " << s1 << " " << s2 << " " << cnt[{s1, s2}] << endl;
					ans += cnt[{s1, s2}];
				}
			}
			cout << ans << '\n';
		}
	}
}

namespace work2 {
	map<pii, vector<int>> v;
	void solve() {
		for (int i = 1; i <= n; i++) {
			string s1, s2;
			cin >> s1 >> s2;
			int l = s1.size();
			string res = "";
			int b1 = -1, b2 = -1;
			for (int i = 0; i < l; i++) {
				if (s1[i] == 'b' || s2[i] == 'b') {
					res.push_back('b');
					if (b1 == -1) b1 = i;
					else b2 = i;
				}
				else {
					res.push_back('a');
				}
			}
			if (b2 == -1) b2 = b1;
			for (int j = 0; j <= b1; j++) {
				v[{b1 - j, b2 - b1 + 1}].push_back(l - b2);
			}
		}
		for (auto &x : v) sort(x.second.begin(), x.second.end());

		for (int i = 1; i <= q; i++) {
			string t1, t2;
			cin >> t1 >> t2;
			int l = t1.size();
			string res = "";
			int b1 = -1, b2 = -1;
			for (int i = 0; i < l; i++) {
				if (t1[i] == 'b' || t2[i] == 'b') {
					res.push_back('b');
					if (b1 == -1) b1 = i;
					else b2 = i;
				}
				else {
					res.push_back('a');
				}
			}
			if (b2 == -1) b2 = b1;
			int ans = 0;
			for (int j = 0; j <= b1; j++) {
				pii p = {b1 - j, b2 - b1 + 1};
				if (v.count(p)) {
					ans += upper_bound(v[p].begin(), v[p].end(), l - b2) - v[p].begin();
				}
			}
			cout << ans << endl;
		}
	}
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> q;
	if (q == 1 || n <= 1000 && q <= 1000) {
		work1::solve();
	}
	else {
		work2::solve();
	}

	return 0;
}