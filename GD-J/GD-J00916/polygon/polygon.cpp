#include <bits/stdc++.h>
using namespace std ;
const long long MAXN=998244353 ;
long long n,a[6000],ans ;
int main () {
	freopen("polygon.in","r",stdin) ;
	freopen("polygon.out","w",stdout) ;
	cin >> n ;
	for (int i=1;i<=n;i++) {
		cin >> a[i] ;
	}
	for (int i=n;i>=3;i++) {
		ans=ans+i-2 ;
	}
	cout << ans ;
}
