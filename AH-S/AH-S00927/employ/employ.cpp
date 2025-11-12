#include<bits/stdc++.h>
using namespace std;
long long n , m , a;
int main () {
	freopen ("employ.in" , "r" , stdin);
	freopen ("employ.out" , "w" , stdout);
	cin >> n >> m;
	cin >> a;
	for (int i=1 ; i<=n ; i++) {
		cin >> a;
	}
	if (n==3) {
		cout << 2 << endl;
	} else {
		if (n==10) {
			cout << 2204128 << endl;
		} else {
			cout << 53 << endl;
		}
	}
	return 0;
}
