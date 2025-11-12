#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::cerr;
using std::clog;

constexpr int mod = 998244353;

int main() {
	
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	cin.tie(nullptr); cout.tie(nullptr); std::ios::sync_with_stdio(false);
	
	int n, m;
	cin >> n >> m;
	
	std::string str;
	cin >> str;
	
	if(str.find('0') == std::string::npos) {
		int ans = 1;
		for(int i = 2; i <= n; ++i) {
			ans = (long long)ans * i % mod;
		}
		cout << ans;
		return 0;
	}
	
	
	return 0;
}
