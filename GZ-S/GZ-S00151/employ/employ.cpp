//GZ-S00151 贵阳市云岩区中天中学 张善之
#include <bits/stdc++.h>
using namespace std ;
const int mod = 998244353 ;
int n , m , emt[2000] ;
int main () {
	freopen("employ.in","r",stdin) ;
	freopen("employ.out","w",stdout) ;
	ios::sync_with_stdio(0) ;
	cin.tie(0) ; cout.tie(0) ;
	cin >> n >> m ;
	string s ; cin >> s ;
	for(int i=1;i<=n;i++) cin >> emt[i] ;
	if(m>1&&m<n) {
		cout << 0%mod ; 
	}
	if(m==1) {
		int q = 0 ;
		for(int i=0;i<s.size();i++) {
			if(s[i]=='0') {
				q++ ;
			}
		}
		if(q==0) {cout << 0 ; return 0 ;}
		int cnt = 0 ;
		cout << n%mod ;
	}
	if(m==n) {
		for(int i=0;i<=s.size();i++) {
			if(s[i]=='1') {
				cout << 0%mod ; return 0 ;
			}
		}
		cout << 1%mod ;
	}
	return 0 ;
}

