#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
int a,b[5005],dp[5005],dp1[5005],c,l,r,m,ans;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> a;
	for(int i = 1; i <= a; i++){
		cin >> b[i];
	}
	sort(b+1,b+1+a);
	dp[b[1]] = 1;
	for(int i = 2; i <= a-1; i++){
		for(int j = 5000; j >= 0; j--){
			if(dp[j] != 0 && j + b[i] <= 5000){
				dp[j + b[i]] += dp[j];
				dp1[j + b[i]] = dp[j];
			}
		}
		dp[b[i]]++;
		for(int j = 0; j <= 5000; j++){
			if(dp1[j] != 0){
				l = i+1;
				r = a;
				c = -1;
				while(l <= r){
					m = (l + r) / 2;
					if(b[m] >= j){
						r = m-1;
					}
					else{
						l = m+1;
						c = m;
					}
				}
				if(c == -1){
					continue;
				}
				ans += ((c - i) * dp1[j]);
				ans %= mod;
			}
		}
		for(int j = 0; j <= 5000; j++){
			dp1[j] = 0;
		}
	}
	cout << ans % mod;
	return 0;
} 
