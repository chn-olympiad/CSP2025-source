#include<bits/stdc++.h>
#define int long long 
using namespace std;
#define upd(x,y) x = (x + y) % mod 
const int N = 505,mod = 998244353;
int n,m,c[N];
string s;
int dp[20][20][1 << 18],dp2[N][N];
int solve1(){
	dp[0][0][0] = 1;
	for (int i = 1;i <= n;i++){
		for (int j = 0;j <= n - m;j++){
			for (int k = 0;k < (1 << n);k++){
				for (int nk = 1;nk <= n;nk++){
					if (!(k & (1 << (nk - 1)))){
						if ((c[nk] <= j) || (s[i - 1] == '0')){
							upd(dp[i][j + 1][k | (1 << (nk - 1))],dp[i - 1][j][k]);
						}
						else{
							upd(dp[i][j][k | (1 << (nk - 1))],dp[i - 1][j][k]);
						}
					}
				}
			}
		}
	}
	int ans = 0;
	for (int j = 0;j <= n - m;j++){
		ans = (ans + dp[n][j][(1 << n) - 1]) % mod;
	}
	return ans;
}
int solve2(){
	int nsum = 0,ans = 1,sum = 1;
	for (int i = 1;i <= n;i++){
		sum = sum * i % mod;
		if (s[i - 1] == '1'){
			int msum = 0;
			for (int j = 1;j <= n;j++){
				(c[j] < i) && (msum++);
			}
			nsum--;
			ans = ans * max(0ll,msum + nsum + 1)% mod;
		}
	}
	for (int i = 1;i <= n + nsum;i++){
		ans = ans * i % mod;
	}
	return (sum - ans + mod) % mod;
}
int solve3(){
	int ans = 1;
	for (int i = 1;i <= n;i++){
		if ((c[i] == 0) || (s[i - 1] == '0')){
			return 0;
		}
		ans = ans * i % mod;
	}
	return ans;
}
int solve4(){
	return 114514;
}
signed main(){
	freopen("employ.in","r",stdin);
  freopen("employ.out","w",stdout);
  ios::sync_with_stdio(0),cin.tie(0);
  cin >> n >> m >> s;
  for (int i = 1;i <= n;i++){
  	cin >> c[i];
	}
	if (n <= 18){
		cout << solve1() << "\n";
		return 0;
	}
	if (m == 1){
		cout<< solve2() << "\n";
		return 0;
	}
	if (m == n){
		cout << solve3() << "\n";
		return 0;
	}
	cout << solve4() << "\n";
}
