#include <bits/stdc++.h>
using namespace std;
const int N = 505, mod = 998244353;
int n, m, c[N], ans;
char s[N];
bool vis[N];
void dfs(int step, int tot) {
	if (step > n) {if (n - tot >= m) (ans += 1) %= mod; return;}
	for (int i = 1; i <= n; i++) {
		if (vis[i]) continue;
		bool f = 1;
		if (s[step] == '0' || tot >= c[i]) f = 0;
		vis[i] = 1, dfs(step + 1, tot + (!f)), vis[i] = 0;
	}
}
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m >> (s + 1);
	for (int i = 1; i <= n; i++) cin >> c[i];
	dfs(1, 0);
	cout << ans << '\n';
	return 0;
}