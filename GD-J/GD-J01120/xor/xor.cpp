#include <bits/stdc++.h>
#define N 500005
using namespace std ;
int n , m , a[N] , pre[N] , f[N] , last[(1 << 20) + 5] , tmp = 0 , ans ;
int main() {

	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);

	ios :: sync_with_stdio(false) ;
	cin . tie(0) , cout . tie(0) ;
	
	cin >> n >> m ;
	for(int i = 1 ; i <= n ; i++) {
		cin >> a[i] ;
		pre[i] = pre[i - 1] ^ a[i] ;
	}
	
	memset(last , -1 , sizeof(last)) ;
	
	f[0] = 0 ;
	last[0] = 0 ;
	for(int i = 1 ; i <= n ; i++) {
		f[i] = f[i - 1] ;	
		if(last[pre[i] ^ m] != -1) {
			f[i] = max(f[i] , f[last[pre[i] ^ m]] + 1) ;
		}
		last[pre[i]] = i ;
	}
	
	cout << f[n] ;
	return 0 ;

}
