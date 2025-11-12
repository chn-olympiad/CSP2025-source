# include<bits/stdc++.h>
# define N 15
using namespace std;
int n, m, ans, a[N], b[N], vis[N];
string s;
int check() {
	int sum = 0, cnt = 0;
	for(int i = 1; i <= n; i ++) {
		if(s[i - 1] == '0' || a[b[i]] - sum <= 0)
			sum ++;
		else
			cnt ++;
	}
	if(cnt >= m) return 1;
	return 0;
}
void dfs(int x) {
	if(x == n + 1) ans += check();
	for(int i = 1; i <= n; i ++) {
		if(vis[i]) continue;
		b[x] = i, vis[i] = 1;
		dfs(x + 1);
		b[x] = vis[i] = 0;
	}
}
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin.tie(0) -> sync_with_stdio(false);
	cin >> n >> m;
	cin >> s;
	for(int i = 1; i <= n; i ++)
		cin >> a[i];
	dfs(1);
	cout << ans << "\n";
	return 0;
}