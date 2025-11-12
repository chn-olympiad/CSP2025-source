#include <bits/stdc++.h>
using namespace std;
const int md = 998244353;
int n, m, w, sum, flag, a[505], dp[300005][20], ans;
string s;

int js(int x){
	sum = 0;
	while(x)
	    if(x & 1) sum++, x >>= 1;
	    else x >>= 1;
	return sum;
}

int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m >> s;
	for(int i = 1; i <= n; i++) cin >> a[i];
	dp[0][0] = 1;
	for(int i = 1; i < (1 << n); i++){
		w = js(i);
	    for(int j = 1; j <= n; j++)
	        if((1 << j - 1) & i)
	            for(int k = 0; k <= n; k++)
	                if(dp[i ^ (1 << j - 1)][k]){
	                	if(w - 1 - k < a[j] && s[w - 1] == '1') dp[i][k + 1] += dp[i ^ (1 << j - 1)][k], dp[i][k + 1] %= md;
	                	else dp[i][k] += dp[i ^ (1 << j - 1)][k], dp[i][k] %= md;
					}
	}
    for(int i = m; i <= n; i++)
	    ans += dp[(1 << n) - 1][i], ans %= md;
    cout << ans << "\n";    
	return 0;
} 
