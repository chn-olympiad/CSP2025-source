#include <bits/stdc++.h>
#define fin for (int i = 1; i <= n; i++) 
#define fjm for (int j = 1; i <= m; j++)
using namespace std;
const int MOD = 998244353;
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	cin >> n;
	if (n < 3) {
		cout << 0 << endl;
		return 0;
	}
	vector<int> a(n + 1);
	fin {
		cin >> a[i];
	}
	if (n == 3) {
		int mx = max({a[1], a[2], a[3]});
		int sum = a[i] + a[2] + a[3];
		if (sum > mx * 2) cout << 1 << endl;
		else cout << 0 << endl;
		return 0;
	}
	long long ans, sum;
	ans = sum = 1;
	for (int i = n; i > 3; i--) {
		sum *= i;
		sum %= MOD;
		ans += sum;
		ans %= MOD;
	}
	cout << ans << endl;
	return 0;
} 
