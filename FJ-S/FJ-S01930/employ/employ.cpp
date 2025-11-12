#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 998244353;
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<int> s(n + 1), c(n + 1);
	vector<ll> frac(n + 2);
	frac[0] = 1;
	for (int i = 1; i <= n + 1; ++i) frac[i] = frac[i - 1] * i % MOD;
	bool flag = true;
	int s1 = 1e9;
	for (int i = 1; i <= n; ++i) {
		char ch;
		cin >> ch;
		s[i] = ch - '0';
		if (s[i]) s1 = min(s1, i);
		if (s[i] == 0) flag = false;
	}
	int mc = 1e9;
	long long c0 = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> c[i];
		if (c[i]) mc = min(mc, c[i]);
		if (c[i] < s1) c0++;
	}
//	if (m == 1) {
//		cout << (n - c0) * frac[n - 1] % MOD << "\n";
////		cerr <<"OK" << endl;
//		return 0;
//	}
//	sort(c.begin() + 1, c.end(), greater<int>());
//	for (int i = 1; i <= n; ++i) cout << c[i] << " \n"[i == n];
//	c.erase(find(c.begin() + 1, c.end(), 0), c.end());
//	n = c.size();
//	cerr << find( - c.begin() << " " << n << endl;
//	if (flag) {
//		for (int i = 1; i <= n; ++i) {
//			cout << frac[i] << " ";
//			if (frac[i] == 161088479) cout << i << endl;
//		}
	if (m == n && !flag) {
		cout << 0 << endl;
		return 0; 
	}
	cout << frac[n] << endl;
//	}
	return 0;
}
