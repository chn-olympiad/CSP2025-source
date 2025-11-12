#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int n, k, a[N], ans, x, dp[N], l, sp1 = 1, sp2 = 1;
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		if(a[i] != 1) sp1 = 0;
		if(a[i] > 1) sp2 = 0;
	} 
	if(sp1){
		cout << n / 2;
		return 0;
	}
	if(sp2){
		if(k == 0){
			for(int i = 1; i <= n; i++){
				if(a[i] == 0) dp[i] = max(dp[i], dp[i - 1] + 1);
				else dp[i + 1] = max(dp[i + 1], dp[i - 1] + 1);
			}
			cout << dp[n];
		}else{
			for(int i = 1; i <= n; i++) ans += a[i];
			cout << ans;
		}
		return 0;
	}		
	
	for(int i = 1; i <= n; i++){
		if(a[i] == k) dp[i] = dp[i - 1] + 1;
			l = 1, x = 0;
				for(int j = l; j <= i; j++){
					x ^= a[j];
					if(x == k){
						dp[j] = max(dp[j], dp[j - 1] + 1);
						l = j;
						break;
					}
				}	
	}
	cout << dp[n];
	return 0;
}
