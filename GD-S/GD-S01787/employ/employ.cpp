#include <bits/stdc++.h>
using namespace std;
const int maxs = (1 << 19), maxt = 20, maxn = 5e2 + 7, mod = 998244353;
int dp[maxs][maxt], c[maxn];
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	for(int i = 0; i < n; i++) cin >> c[i];
	if(n <= 18){
		int ALL = (1 << n) - 1;
		dp[0][0] = 1;
		int ans = 0;
		for(int S = 0; S <= ALL; S++){
			int j = __builtin_popcount(S);
			//cout << S << " " << j << ": ";
			for(int t = 0; t <= j; t++){
				for(int i = 0; i < n; i++){
					if(!(S & (1 << i))) {
						int ok = (s[j] == '1' ? t >= c[i] : 1);
						dp[S | (1 << i)][t + ok] = (dp[S | (1 << i)][t + ok] + dp[S][t]) % mod;
					}
				}
				//cout << dp[S][t] << " "; 
				if(S == ALL && t <= n - m) ans = (ans + dp[S][t]) % mod; 
			}
			//cout << "\n";
		}
		cout << ans << endl;
	}
	else {
		if(m == n) cout << 0 << endl;
		if(m == 1){
			int fl;
			for(int i = 0; i < n; i++){
				if(s[i] == '1') {
					fl = i;
					break;
				}
			}
			long long cnt = 0;
			for(int i = 1; i <= n; i++){
				if(c[i] > fl) cnt++;
			}
			long long ans = cnt;
			for(int i = 1; i < n; i++) ans = ans * i % mod;
			cout << ans << endl;
		}
		else {
			long long ans = 1;
			for(long long i = 1; i <= n; i++) {
				ans = ans * i % mod;
			}
			cout << (m == n ? 0 : ans) << endl;
		}
	}
	return 0;
}
