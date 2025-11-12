#include <bits/stdc++.h>
using namespace std;
const long long N = 998244353;
long long n, ans = 0, m;
long long a[50005], dp[50005], b[5005];
long long c(long long x, long long y){
	long long sum = 1, cnt = 1;
	for(int i = y - x + 1 ; i <= y ; i++){
		sum *= i;
	}
	for(int i = 1 ; i <= x ; i++){
		cnt *= i;
	}
	return (sum / cnt % N);
}
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	if(n == 3){
		for(int i = 1 ; i <= n ; i++){
			cin >> a[i];
			dp[i] = a[i] + dp[i - 1];
			m = max(m, a[i]);
		}
		if(dp[n] > m * 2){
			cout << 1;
		}else{
			cout << 0;
		}
	}
	if(n < 3){
		cout << 0;
	}
	
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i];	
	}
	int flag = 0;
	for(int i = 1 ; i <= 5000 ; i++){
		if(b[i] && (i > 1)){
			flag = 1;
		}
	}
	if(!flag){
		for(int i = 3 ; i <= n ; i++){
			ans += (c(i,n)) % N;
			ans %= N;
		}
		cout << ans;
	}
	return 0;
}
