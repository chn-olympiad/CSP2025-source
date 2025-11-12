#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int MOD = 998244353, N = 5005;
int n, a[N];
int dfs(int np, int t, int sum, int mx, bool b) {
	int cnt = 0;
	if(t >= 3 && b) {
		if(sum > mx * 2) {
			cnt++;
		}
	}
	if(np == n + 1) return cnt;
	cnt += dfs(np + 1, t, sum, mx, 0) % MOD;
	cnt += dfs(np + 1, t + 1, sum + a[np], a[np], 1) % MOD;
	return cnt % MOD;
}
signed main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a+1, a+n+1);
	cout << dfs(1, 0, 0, 0, 1);
	return 0;
}