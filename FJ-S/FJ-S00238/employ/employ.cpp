#include <bits/stdc++.h>
#define int long long 
using namespace std;
const int N = 510;
const int mod = 998244353;
int c[N];
int n, m, ans = 1;
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	string str;
	cin >> str; 
	for(int i = 1; i <= n; i++) cin >> c[i];
	for(int i = 1; i <= n; i++) {
		ans = (ans % mod) * (i % mod);
	}
	cout << ans;
	return 0;
} 
