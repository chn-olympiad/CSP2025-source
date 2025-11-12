#include <bits/stdc++.h>
using namespace std;

int n, m;
char s[510];
int c[510], tot[510];
long long ans = 1;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d", &n, &m);
	scanf("%s", s + 1);
	for (int i = 1; i <= n; i++)
		tot[i] = tot[i - 1] + (s[i] == '1');
	for (int i = 1; i <= n; i++)
		scanf("%d", &c[i]);
	for (int i = 1; i <= n; i++)
		ans *= i, ans %= 998244353;
	printf("%lld\n", ans % 998244353);
}