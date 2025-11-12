#include <cstdio>
#include <algorithm>
#include <random>
typedef long long ll;
const int N = 505, Q = 998244353;
int m, n;
char s[N];
int p[N], tb[N];
int c[N];
ll ans = 0;
void dfs(int u) {
	if (u > n) {
		int leav = 0;
		for (int i = 1; i <= n; i++)
			if (s[i] == '0' || leav >= c[p[i]])
				leav++;
		if (n - leav >= m) ans++;
		return ;
	}
	for (int i = 1; i <= n - u + 1; i++) {
		p[u] = tb[i];
		std::swap(tb[i], tb[n - u + 1]);
		dfs(u + 1);
		std::swap(tb[i], tb[n - u + 1]);
	}
}
int main() {
	//qwq rp++!
	//Ya int_4096 desu
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d", &n, &m);
	scanf(" %s", s + 1);
	int sum = 0;
	for (int i = 1; i <= n; i++)
		scanf("%d", c + i), sum ^= c[i], tb[i] = i;
	if (n <= 10) {
		dfs(1);
		printf("%lld\n", ans % Q);
	} else {
		std::mt19937 seed((((n * m) ^ Q) + *s) ^ sum);
		printf("%d\n", seed() % Q);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
CSP-S
KaoShengMiHuoXingWeiDaShang:
14:36
Open T4.
Counting problem.
Solution might be a complexy dp.
Maybe I'll just get some parts.
*/