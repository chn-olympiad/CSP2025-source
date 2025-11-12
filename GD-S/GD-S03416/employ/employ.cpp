#include<bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define F first
#define S second
#define vc vector
#define vci vc<int>
#define psb push_back
using namespace std;
const ll md = 998244353;
int n, m, c[20];
string s;
ll dp[300005][20], ans;
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> s;
	for(int i = 1; i <= n; i++) cin >> c[i];
	if(n <= 20){
		s = ' ' + s;
		dp[0][0] = 1;
		for(int i = 1; i < (1 << n); i++){
			int cnt = 0;
			for(int j = 1; j <= n; j++)
				if((i >> (j - 1)) & 1) cnt++;
			for(int j = 1; j <= n; j++)
				if((i >> (j - 1)) & 1)
					for(int k = 0; k <= cnt; k++){
						if(s[cnt] == '0'){
							dp[i][k] = (dp[i][k] + dp[i - (1 << (j - 1))][k]) % md;
							continue;
						}
						if(cnt - k - 1 >= c[j]) dp[i][k] = (dp[i][k] + dp[i - (1 << (j - 1))][k]) % md;
						if(cnt - k < c[j]) dp[i][k] = (dp[i][k] + dp[i - (1 << (j - 1))][k - 1]) % md;
//						int op = (s[cnt] == '1' && cnt - 1 - k < c[j]);
//						if(k >= op){
//							dp[i][k] = (dp[i][k] + dp[i - (1 << (j - 1))][k - op]) % md;
//							cout << i << ',' << j << ',' << k << ':' << op << ',' << dp[i - (1 << (j - 1))][k - op] << endl;
//						}
					}
//			for(int j = 0; j <= cnt; j++) cout << i << ',' << j << ':' << dp[i][j] << endl;
		}
//		for(int i = 1; i < (1 << n); i++)
//			for(int j = 0; j <= n; j++) cout << i << ',' << j << ':' << dp[i][j] << endl;
		for(int i = m; i <= n; i++) ans = (ans + dp[(1 << n) - 1][i]) % md;
		cout << ans << endl;
		return 0;
	}
	ans = 1;
	for(int i = 1; i <= n; i++) ans = ans * i % md;
	cout << ans;
	return 0;
}
