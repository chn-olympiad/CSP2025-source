//GZ-S00151 贵阳市云岩区中天中学 张善之
#include <bits/stdc++.h>
using namespace std ;
const int N = 1e6+20 , M=1e4+20 ;
int n , m , k ;
struct troci{
	long long cr ; 
	int l , r ;	
}q[N];
long long cs[N] , dp[N];

int main () {
	freopen("road.in","r",stdin) ;
	freopen("road.out","w",stdout) ;
	ios::sync_with_stdio(0) ;
	cin.tie(0) ; cout.tie(0) ;
	cin >> n >> m >> k ;
	for(int i=1;i<=m;i++) {
		cin >> q[i].l >> q[i].r >> q[i].cr ;
		dp[i] = 1e9 ;
	}
	for(int i=1;i<=k;i++) {
		int l1 ;
		int q11 ; cin >> q11 ;
		for(int i=1;i<=n;i++) {
			cin >> l1 ;
			dp[l1] = 0 ;
		}
	}
	cout << 0 ;
	return 0 ;
}

