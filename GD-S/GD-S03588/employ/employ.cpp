#include <cstdio>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

const int mod = 998244353;
int n, m, c[501], a[501], ans;
char S[505];
bool vis[501];
void dfs(int pl) {
	if (pl == n + 1) {
		int le = 0, cnt = 0;
		for (int i = 1; i <= n; i++)
			if (le >= c[a[i]])
				le++;
			else if (S[i - 1] == '0')
				le++;
			else
				cnt++;
		if (cnt >= m)
			ans = (ans + 1) % mod;
	}
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			vis[i] = true;
			a[pl] = i;
			dfs(pl + 1);
			vis[i] = false;
		}
	}
}
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d%s", &n, &m, S);
	for (int i = 1; i <= n; i++)
		scanf("%d", &c[i]);
	if (n <= 18) {
		dfs(1);
		printf("%d", ans);
		return 0;
	}
	if (m == n) {
		bool t = true;
		for (int i = 1; i <= n; i++)
			if (c[i] == 0) {
				t = false;
				break;
			}
		for (int i = 0; i < n; i++)
			if (S[i] == '0') {
				t = false;
				break;
			}
		if (t) {
			int cc = 1;
			for (int i = 1; i <= n; i++)
				cc = 1ll * cc * i % mod;
			printf("%d", cc);
		} else
			printf("%d", 0);
		return 0;
	}
	if (m == 1) {
		bool t = false;
		for (int i = 0; i < n; i++)
			if (S[i] == '1')
				t = true;
		if (!t)
			printf("%d", 0);
		return 0;
	}
	printf("%d", 0);
	return 0;
}
