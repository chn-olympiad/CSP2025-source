#include <bits/stdc++.h>
using namespace std;
const int N = 5 * 1e3 + 5;
const long long MOD = 998244353;
int n, a[N], sum, ans;
bool vis[N];
void dfs(int x) {
	if (x == n) {
		ans ++;
		ans %= MOD;
		return ;
	}
	for (int i = 1; i <= n; i ++) {
		if (!vis[i]) {
			vis[i] = true;
			dfs(i + 1);
			vis[i] = false;
		}
	}
}
int main() {
//	freopen("polygon.in", "r", stdin);
//	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i<= n; i ++) {
		cin >> a[i];
		sum += a[i];
	}
	if (n <= 2 || sum == 1) {
		cout << 0;
		return 0;
	}
	if (n == 3) {
		int fir = a[1] + a[2], sec = a[1] + a[3], thi = a[2] + a[3];
		if (fir > a[3] && sec > a[2] && thi > a[1])	cout << 1;
		else cout << 0;
		return 0;
	}
	for (int i = 3; i <= n; i ++) {
		dfs(i);
	} 
	cout << ans % MOD;
	return 0;
}

