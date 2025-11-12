#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod = 998244353;
char s[510];
ll f[510];
bool v[510];
ll sum;
int n, m, cnt, a[510], c[510];
void dfs(int x) {
	if (x <= n) {
		for (int i = 1; i <= n; i++) {
			if (v[i]) continue;
			v[i] = 1;
			a[x] = i;
			dfs(x + 1);
			v[i] = 0;
		}
	}
	else {
		int cnt = 0, ans = 0;
		for (int i = 1; i <= n; i++) {
			if (s[i] == '0' || cnt >= c[a[i]]) cnt++;
			else ans++;
		}
		if (ans >= m) sum = (sum + 1) % mod;
	}
}
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	f[0] = 1ll;
	for (int i = 1; i < 510; i++) f[i] = f[i - 1] * i % mod;
	scanf("%d%d", &n, &m);
	scanf("%s", s + 1);
	for (int i = 1; i <= n; i++) scanf("%d", c + i);
	dfs(1);
	printf("%lld", sum);
	return 0;
}
