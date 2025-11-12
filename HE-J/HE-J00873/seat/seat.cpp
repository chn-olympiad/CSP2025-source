#include<bits/stdc++.h>
using namespace std;
int n,m;
int r;
int a[110];
int main() {
	freopen("seat.in""w""stdin");
	freopen("seat.out""r""stdout");
	cin >> n >> m;
	for(int i = 0;i < n * m;i++) {
		cin >> a[i];
	} 
	r = a[0];
	sort(a,a + n * m);
	int j = 1,k = 1;
	for(int i = n * m - 1;i >= 0;i--) {
		if(a[i] == r) {
			int x = n * m - i;
			cout << (x - 1) / n + 1 << " " ;
			if(((x - 1) / n) % 2 == 0) {
				if(x % n == 0) {
					cout << n;
				} else {
					cout << x % n;
				} 
			} else {
				cout << n - (x - 1) % n;
			}
			break;
		}
	}
	return 0;
}
