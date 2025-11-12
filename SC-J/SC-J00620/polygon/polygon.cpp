#include<bits/stdc++.h>
using namespace std;
const int maxn = 5010, mod = 998244353, maxm = 510;

int a[maxn], s[maxn];
int ans = 0;
int n;
void dfs(int p, int sum) {
	if (p > n) {
		return ;
	}
	if (sum > a[p]) {
		ans ++, ans %= mod;
	}
	
	dfs(p + 1, sum);
	dfs(p + 1, sum + a[p]);
}

long long fac[maxn], inv[maxn];
long long qpow(int a, int b) {
//	printf("(%d %d)", a, b);
	if (b == 1) return a;
	long long res = qpow(a, b >> 1);
	res = res * res % mod;
	if (b & 1) res = res * a % mod;
	return res % mod;
}

int f[maxn][maxn];

int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int mxai = 0;
	scanf("%d", &n);
	for (int i = 1;i <= n;i ++) scanf("%d", &a[i]), mxai = max(a[i], mxai);
	sort(a + 1, a + n + 1);
	for (int i = 1;i <= n;i ++) s[i] = s[i - 1] + a[i];
	if (n <= 20) {//expect 40pts
		dfs(1, 0);
		printf("%d\n", ans);
	} else if (s[n] == n) {//expect 24pts
		fac[0] = 1;
		for (int i = 1;i <= n;i ++) {
			fac[i] = (fac[i - 1] * i) % mod;
			inv[i] = qpow(fac[i], mod - 2);
		}
		long long sum = 0;
		for (int i = 3;i <= n;i ++) {
			sum += (((fac[n] * inv[n - i]) % mod) * inv[i]) % mod;
		}
		printf("%lld", (sum + 1) % mod);
	} else {
		printf("%d\n", s[n]);
		puts("I dont know how to solve this problem");
	}
	return 0;
}