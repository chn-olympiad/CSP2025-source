#include <bits/stdc++.h>
using namespace std;
const int N = 5e3+10, M = 1e4 + 10;
int n;
long long a[N];
int dp[N][M];
int h[N];
long long cnt = 0;
void dfs(int x, long long sum, long long mx, int l) {
	if(x == n + 1) {
		if(l >= 3 && mx * 2 < sum) {
			cnt++;
			cnt %= 998244353;
		}
		return ;
	}
	dfs(x + 1, sum + a[x], max(mx, a[x]), l + 1);
	dfs(x + 1, sum, mx, l);
}
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		if(cnt > a[i]) {
			cnt = a[i];
		}
	}
	sort(a + 1, a + 1 + n);
	dfs(1, 0, 0, 0);
	cout << cnt;
	return 0;
}
