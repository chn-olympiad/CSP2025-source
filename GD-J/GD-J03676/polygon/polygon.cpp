#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 998244353;
int n, a[5005], ans;
vector<int> v;
bool check() {
	int maxn = INT_MIN, sum = 0;
	for (int t : v) {
		maxn = max(maxn, t);
		sum += t;
		//cout << t << " ";
	}
	//cout << endl;
	return sum > (maxn << 1);
}
void f(int s, int m) {
	if (m == 0) {
		if (check()) {
			ans = (ans + 1) % MOD;
		}
		return;
	}
	for (int i = s; i <= n - m + 1; ++i) {
		v.push_back(a[i]);
		f(i + 1, m - 1);
		v.pop_back();
	}
}
signed main () {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	if (n == 3) return cout << ((a[1] + a[2] + a[3]) > 2 * max(a[1], max(a[2], a[3]))), 0;
	for (int i = 3; i <= n; ++i) f(1, i);
	cout << ans;
	return 0;
}
