#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

ll n , m , a[10010] , r;
ll x = 1 , y = 1;

bool cmp(ll x , ll y) {
	return x > y;
}

int main () {
	freopen("seat.in" , "r" , stdin);
	freopen("seat.out" , "w" , stdout);
	scanf("%lld %lld" , &n , &m);
	for(ll i = 1;i <= n * m;i ++) {
		scanf("%lld" , &a[i]);
	}
	
	r = a[1];
	
	sort(a + 1 , a + n * m + 1 , cmp);
	bool f = 1;
	
	for(ll i = 1;i <= n * m;i ++) {
		if(a[i] == r) {
			if(x == n + 1) {
				x = n;
			}
			if(x == 0) {
				x = 1;
			}
			printf("%lld %lld" , y , x);
		}
		if(f == 1) {
			x ++;
			if(x == n + 1) {
				y ++;
				x --;
				f = !f;
			}
		} else {
			x --;
			if(x == 0) {
				y ++;
				x ++;
				f = !f;
			}
		}
	}
	return 0;
}