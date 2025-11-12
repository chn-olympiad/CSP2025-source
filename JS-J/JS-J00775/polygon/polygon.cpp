#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;
int n, a[5010], ans = 0, p, b[5010];

void dfs(int k, int t, int cnt, int s, bool f){
	if (cnt >= 3 && f){
		if (s > 2 * t) ans = (ans + 1) % mod;
	}
	if (k > n) return;
	dfs(k + 1, t, cnt, s, 0);
	b[cnt + 1] = a[k];
	dfs(k + 1, max(t, a[k]), cnt + 1, s + a[k], 1);
}

signed main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	dfs(1, 0, 0, 0, 0);
	cout << ans << endl;
	return 0;
}
