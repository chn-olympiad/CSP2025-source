#include <bits/stdc++.h>
#define Write ios::sync_with_stdio(0);
#define by cin.tie(0);
#define Na1L0n9 cout.tie(0);
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const int N = 1e5 + 10;
const int MOD = 998244353;
ll n, m, ans, c[N], a[N];
bool vis[N];
string s;
void dfs(int k) {
	if (k == n) {
		int cnt = 0, x = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == '0' || cnt >= c[a[i]]) {
				cnt++;
			}
			else {
				x++;
			}
		}
		ans += (x >= m);
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			vis[i] = 1;
			a[k] = i;
			dfs(k + 1);
			vis[i] = 0;
		}
	}
}
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	Write by Na1L0n9
	cin >> n >> m >> s;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	dfs(0);
	cout << ans;
	return 0;
}

