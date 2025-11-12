#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define ull unsigned long long
#define i128 __int128
#define PII pair<int, int>
#define PLL pair<ll, ll>
using namespace std;

constexpr ll inf = (1ll << 62);
constexpr int N = 505, mod = 998244353;

void solve() {
	int n, m;
	string s;
	cin >> n >> m >> s;
	vector<int> c(n), p(n);
	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}
	iota(p.begin(), p.end(), 1);
	ll ans = 0;
	do {
		vector<int> d(n);
		for (int i = 0; i < n; i++) {
			d[p[i] - 1] = c[i];
		}
//		cout << "P: ";
//		for (auto i : p) cout << i << " ";cout << "\n";
//		cout << "D: ";
//		for (auto i : d) cout << i << " ";cout << "\n";
		int cnt = 0, res = 0;
		for (int i = 0; i < n; i++) {
			if (cnt >= d[i]) {
				cnt++;
				continue;
			}
			if (s[i] == '0') {
				cnt++;
			} else {
				res++;
			}
		}
		if (res >= m) {
			ans++;
			ans %= mod;
		}
	} while (next_permutation(p.begin(), p.end()));
	cout << ans << "\n";
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	while (t--) {
		solve();
	}
	return 0;
} 
