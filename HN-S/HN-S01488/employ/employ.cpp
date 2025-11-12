#include <bits/stdc++.h>
using namespace std;

void fileIO(const string &s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

using i64 = long long;
const int N = 510, P = 998244353;

int n, m;
string s;

// dp[i][j] : i 个人失败 j 个人成功未确认 
int dp[2][N][N], fact[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	fileIO("employ");
	
	cin >> n >> m >> s;
	vector<int> c(n + 1), pc(n + 1);
	for(int i = 0, x; i < n; i ++) {
		cin >> x;
		c[x] ++;
	}
	
	pc = c;
	for(int i = 1; i <= n; i ++)
		pc[i] += pc[i - 1];
	
	fact[0] = 1;
	for(int i = 1; i <= n; i ++)
		fact[i] = fact[i - 1] * (i64)i % P;
	
	dp[1][0][0] = 1;
	int c0 = 0;
	for(int i = 0; i < n; i ++) {
		int u = i & 1, v = u ^ 1;
		memset(dp[u], 0, sizeof dp[u]);
		if(s[i] == '0') {
			c0 ++;
			for(int j = 1; j <= n; j ++) {
				for(int k = n; k >= 0; k --)
					dp[u][j][k] = dp[v][j - 1][k];
				for(int l = 1; l <= c[j]; l ++) {
					for(int k = 0; k < n; k ++) {
						dp[u][j][k] = (dp[u][j][k] + 
						dp[u][j][k + 1] * (k + 1ll)) % P;
					}
				}
			}
		}else{
			for(int j = 0; j + 1 <= n; j ++) {
				for(int k = 0; k <= n; k ++)
					dp[u][j + 1][k] = 
					dp[v][j][k] * (i64)(pc[j] - (j - c0) - (i - j - k)) % P;
				for(int l = 1; l <= c[j + 1]; l ++) {
					for(int k = 0; k < n; k ++) {
						dp[u][j + 1][k] = (dp[u][j + 1][k] + 
						dp[u][j + 1][k + 1] * (k + 1ll)) % P;
					}
				}
				for(int k = 1; k <= n; k ++)
					(dp[u][j][k] += dp[v][j][k - 1]) %= P;
			}
		}
	}
	
	int u = (n + 1) & 1;
	for(int j = 0; j <= n; j ++)
		for(int l = pc[j] + 1; l <= n; l ++)
			for(int k = 0; k < n; k ++) {
				dp[u][j][k] = (dp[u][j][k] + 
				dp[u][j][k + 1] * (k + 1ll)) % P;
			}
	
	int ans = 0;
	for(int i = 0; i <= n; i ++) {
		if(n - i >= m) ans = (ans + dp[u][i][0]) % P;
	}
	cout << (ans * (i64)fact[c0]) % P << "\n";
}


