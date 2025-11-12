#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
int a[5005];
int n;
long long cnt;
bool vis[5005];
void dfs(long long num, long long maxs, int idx,long long sum) {
	if(num >= 3 && sum > maxs * 2) {
		cnt ++;
	}
	for (int i = idx + 1; i <= n; i ++) {
		dfs(num + 1, a[i], i, sum + a[i]);
	}
}
long long c(int m,int k) {
	long long x = 1;
	long long y = 1;
	if (k > m /2) {
		k = m - k;
	}
	for (long long i = m; i >= m - k + 1; i --) {
		x *= i;
		x /= y;
		y ++;
	}
	return x % MOD;
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	bool flag_1 = true;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		if (a[i] > 1) {
			flag_1 = false;
		}
	}
	sort (a + 1, a + n + 1);
	if(flag_1) {
		long long ans = 0;
		for (int i = 3; i <= n; i ++) {
			ans += c(n, i) % MOD;
			ans %= MOD;
		}
		cout << (ans + MOD) % MOD;
	}
	else {
		dfs(0, 0, 0, 0);
		cout << cnt % MOD;
	}
	
	return 0;
}
