#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 7;

ll n , k , a[N];
ll ans;

int main() {
	freopen("xor.in" , "r" , stdin);
	freopen("xor.out" , "w" , stdout);
	scanf("%lld%lld" , &n , &k);
	for(int i = 1 ; i <= n ; i++) {
	 	scanf("%lld" , &a[i]);
	}
	ll left = 1 , right = 1 , value = 0;
	while(right <= n) {
		if(left == right) {
			value = a[right];
		} else {
			for(int i = left ; i <= right ; i++) {
				value = value ^ a[i];
			}
		}
		if(value == k) {
			ans++;
			left = right + 1;
			right = left;
		} else {
			right++;
		}
		value = 0;
		if(right == n + 1 && left < n) {
			left++;
			right = left;
		}
	}
	printf("%lld" , ans);
	return 0;
}

