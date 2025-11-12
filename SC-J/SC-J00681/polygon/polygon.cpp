#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;

ll n , ans = 0;
ll dp[10010] , a[10010];

int main () {
	freopen("polygon.in" , "r" , stdin);
	freopen("polygon.out" , "w" , stdout);
	scanf("%lld"  , &n);
	for(ll i = 1;i <= n;i ++) {
		scanf("%lld" , &a[i]);
	}
	
	for(ll i = 1;i < n * 2;i ++) {
		ll tmp = 0 , tmp_i = i;
		while(tmp_i > 0) {
			tmp ++ ;
			dp[tmp] = tmp_i % 2;
			tmp_i /= 2;
		}
		
		ll sum = 0 , maxn = -0x3f3f3f3f3f;
		
		for(ll j = 1;j <= n;j ++) {
			if(dp[j] == 1) {
				sum += a[j];
			}
		}
		
		for(ll j = 1;j <= n;j ++) {
			if(dp[j] == 1) {
				if(maxn >= a[j]) {
					maxn = a[j];
				}
			}
		}
		
		if(sum > maxn * 2) {
			ans ++;
		}
	}
	printf("%lld" , ans);
	return 0;
}