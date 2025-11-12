#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

ll n , p , k;

int main () {
	freopen("xot.in" , "r" , stdin);
	freopen("xor.out" , "w" , stdout);
	cin >> n >> k;
	for(ll i = 1;i <= n;i ++) {
		cin >> p;
	}
	if(n % 2 == 0) {
		printf("%lld" , n - 1);
	} else {
		printf("%lld" , n);
	}
	return 0;
}