#include <bits/extc++.h>
#define endl '\n'
typedef long long ll;
#define int ll
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;

void Main() {
	int n, q;
	cin >> n >> q;
	vector<pair<string, string>> s(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> s[i].first >> s[i].second;
	}
	while (q--) {
		pair<string, string> t;
		cin >> t.first >> t.second;
		if (t.first.size() != t.second.size()) {
			cout << 0 << endl;
			continue;
		}
		int res = 0;
		for (int i = 1; i <= n; ++i) {
			if (s[i].first.size() > t.first.size()) {
				continue;
			}
			bool ens = false;
			for (int j = 0; j <= static_cast<int>(t.first.size() - s[i].first.size()); ++j) {
				if (s[i].first[0] == t.first[j] && s[i].second[0] == t.second[j]) {
					bool tmp = true;
					for (int k = 1; k < static_cast<int>(s[i].first.size()); ++k) {
						if (s[i].first[k] != t.first[j + k] || s[i].second[k] != t.second[j + k]) {
							tmp = false;
							break;
						}
					}
					for (int k = 0; k < j; ++k) {
						if (t.first[k] != t.second[k]) {
							tmp = false;
							break;
						}
					}
					for (int k = j + static_cast<int>(s[i].first.size()); k < static_cast<int>(t.first.size()); ++k) {
						if (t.first[k] != t.second[k]) {
							tmp = false;
							break;
						}
					}
					if (tmp) {
						ens = true;
						break;
					}
				}
			}
			if (ens) {
				++res;
			}
		}
		cout << res << endl;
	}
}

// #define CSPS_MULTI_TEST_CASES

signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
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

