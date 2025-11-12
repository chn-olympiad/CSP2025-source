#include<bits/stdc++.h>
using namespace std;
const int N = 500 + 10, mod = 998244353;
long long n, m, x, ans, sum0, c[N], su[N], po[N], C[N][N], D[N][N], dp[2][N][N];
string s;
inline long long h(long long x){
	return x % mod;
} 
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>m>>s, po[0] = dp[0][0][0] = 1;
	for(int i = 1;i <= n;i = -~i) cin>>x, c[x] ++, po[i] = h(po[i - 1] * i);
	for(int i = 0;i <= n;i = -~i){
		C[i][0] = D[i][0] = 1, su[i] = (i == 0 ? 0 : su[i - 1]) + c[i];
		for(int j = 1;j <= i;j = -~j) C[i][j] = h(C[i - 1][j - 1] + C[i - 1][j]), D[i][j] = h(D[i][j - 1] * (i - j + 1));
	}
	for(int i = 1, op = 1;i <= n;i = -~i, op ^= 1){
		sum0 += (s[i - 1] == '0');
		for(int j = 0;j <= i;j = -~j){
			for(int k = 0;k <= min(i - sum0, su[j]);k = -~k){
				dp[op][j][k] = (s[i - 1] == '0' ? 0 : dp[op ^ 1][j][k]);
				if(j == 0) continue;
				if(s[i - 1] == '0'){
					for(int p = 0;p <= min((long long)k, c[j]);p = -~p){
						dp[op][j][k] = h(dp[op][j][k] + h(C[c[j]][p] * dp[op ^ 1][j - 1][k - p]) * D[i - sum0 - (k - p)][p]);
					} 
				}else{
					for(int p = 1;p <= min((long long)k, c[j] + 1);p = -~p){
						dp[op][j][k] = h(dp[op][j][k] + h(dp[op ^ 1][j - 1][k - p] * max(0ll, su[j - 1] - (k - p))) * h(C[c[j]][p - 1] * D[i - 1 - sum0 - (k - p)][p - 1]));
					} 
				}
			}
		}
	}
	for(int i = 0;i <= n - m;i = -~i){
		for(int j = 0;j <= min(n - sum0, su[i]);j = -~j){
			if(su[i] - j <= sum0) ans = h(ans + h(dp[n & 1][i][j] * po[n - su[i]]) * D[sum0][su[i] - j]);
		}
	}
	cout<<ans;
	return 0;
}
