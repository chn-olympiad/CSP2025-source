#include<bits/stdc++.h>
using namespace std;
int n , a[5010] , h , maxn;
int main () {
	freopen ("polygon.in" , "r" , stdin);
	freopen ("polygon.out" , "w" , stdout);
	cin >> n;
	for (int i=1 ; i<=n ; i++) {
		cin >> a[i];
		h+=a[i];
		if (maxn<a[i]) {
			maxn=a[i];
		}
	}
	if (h>maxn*2) {
		cout << 1 << endl;
	} else {
		cout << 0 << endl;
	}
	return 0;
}
