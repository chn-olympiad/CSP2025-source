#include <bits/stdc++.h>
using namespace std;
const long long M = 998224353;
int n,a[5010],sum[5010],vis[5010];
long long ans;
void dfs(int l,int r,int sum) {
	if (sum < a[r]) return;
	if (sum > a[r]) ans = (ans + 1) % M;
	for (int i = l; i < r; i++) {
		if (!vis[i]) {
			vis[i] = 1;
			dfs(i + 1,r,sum - a[i]);
			vis[i] = 0;
		}
	}
	return;
}
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort (a + 1,a + n + 1);
	for (int i = 1; i <= n; i++) sum[i] = a[i] + sum[i - 1];
	for (int i = 3; i<= n; i++) {
		if (sum[i - 1] <= a[i]) continue;
		dfs(1,i,sum[i-1]);
		ans %= M;
	}
	cout << (ans % M) << endl;
	return 0;
}

