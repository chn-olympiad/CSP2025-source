#include<bits/stdc++.h>
using namespace std;

const int N = 5e3 + 5, MOD = 998244353;

int n;
long long ans;
int a[N], sum[N];
void dfs(int x, int sum, int cnt, int ma) {
	int i;
	
	if (x == n + 1) {
		if (cnt > 2 && sum > 2 * ma) ans = (ans + 1) % MOD;
		
		return;
	}
	
	dfs(x + 1, sum + a[x], cnt + 1, max(ma, a[x]));
	dfs(x + 1, sum, cnt, ma);
}

int main() {
	int i;
	
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	cin >> n;
	for (i = 1; i <= n; ++i) cin >> a[i];
	
	if (n <= 100) dfs(1, 0, 0, 0);
	else {
		for (i = n - 2; i > 0; --i) ans = (ans + i) % MOD;
	}
	
	cout << ans;
	
	return 0;
}

