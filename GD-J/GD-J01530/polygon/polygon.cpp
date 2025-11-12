#include<bits/stdc++.h>
using namespace std;
const int MOD = 998244353;

int n, a[5005], ans = 0, cnt = 0;

void dfs(int step, int sum, int maxn){
	if(step > n){
		if(sum > 2 * maxn)ans++;
		ans %= MOD;
		return ;
	}
	dfs(step+1, sum+a[step], max(maxn, a[step]));
	dfs(step+1, sum, maxn);
}

int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i=1; i<=n; i++) {
		cin >> a[i];
		if(a[i] == 1)cnt++;
	}
	if(n > 20){
		for(int i=3; i<=cnt; i++){
			int k = 1, d = 1;
			for(int j=1; j<=i; j++){
				k *= j, k %= MOD;
				d *= cnt - j + 1, d %= MOD;
			}
			ans += d / k;
			ans %= MOD; 
		}
		cout << ans;
		return 0;
	} 
	dfs(1, 0, 0);
	cout << ans;
	return 0;
}
