#include <bits/stdc++.h>
using namespace std ;
long long n,k,s[500010],ans,flag=1 ;
long long d[500010],vis[500010] ;
int main () {
	freopen("xor.in","r",stdin) ;
	freopen("xor.out","w",stdout) ;
	cin >> n >> k ;
	for (int i=1;i<=n;i++) {
		cin >> s[i] ;
		d[i]=s[i]^d[i-1] ;
	}
	for (long long i=1;i<=n;i++) {
		for (long long j=i;j<=n;j++) {
			for (long long k=i;k<=j;k++) {
				if (vis[k]==1) {
					flag=0 ;
					break ;
				}
			}
			long long a=d[i-1]^d[j] ;
			if (a==k && flag) {
				ans++ ;
				for (long long w=i;w<=j;w++) {
					vis[w]=1 ;
				}
			}
			flag=1 ;
		}
	}
	cout << ans ;
}
