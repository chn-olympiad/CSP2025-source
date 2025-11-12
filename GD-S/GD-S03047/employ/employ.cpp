#include <cstdio>
#define ll long long
using namespace std;
const ll mod = 998244353;
int n, m, c[505], s[505], b[505];
int f[505];
char t[505]; 
ll ans, p[505];
void dfs(int x, int cnt, int tot) {
	if (x > n)  {
		if (tot >= m) (ans += 1) %= mod;
		return;
	}
	if (tot + b[n] - b[x - 1] < m) return;
	if (tot >= m) {
		(ans += p[n - x + 1]) %= mod;
		return;
	}
	for (int i = 1; i <= n; i++) if (!f[i]) {
		f[i] = true;
		if (s[x] && cnt < c[i]) dfs(x + 1, cnt, tot + 1);
		else dfs(x + 1, cnt + 1, tot);
		f[i] = false;
	}
}
bool check() {
	for (int i = 1; i <= n; i++) if (!s[i]) return false;
	return true;
}
bool judge() {
	for (int i = 1; i <= n; i++) if (!c[i]) return false;
	return true;
}
ll tsk1() {
	if (check() && judge()) return p[n];
	else return 0ll;
}
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d%s", &n, &m, t + 1);
	p[0] = 1;
	for (int i = 1; i <= n; i++) p[i] = p[i - 1] * i % mod;
	for (int i = 1; i <= n; i++) s[i] = t[i] - '0', b[i] = b[i - 1] + s[i];
	for (int i = 1; i <= n; i++) scanf("%d", c + i);
	if (m == n) printf("%lld", tsk1());
//	else if (check()) printf("%lld", p[n]);
	else {
		dfs(1, 0, 0);
		printf("%lld", ans);
	}
	return 0;
}
