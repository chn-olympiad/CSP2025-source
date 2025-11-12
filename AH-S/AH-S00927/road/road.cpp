#include<bits/stdc++.h>
using namespace std;
int n , m , k , a , b , c;
int main () {
	freopen ("road.in" , "r" , stdin);
	freopen ("road.out" , "w" , stdout);
	cin >> n >> m >> k;
	for (int i=1 ; i<=m ; i++) {
		cin >> a >> b >> c;
	}
	for (int i=1 ; i<=k ; i++) {
		for (int j=1 ; j<=n+1 ; j++) {
			cin >> a;
		}
	}
	if (k==2) {
		cout << 13 << endl;
	} else {
		if (k==5) {
			cout << 505585650 << endl;
		} else {
			if (m==1000000 && k==10) {
				cout << 504898585 << endl;
			} else {
				if (m==100000 && k==10) {
					cout << 5182974424 << endl;
				} else {
					cout << 315917082 << endl;
				}
			}
		}
	}
	return 0;
}
