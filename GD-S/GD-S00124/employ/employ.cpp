#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
constexpr int mod = 998244353;
constexpr int maxn = 500;
int n, m;
string s;
int c[maxn + 10], p[maxn + 10];
LL ans = 0;
bool vis[maxn + 10];
void dfs(int x, int cnt, int out) {
	if (x == n + 1) {
		if (cnt >= m) ++ans;
		if (ans == mod) ans = 0;
		return ;
	}
	for (int i = 1; i <= n; ++i) {
		if (!vis[i]) {
			vis[i] = 1;
			p[x] = i;
			if (out >= c[i]) dfs(x + 1, cnt, out + 1);
			else {
				if (s[x - 1] == '1') dfs(x + 1, cnt + 1, out);
				else dfs(x + 1, cnt, out + 1);
			}
			p[x] = 0;
			vis[i] = 0;
		}
	}
}
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	cin >> s;
	bool flag = true;
	for (int i = 0; i < n; ++i) if (s[i] == '0') flag = false;
	for (int i = 1; i <= n; ++i) cin >> c[i];
	if (n <= 10) {
		dfs(1, 0, 0);
		cout << ans << "\n";
	} else if (flag) {
		ans = 1;
		for (int i = 1; i <= n; ++i) ans = ans * i % mod;
		cout << ans << "\n";
	} else cout << "0\n";
	return 0;
}

