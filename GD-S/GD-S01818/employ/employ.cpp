#include <bits/stdc++.h>
#define N 505
#define ll long long
using namespace std;
int n, m, c[N], vis[N], ans;
string s;
void dfs(int id, int cnt, int die) {
	if (id > n) {
		if (cnt >= m) ans++;
		return;
	}
	for (int i = 1; i <= n; i++)
		if (!vis[i]) {
			vis[i] = 1;
			int flag = 0;
			if (die < c[i] && s[id - 1] == '1') flag = 1;
			dfs(id + 1, cnt + flag, die + !flag);
			vis[i] = 0;
		}
}
int main() {
	freopen("employ.in", "r", stdin), freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	cin >> n >> m;
	cin >> s;
	for (int i = 1; i <= n; i++) cin >> c[i];
	dfs(1, 0, 0);
	cout << ans;
	return 0;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
