#include <bits/stdc++.h>
using namespace std ;
long long n,m,r,cnt=1,a,b ;
long long s[110],t[20][20] ;
bool cmp (int x,int y) {
	return x>y ;
}
int main () {
	freopen("seat.in","r",stdin) ;
	freopen("seat.out","w",stdout) ;
	cin >> n >> m ;
	for (int i=1;i<=n*m;i++) {
		cin >> s[i] ;
	}
	r=s[1] ;
	sort(s+1,s+n*m+1,cmp) ;
	for (int j=1;j<=m;j++) {
		if (j%2==0) {
			for (int i=n;i>=1;i--) {
				t[i][j]=s[cnt] ;
				cnt++ ;
			}
		}
		else {
			for (int i=1;i<=n;i++) {
				t[i][j]=s[cnt] ;
				cnt++ ;
			}
		}
	}
	for (int j=1;j<=m;j++) {
		for (int i=1;i<=n;i++) {
			if (t[i][j]==r) {
				cout << j << " " << i ;
				break ;
			}
		}
	}
}
