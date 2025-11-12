#include <bits/stdc++.h>
using namespace std;
const int N = 5e2 + 10;
const int INF = 0x3f3f3f3f;
int n, m, c[N], p[N], ansp;
string s;
bool v[N];
void dfs(int step) {
	if (step == n + 1) {
		int no = 0;
		for (int i = 1; i <= n; i++) {
			if (no >= p[i]) {
				no++;
				continue;
			} else if (!(s[i - 1] - '0')) {
				no++;
				continue;
			}
		}
		if (n - no >= m) ansp = ansp + 1 % 998244353;
		return ;
	}
	for (int i = 1; i <= n; i++) {
		if (!v[i]) {
			v[i] = 1;
			p[step] = c[i];
			dfs(step + 1);
			v[i] = 0;
		}
	}
}
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> s;
	for (int i = 1; i <= n; i++) cin >> c[i];
	dfs(1);
	cout << ansp;
	return 0;
}

