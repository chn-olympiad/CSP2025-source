#include <bits/extc++.h>
#define endl '\n'
typedef long long ll;
#define int ll
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;

constexpr int mod = 998244353;

void Main() {
	int n, m;
	string s;
	cin >> n >> m >> s;
	s = '\0' + s;
	vector<int> c(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> c[i];
	}
	int res = 0;
	vector<int> p(n + 1);
	iota(p.begin() + 1, p.end(), 1);
	do {
		int notin = 0;
		for (int i = 1; i <= n; ++i) {
			if (notin >= c[p[i]] || s[i] == 48) {
				++notin;
			}
		}
		if (n - notin >= m) {
			(++res) %= mod;
		}
	} while (next_permutation(p.begin() + 1, p.end()));
	cout << (res % mod + mod) % mod << endl;
}

// #define CSPS_MULTI_TEST_CASES

signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int t = 1;
#ifdef CSPS_MULTI_TEST_CASES
	cin >> t;
#endif
	while (t--) {
		Main();
	}
	return cout << flush, fflush(stdout), 0;
}

