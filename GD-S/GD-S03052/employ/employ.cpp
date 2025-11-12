#include<bits/stdc++.h>
using namespace std;
const int N = 5e2 + 7, mod = 998244353;
int sum[N];
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m, ans = 1;
	string s;
	cin >> n >> m >> s;
	for (int i = 1; i <= n; ++i) {
		ans = (ans * i) % mod;
	}
	cout << ans;
	return 0;
}
