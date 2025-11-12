#include <bits/stdc++.h>

#define i64 long long

#define pii pair<int, int>
#define fi first
#define se second
#define mp make_pair
#define eb emplace_back

using namespace std;

inline int Read() {int res; return scanf("%d", &res), res; }
inline i64 Read64() {i64 res; return scanf("%lld", &res), res; }

const int N = 500 + 5, Mod = 998244353;

int ksm(int x, int y) {
	int tmp = 1;
	for(; y; y >>= 1) {
		if(y & 1) tmp = (i64)tmp * x % Mod;
		x = (i64)x * x % Mod;
	} 
	return tmp;
}

int n, m, a[N], t = 0, cnt[N], c[N], d[N];
char s[N];
int fac[N], inv[N], dp[N][N][N], tmp[N][N], sum[N];

int A(int x, int y) {
	if(x < y) return 0;
	return (i64)fac[x] * inv[x - y] % Mod;
}

int C(int x, int y) {
	if(x < y) return 0;
	return (i64)fac[x] * inv[x - y] % Mod * inv[y] % Mod;
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	n = Read(), m = Read();
	scanf("%s", s + 1);
	for(int i = 1; i <= n; ++ i) c[i] = Read(), cnt[c[i]] ++;
	sum[0] = cnt[0];
	for(int i = 1; i <= n; ++ i) sum[i] = cnt[i] + sum[i - 1];
	
	fac[0] = 1;
	for(int i = 1; i <= n; ++ i) fac[i] = (i64)fac[i - 1] * i % Mod;
	inv[n] = ksm(fac[n], Mod - 2);
	for(int i = n; i >= 1; -- i) inv[i - 1] = (i64)inv[i] * i % Mod; 
	
	for(int i = 1; i <= n; ++ i) d[i] = d[i - 1] + (s[i] == '0'); 
	
	dp[0][0][0] = 1;
	for(int i = 1; i <= n; ++ i) {
		for(int j = 0; j < i; ++ j) {
			for(int k = 0; k < i; ++ k) tmp[j][k] = 0;
		} 
		if(s[i] == '0') {
			for(int j = 0; j < i; ++ j) {
				for(int k = 0; k < i; ++ k) {
					for(int z = 0; z <= min(k, cnt[j + 1]); ++ z) (tmp[j][k - z] += (i64)dp[i - 1][j][k] * A(cnt[j + 1], z) % Mod * C(k, z) % Mod) >= Mod && (tmp[j][k - z] -= Mod);
				}
			} 
			for(int j = 0; j < i; ++ j) {
				for(int k = 0; k < i; ++ k) (dp[i][j + 1][k] += tmp[j][k]) >= Mod && (dp[i][j + 1][k] -= Mod);
			} 
		}else {
			for(int j = 0; j < i; ++ j) {
				for(int k = 0; k <= (i - 1 - j); ++ k) {
//					cout << j << " " << k << " " << (sum[j] - (j - d[i - 1]) - (i - 1 - j - k)) << endl;
					(dp[i][j + 1][k] += (i64)dp[i - 1][j][k] * max(0, (sum[j] - (j - d[i - 1]) - (i - 1 - j - k))) % Mod) >= Mod && (dp[i][j + 1][k] -= Mod);
				}
			}
			
			for(int j = 0; j <= i; ++ j) {
				for(int k = 0; k <= i; ++ k) {
					for(int z = 0; z <= min(k, cnt[j]); ++ z) (tmp[j][k - z] += (i64)dp[i][j][k] * A(cnt[j], z) % Mod * C(k, z) % Mod) >= Mod && (tmp[j][k - z] -= Mod);
				}
			}
			
			for(int j = 0; j <= i; ++ j) {
				for(int k = 0; k <= i; ++ k) dp[i][j][k] = tmp[j][k]; 
			}
			
			for(int j = 0; j < i; ++ j) {
				for(int k = 0; k < i; ++ k) (dp[i][j][k + 1] += dp[i - 1][j][k]) >= Mod && (dp[i][j][k + 1] -= Mod);
			}
		}
		
//		for(int j = 0; j <= i; ++ j) {
//			for(int k = 0; k <= i; ++ k) cout << i << " " << j << " " << k << " " << dp[i][j][k] << endl;			 
//		}
	} 
	
	int ans = 0;
	for(int j = 0; j <= n - m; ++ j) {
//		cout << j << " " << d[n] << endl;
		for(int k = 0; k <= n; ++ k) {
//			cout << j << " " << k << " " << dp[n][j][k] << " " << n - sum[j] << " " << k << endl;			 
			(ans += (i64)dp[n][j][k] * A(n - sum[j], k) % Mod * fac[d[n]] % Mod) >= Mod && (ans -= Mod);
		}
	}
	
	printf("%d\n", ans);
	
	return 0;
}
/*
//freopen
//froepen
//fropen
//fopen
//freopen("employ.in", "w", stdin);
//freopen("employ.in", "r", stdout);
//freopen("employ.out", "r", stdin);
*/ 
