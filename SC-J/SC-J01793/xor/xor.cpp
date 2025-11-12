#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N= 5e5+10;
int a[N] ,sum[N];
signed main() {
	freopen("xor.in","r",stdin) ;
	freopen("xor.out","w",stdout) ;
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0) ;
	int n ,k; cin >> n >> k;
	sum[0] = 0;
	for(int i=1;i <= n; ++i) {
		cin >> a[i] ;
		sum[i] = (sum[i-1] ^ a[i]); 
	}int ans =0;
	for(int i=1;i <= n;) {
		int l= i,r =i;
		bool f = 0; 
		while(r <= n) {
			int x = (sum[r] ^ sum[l-1]) ;
			if(x == k) {
				ans ++;f= 1;
				break ;
			}else r ++;
		}
		if(f == 1)i += (r-l +1);
		else i ++;
	}cout << ans;
	return 0;
}
//
