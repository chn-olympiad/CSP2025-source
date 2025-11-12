#include<bits/stdc++.h>
using namespace std;
using LL = long long;
LL big(LL a, LL b){
	return (a > b ? a : b);
}
const LL MOD = 998244353;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	
	LL n;cin >> n;
	vector<LL> A(n + 1);
	for(LL i = 1;i <= n; i++){
		cin >> A[i];
	}
	// 2 ^ n
	LL k = 1;
	for(LL i = 1;i <= n; i++){
		k *= 2;
	}
	LL sum = 0, lar, ans = 0;
	for(LL i = 1;i <= k; i++){
		sum = 0, lar = LONG_LONG_MIN;
		LL cnt = 0;
		for(LL now = i;now > 0; now /= 2){
		    // cout << now << ' ';
			cnt++;
			if(now & 1 == 1){
				sum += A[cnt];
				lar = max(lar, A[cnt]);
		    }
		}
		
		if((sum > 2 * lar) && cnt >= 3) {
			ans = ans % MOD + 1;
			
		}
	
	}
	cout << ans;
	return 0;
}
/*




*/