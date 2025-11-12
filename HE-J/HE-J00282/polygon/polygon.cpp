#include<bits/stdc++.h>
using namespace std;
const int N = 5e3 + 50;
long long n;
long long a[N], ans;
bool vis[N];
void dfs(int x) {
	if (x == n + 1) {
		long long ma = 0, sum = 0;
		for (int i = 1; i <= n; i ++) {
			if (vis[i]) {
				sum += a[i]; 
				ma = max(ma, a[i]);
			}
		}
		if (sum > 2 * ma) {
			ans = (ans + 1) % 998244353;
		}
		return ;
	}
	vis[x] = true;
	dfs(x + 1);
	vis[x] = false;
	dfs(x + 1);
}
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	dfs(1);
	cout << ans;
	return 0;
}
