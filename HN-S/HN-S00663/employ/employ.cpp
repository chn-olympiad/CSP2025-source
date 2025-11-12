#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 512;
const int mod = 998244353;
int n, m, ans;
char s[N];
int a[N], p[N], b[N];
bool vis[N];

void dfs(int x) {
	if (x > n) {
		int tot = 0, cnt =0 ;
		for (int i = 1; i <= n; i++) {
			if (s[i] == '0')tot++;
			else if (b[i] > tot) {
				cnt++;
			}
		}
		ans += (cnt >= m);
		return ;
	}
	for (int i = 1; i <= n; i++) if (!vis[i]) {
		vis[i] = true;
		b[x] = a[i];
		dfs(x + 1);
		vis[i] = false;
	}
}

int main() {
	freopen("employ.in", "r", stdin);freopen("employ.out", "w", stdout);
	scanf("%d%d", &n,&m);
	scanf("%s", s + 1);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	dfs(1);
	printf("%d\n", ans);
	return 0;
}