#include<bits/stdc++.h>
using namespace std;
const int N = 510;
const int mod = 998244353;
int a[N],s[N],ans = 0;
int dp[1100000][20],b[N];
inline int M(int x){
	return (x % mod + mod) % mod;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin >> n >> m;
	string t;
	cin >> t;
	for(int i = 0;i < n;i ++)
		a[i + 1] = t[i] - '0';
	b[0] = 0;
	for(int i = 1;i <= n;i ++){
		b[i] = 1 - a[i];
		b[i] += b[i - 1];
	}
	for(int i = 1;i <= n;i ++)
		cin >> s[i];
	if(n <= 18){
		dp[0][0] = 1;
		for(int i = 1;i < (1 << n);i ++){
			int num = 0;
			for(int j = 1;j <= n;j ++){
				if(i >> (j - 1) & 1){
					num ++;
				} 
			}
			for(int j = 1;j <= n;j ++){
				if(i >> (j - 1) & 1){
					int f = i - (1 << (j - 1));
					for(int t = 0;t <= n;t ++){
						if(num - t - 1 >= s[j] || a[num] == 0){
							dp[i][t] = M(dp[i][t] + dp[f][t]);
						}
						else dp[i][t + 1] = M(dp[i][t + 1] + dp[f][t]);
					}
				} 
			}
		}
		int ans = 0;
		for(int i = m;i <= n;i ++)
			ans = M(ans + dp[(1 << n) - 1][i]);
		cout << ans << "\n";
	}
	return 0;
}
