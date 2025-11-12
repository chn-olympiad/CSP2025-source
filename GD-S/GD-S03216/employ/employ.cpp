#include <bits/stdc++.h>
using namespace std;

const int MXN = 502;
const int MOD = 998244353;

int n, m;
char s[MXN];
long long ns;
int cnt[MXN], sum[MXN];
long long mul[MXN], inv[MXN], f[MXN][MXN], g[MXN][MXN];

int read(){
	int x = 0;
	char c = getchar();
	for(;c < '0' || c > '9';) c = getchar();
	for(;c >= '0' && c <= '9';c = getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
	return x;
}

int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int i, j, k;
	n = read();
	m = read();
	scanf("%s", s + 1);
	for(i = 1;i <= n;++i){
		int c = read();
		++cnt[c];
	}
	for(i = n;i >= 0;--i) sum[i] = sum[i + 1] + cnt[i + 1];
	mul[0] = 1;
	for(i = 1;i <= n;++i) mul[i] = mul[i - 1] * i % MOD;
	inv[1] = 1;
	for(i = 2;i <= n;++i) inv[i] = MOD - MOD / i * inv[MOD % i] % MOD;
	for(i = 0;i <= n - m;++i) f[i][sum[i]] = 1;
	for(i = n;i;--i){
		for(j = 0;j <= n;++j)
			for(k = 0;k <= n;++k){
				g[j][k] = f[j][k];
				f[j][k] = 0;
			}
		if(s[i] == '1')
			for(j = 0;j <= n;++j)
				for(k = 0;k <= sum[j];++k){
					if(g[j][k] == 0) continue;
					if(k) (f[j][k - 1] += g[j][k] * k % MOD * inv[n - (sum[j] - k)]) %= MOD;
					if(j) (f[j - 1][k + cnt[j]] += g[j][k]) %= MOD;
					if(j && k + cnt[j]) (f[j - 1][k - 1 + cnt[j]] += -g[j][k] * (k + cnt[j]) % MOD * inv[n - (sum[j] - k)]) %= MOD;
				}
		else
			for(j = 1;j <= n;++j)
				for(k = 0;k <= sum[j];++k)
					if(g[j][k]) (f[j - 1][k + cnt[j]] += g[j][k]) %= MOD;
	}
	for(i = 0;i <= n;++i) (ns += f[0][i]) %= MOD;
	printf("%lld", (ns + MOD) % MOD * mul[n] % MOD);
	return 0;
}
