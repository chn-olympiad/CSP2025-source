#include<bits/stdc++.h>
using namespace std;
const int maxn = 501;
const int inf = 998244353;
int a[maxn], b[maxn], n, m;
long long dp[262200][20];
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	if(n <= 18){
		for(int i = 1;i <= n;i++){
			char ch;
			cin >> ch;
			a[i] = ch - '0';
		}
		for(int i = 1;i <= n;i++) cin >> b[i];
		dp[0][0] = 1;
		for(int i = 0;i < (1 << n);i++){
			int cnt = __builtin_popcount(i);
			for(int j = 0;j <= cnt;j++){
				dp[i][j] %= inf;
				// cout << i << ' ' << j << ' ' << dp[i][j] << endl;
				for(int k = 1;k <= n;k++){
					if(i & (1 << (k - 1))) continue;
					if(cnt - j >= b[k] || a[cnt + 1] == 0) dp[i ^ (1 << (k - 1))][j] += dp[i][j];
					else dp[i ^ (1 << (k - 1))][j + 1] += dp[i][j];
				}
			}
		}
		int ans = 0;
		for(int i = m;i <= n;i++) ans = (ans + dp[(1 << n) - 1][i]) % inf;
		cout << ans;
		return 0;
	}
	return 0;
}