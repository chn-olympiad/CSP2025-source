#include <bits/stdc++.h>

using namespace std;

const int N = 510;
const int Mod = 998244353;

int n, m;
int c[N], Sum[N];
int C[N][N], fact[N];
int dp[2][N][N];
char s[N];
int Ss[N];

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	C[0][0] = 1;
	for (int i = 1; i < N; i ++) {
		C[i][0] = 1;
		for (int j = 1; j <= i; j ++) {
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % Mod;
		}
	}
	fact[0] = 1;
	for (int i = 1; i < N; i ++) fact[i] = 1ll * fact[i - 1] * i % Mod;
	
	scanf("%d%d", &n, &m);
	scanf("%s", s + 1);
	for (int i = 1; i <= n; i ++) scanf("%d", &c[i]), Sum[c[i]] ++;
	
	for (int i = 1; i <= n + 1; i ++) Sum[i] += Sum[i - 1];
	
	dp[0][0][0] = 1;
	for (int i = 1; i <= n; i ++) {
		memset(dp[i & 1], 0, sizeof dp[i & 1]); 
		Ss[i] = Ss[i - 1];
		if (s[i] == '1') {
			Ss[i] ++;
			for (int j = 0; j <= n; j ++) {
				for (int k = 0; k <= n; k ++) {
					int S = Sum[j + 1] - Sum[j];
					for (int Tmp = 0; Tmp <= S && Tmp <= k; Tmp ++) {
						dp[i & 1][j + 1][k - Tmp] += 1ll * dp[i - 1 & 1][j][k] * C[S][Tmp] % Mod * C[k][Tmp] % Mod * (Sum[j] - (Ss[i - 1] - k)) % Mod * fact[Tmp] % Mod;
						dp[i & 1][j + 1][k - Tmp] = (dp[i & 1][j + 1][k - Tmp] >= Mod ? dp[i & 1][j + 1][k - Tmp] - Mod : dp[i & 1][j + 1][k - Tmp]); 
					}
					dp[i & 1][j][k + 1] += dp[i - 1 & 1][j][k];
					dp[i & 1][j][k + 1] = (dp[i & 1][j][k + 1] >= Mod ? dp[i & 1][j][k + 1] - Mod : dp[i & 1][j][k + 1]);
				}
			}
		}
		else {
			for (int j = 0; j <= n; j ++) {
				for (int k = 0; k <= n; k ++) {
					int S = Sum[j + 1] - Sum[j];
					for (int Tmp = 0; Tmp <= S && Tmp <= k; Tmp ++) {
						dp[i & 1][j + 1][k - Tmp] += 1ll * dp[i - 1 & 1][j][k] * C[S][Tmp] % Mod * C[k][Tmp] % Mod * fact[Tmp] % Mod;
						dp[i & 1][j + 1][k - Tmp] = (dp[i & 1][j + 1][k - Tmp] >= Mod ? dp[i & 1][j + 1][k - Tmp] - Mod : dp[i & 1][j + 1][k - Tmp]); 
					}
				}
			}
		} 
	}
	
	int ans = 0;
	for (int j = 0; j <= n - m; j ++) {
		for (int k = 0; k <= n; k ++) {
			int p = (Sum[j] - (Ss[n - 1] - k)) - (s[n] == '0' ? 0 : 1);
			int Lef = Sum[n + 1] - Sum[j];
			if (p + Lef - k < 0) continue; 
			ans += 1ll * dp[n & 1][j][k] * fact[p + Lef - k] % Mod * C[Lef][k] % Mod * fact[k] % Mod;
			ans %= Mod;
		}
	}
	
	printf("%d", ans);
	
	return 0;
}

