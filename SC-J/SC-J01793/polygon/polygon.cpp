#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353 ,MAXN = 5050;
int a[MAXN] ,dp[505][505] ;
int zhehuc(int x ,int y) {
	x = min(y -x ,x) ;
	int fz =1,fm =1;
	int cnt = 1;
	for(int i = y;cnt <= x; --i) {
		fz = fz * i;
		cnt ++;
	}
	for(int i= 1;i <= x;++i) 
		fm = fm * i;
	return fz / fm ;
}
signed main() {
	freopen("polygon.in","r",stdin) ;
	freopen("polygon.out","w",stdout) ;
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0) ;
	int n ; cin >> n;
	if(n <= 2) {
		cout << 0; return 0;
	}
	int maxx = -1 ,sum= 0;
	for(int i=1;i <= n; ++i) {
		cin >> a[i] ;
		maxx = max(a[i] ,maxx );
		sum = a[i] + sum;
	}
	if(n == 3){
		if(maxx < sum/ 2) cout << 1;
		else cout << 0;
		return 0;
	}int ans = 0;
	for(int i = 3;i <= n; ++i) {
		ans += zhehuc(i ,n) ;
	}cout << ans % mod;
	return 0;
}