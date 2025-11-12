#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, a[100005];
int ans;

void dfs(int dep, int sum, int ma) {
	if(dep == n + 1) {
		if(ma * 2 < sum) {
			ans += 1;
			ans %= 998244353;
		}
		return;
	}
	dfs(dep + 1, sum + a[dep], max(ma, a[dep]));
	dfs(dep + 1, sum, ma);
}

signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);	
	cin >> n;
	for(int i = 1; i <= n; i += 1) {
		cin >> a[i];
	}
	dfs(1, 0, 0);
	cout << ans;
}

