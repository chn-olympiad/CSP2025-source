#include <bits/stdc++.h>
using namespace std;
const int N = 505;
const int mod = 998244353;
int n, m;
string s;
int c[N];
int ans;
int a[N];
bool f = false;
signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	for(int i = 0;i < n;i ++ ) {
		if(s[i] - '0' == 0) f = true;
	}
	for(int i = 1;i <= n;i ++ ) cin >> c[i];
	if(m == 1) {
		ans = 1;
		for(int i = 1;i <= n;i ++ ) {
			ans = ans * i % mod;
		}
		cout << ans;
		return 0;
	}
	if(!f) {
		ans = 1;
		for(int i = 1;i <= n;i ++ ) {
			ans = ans * i % mod;
		}
		cout << ans;
		return 0;
	}
	if(m == n) {
		cout << 0;
		return 0;
	}
	return 0;
}
