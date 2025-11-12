#include <bits/stdc++.h>
using namespace std;
const int maxn = 505, mod = 998244353;
int n, m;
long long a[maxn];
bool k = 1;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	string s;
	cin >> s;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		if(a[i]!=1) k = 0;
	}
		long long ans = 1;
		for(int i = n; i >= m; i--) ans = ans * i % mod;
		cout << ans;
	return 0;
}
