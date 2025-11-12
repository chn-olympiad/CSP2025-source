#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5000;
const int mod =  998244353;
ll n, a[N], ans;
void dfs(int q, int num, int maxn, ll sum) {
	if (num >= 3 && sum > maxn * 2) {
		ans ++;
		ans %= mod;
	}
	for (int i = q + 1; i <= n; i ++) {
		dfs(i, num + 1, a[i], sum + a[i]);
	}
}
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i < n - 1; i ++) {
		dfs(i, 1, a[i], a[i]);
	}
	cout << ans % mod;
	return 0;
}
