#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
#define sr cin
#define sw cout
#define sendl '\n'
#define seia cout.flush();return 0

int n, m, ans;
bool vis[110];
int temp, c[110];
string str;

void dfs(int x) {
	if (n - temp < m) {
		return;
	}
	if (x == n + 1) {
		ans++;
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			vis[i] = true;
			bool f = false;
			if (temp >= c[i] || str[x - 1] == '0') {
				temp++;
				f = true;
			}
			dfs(x + 1);
			if (f) {
				temp--;
			}
			vis[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	sr >> n >> m;
	sr >> str;
	for (int i = 1; i <= n; i++) {
		sr >> c[i];
	}
	dfs(1);
	sw << ans << sendl;
	seia;
}