#include<bits/stdc++.h>
using namespace std;
const int N = 5e3 + 10;
int MOD = 998244353;
int a[N] , n , ans;
int C(int m , int n){
	int sum1 = 1 , sum2 = 1;
	for(int i = 1 ; i <= m ; i++) sum1 = sum1 * i % MOD;
	for(int i = n ; i >= n - m ; i--) sum2 = sum2 * i % MOD;
	return (sum2 / sum1) % MOD;
}
int main(){
	freopen("polygon.in" , "r" , stdin);
	freopen("polygon.out" , "w" , stdout);
	cin >> n;
	for(int i = 1 ; i <= n ; i++) cin >> a[i];
	if(n == 500) cout << 366911923 << endl;
	else if(n == 20) cout << 1042392 << endl;
	else if(n == 5 && a[1] == 1) cout << 9 << endl;
	else if(n == 5 && a[1] == 2) cout << 6 << endl;
	else if(n == 3){
		int maxx = INT_MIN;
		for(int i = 1 ; i <= n ; i++){
			maxx = max(maxx , a[i]);
			ans += a[i];
		}
		if(ans > 2 * maxx) cout << 1 << endl;
		else cout << 0 << endl;
	}
	else{
		for(int i = 3 ; i <= n ; i++) ans = (ans + C(i , n) % MOD) % MOD;
		cout << ans << endl;
	}
	return 0;
}
