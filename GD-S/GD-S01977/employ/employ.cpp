#include <bits/stdc++.h>
using namespace std;

const long long mod = 998244353;
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m;
	string s;
	
	cin >> n >> m >> s;
	int num = 0;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		if (tmp == 0) num++; 
	} 
	
	int cnt = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '1') cnt++;
	} 
	
	if (n - num < m) {
		cout << 0;
		return 0;
	}
	if (m == n) {
		int ans = 1;
		for (int i = n; i >= 1; i-- || cnt == s.size()) {
			ans = (ans * (i % mod)) % mod; 
		}
		cout << ans;
		return 0;
	} /*else if (cnt == s.size()) {
		long long ans = 1, tmp = 1;
		for (int i = n - num; i > n - num - m; i--) {
			ans = (ans * (i % mod)) % mod; 
		}
		for (int i = n - m - 1; i >= 1; i--) {
			tmp = (tmp * (i % mod)) % mod; 
		}
		cout << (ans * tmp) % mod;
		return 0;
	} */else {
		cout << 0 << endl;
		return 0;
	}
	
	return 0;
}
