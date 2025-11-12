#include<bits/stdc++.h>
using namespace std;

const int MAXN = 505;
const int MN = 20;
const int MAXM = 300005;
const int MOD = 998244353;

int n, m;
long long ans = 0;
char ch[MAXN];
int c[MAXN];
int s[MAXN];
int dp[MN][MAXM];
int sum[MAXM];

int LOWBIT(int x) {
	return x & -x;
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	cin >> n >> m;
	scanf("%s", ch + 1);
	for (int i = 1; i <= n; ++i) s[i] = ch[i] - 48;
	for (int i = 0; i < n; ++i) scanf("%d", &c[i]);
	dp[0][0] = 1;
	
	int ful = (1 << n) - 1;
	for (int i = 1; i <= ful; ++i) {
		sum[i] = sum[i - LOWBIT(i)] + 1;
		for (int j = 0; j <= sum[i]; ++j) {
			for (int k = 0; k < n; ++k) {
				if ( ( i & (1 << k) ) == 0) continue;
				int nxt = i - (1 << k);
				if (s[ sum[i] ]) {
					if (sum[i] - 1 - j >= c[k]) dp[j][i] = (dp[j][i] + dp[j][nxt]) % MOD;
					else if (sum[i] - j < c[k] && j >= 1) dp[j][i] = (dp[j][i] + dp[j - 1][nxt]) % MOD;
				}
				else dp[j][i] = (dp[j][i] + dp[j][nxt]) % MOD;
			}
		}
			
	}
	for (int i = m; i <= n; ++i) ans = (ans + dp[i][ful]) % MOD;
	cout << ans << endl;
}
