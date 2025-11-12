#include<bits/stdc++.h>

using namespace std;

const int N = 5005;
int n;
int a[N], ans;
void dfs(int id, int mx, int sum) {
	if (id == n + 1) {
		return ;
	}
	if (sum + a[id] > max(mx, a[id]) * 2) {
		ans++;
	}
	dfs(id + 1, max(mx, a[id]), sum + a[id]);
	dfs(id + 1, mx, sum);
	return ;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	dfs(1, 0, 0);
	cout << ans;
	return 0;
}
