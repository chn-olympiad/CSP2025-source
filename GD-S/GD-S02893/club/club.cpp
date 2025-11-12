#include <bits/extc++.h>
#define endl '\n'
typedef long long ll;
#define int ll
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;

void Main() {
	int n;
	cin >> n;
	vector<vector<int>> a(n + 1, vector<int>(4));
	bool spAchk = true, spBchk = true;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i][1] >> a[i][2] >> a[i][3];
		if (a[i][3] != 0) {
			spAchk = spBchk = false;
		}
		if (a[i][2] != 0) {
			spAchk = false;
		}
	}
	if (n <= 10) {
		vector<int> mk(n + 1);
		function<int(int, int, int, int)> dfs = [&](int pos, int c1, int c2, int c3) -> int {
			if (max({c1, c2, c3}) > n / 2) {
				return -1;
			}
			if (pos == n) {
				int res = 0;
				for (int i = 1; i <= n; ++i) {
					res += a[i][mk[i]];
				}
				return res;
			}
			int res = 0;
			mk[pos + 1] = 1;
			res = max(res, dfs(pos + 1, c1 + 1, c2, c3));
			mk[pos + 1] = 2;
			res = max(res, dfs(pos + 1, c1, c2 + 1, c3));
			mk[pos + 1] = 3;
			res = max(res, dfs(pos + 1, c1, c2, c3 + 1));
			mk[pos + 1] = 0;
			return res;
		};
		cout << dfs(0, 0, 0, 0) << endl;
	} else if (spAchk) {
		sort(a.begin() + 1, a.end(), [&](const vector<int> &x, const vector<int> &y) {
			assert(static_cast<int>(x.size()) == 4 && static_cast<int>(y.size()) == 4);
			return x[1] > y[1];
		});
		int res = 0;
		for (int i = 1; i <= n / 2; ++i) {
			res += a[i][1];
		}
		cout << res << endl;
	} else if (spBchk) {
		sort(a.begin() + 1, a.end(), [&](const vector<int> &x, const vector<int> &y) {
			assert(static_cast<int>(x.size()) == 4 && static_cast<int>(y.size()) == 4);
			return x[1] == y[1] ? x[2] < y[2] : x[1] > y[1];
		});
		int res = 0;
		for (int i = 1; i <= n / 2; ++i) {
			res += a[i][1];
		}
		for (int i = n / 2 + 1; i <= n; ++i) {
			res += a[i][2];
		}
		cout << res << endl;
	} else {
		int res = 0;
		for (int i = 1; i <= n; ++i) {
			res += max({a[i][1], a[i][2], a[i][3]});
		}
		cout << res << endl;
	}
}

#define CSPS_MULTI_TEST_CASES

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	srand(time(0));
	int t = 1;
#ifdef CSPS_MULTI_TEST_CASES
	cin >> t;
#endif
	while (t--) {
		Main();
	}
	return cout << flush, fflush(stdout), 0;
}

