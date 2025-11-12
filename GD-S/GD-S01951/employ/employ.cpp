#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout); 
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	vector <bool> s(n + 1); {
		string s_;
		cin >> s_;
		s_ = " " + s_;
		for (int i = 1; i <= n; i ++)
			s[i] = s_[i] - '0';
	}
	vector <int> c(n + 1);
	for (int i = 1; i <= n; i ++)
		cin >> c[i];
	if (m == n) {
		bool all1 = 1;
		for (int i = 1; i <= n; i ++)
			if (!s[i])
				all1 = 0;
		bool allup0 = 1;
		for (int i = 1; i <= n; i ++)
			if (c[i] == 0)
				allup0 = 0;
		if (!all1 || !allup0) {
			cout << 0 << "\n";
			return 0;
		}
		int ans = 1;
		for (int i = 1; i <= n; i ++)
			ans = ans * i % MOD;
		cout << ans << "\n";
		return 0;
	}
	if (m == 1) {
		
	}
	function <bool(vector <int>&)> check = [&](vector <int>& p) {
		int unac = 0, ac = 0;
		for (int i = 1; i <= n; i ++) {
			if (s[i] == 0 || unac >= c[p[i]])
				unac ++;
			else
				ac ++;
		}
		return ac >= m;
	};
	vector <int> p(n + 1);
	for (int i = 1; i <= n; i ++)
		p[i] = i;
	int ans = 0;
	do {
		ans += check(p);
	} while (next_permutation(p.begin() + 1, p.begin() + n + 1));
	cout << ans << "\n";
	return 0;
}
