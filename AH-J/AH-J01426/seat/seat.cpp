#include<bits/stdc++.h>
using namespace std;
int n , m , s[20][20] , a[110] , t , q=1;
bool cmp (int x , int y) {
	return x>y;
}
int main () {
	freopen ("seat.in" , "r" , stdin);
	freopen ("seat.out" , "w" , stdout);
	cin >> n >> m;
	for (int i=1 ; i<=n*m ; i++) {
		cin >> a[i];
	}
	t=a[1];
	sort (a+1 , a+1+n*m , cmp);
	for (int i=1 ; i<=m ; i++) {
		if (i%2==1) {
			for (int j=1 ; j<=n ; j++) {
				s[i][j]=a[q++];
			}
		} else {
			for (int j=n ; j>=1 ; j--) {
				s[i][j]=a[q++];
			}
		}
	}
	for (int i=1 ; i<=m ; i++) {
		for (int j=1 ; j<=n ; j++) {
			if (s[i][j]==t) {
				cout << i << ' ' << j << endl;
			}
		}
	}
	return 0;
}
