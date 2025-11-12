#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 10;
const int mod = 998244353;

int n, m, ans;
char s[N];
int c[N], pre[N];
int fac[N];
int vis[N];

void Dfs(int x, int now) {
	if (now >= m) {
		ans = (ans + fac[n - x + 1]) % mod;
		return;
	}
	if (x == n + 1) return;
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			vis[i] = 1;
			Dfs(x + 1, now + ((s[x] == '1') & (c[i] > x - now - 1)));
			vis[i] = 0;
		}
	}
} 

signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	cin >> s + 1;
	//for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + (s[i] - '0');
	for (int i = 1; i <= n; i++) cin >> c[i];
	sort(c + 1, c + n + 1);
	fac[0] = 1;
	for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % mod;
	if (m == n) {
		for (int i = 1; i <= n; i++) {
			if (s[i] == '0' || c[i] == 0) {
				cout << 0; return 0;
			}
		}
		cout << fac[n]; return 0;
	}
	Dfs(1, 0);
	cout << ans << "\n";
	return 0;
}
