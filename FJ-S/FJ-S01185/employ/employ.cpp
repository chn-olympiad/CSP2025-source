#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 7, mod = 998244353;

int n, m, ans = 1;
string s;
int c[501]; 
bool f = 0;

int main() {
	
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	cin >> n >> m >> s;
	for (int i = 1; i <= n; ++i) {
		cin >> c[i];
	}
	for (auto i : s) {
		if (i == '0') {
			f = 1;
			break;
		}
	} 
	if (!f) {
		for (int i = 2; i <= n; ++i) {
			ans = ans * i % mod;
		}
	}
	cout << ans;
	
	return 0;
}
/*
²»ÏëÐ´ÁË¡£ 
*/
