#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main() {
	
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	
	cin >> n >> m;
	int a[n * m];
	int da;
	int d = 0;
	int R = a[0];
	int c[n * m];
	
	for(int i = 0; i < n * m; i++) {
		cin >> a[i];
	}
	
	da = a[1];
	
	for (int i = 0; i <= n*m; i++) {
		if (da > a[i]) {
			if (a[i] == a[0]) {
				break;
			}
		}
		if (da < a[i]) {
			da = a[i];
		}
	}
	
	c[0] = da;
	
	for (int i = 1; i <= n*m; i++) {
		if (a[i] > a[0]) {
			d++;
		}
		if (a[i] == a[0]) {
			cout << d << endl;
		}
	}
	
	// cout << d << endl;
	
	int p = 1,o = 1;
	
	bool ok = true;
	
	bool abc = true;
	
	for (int i = 1; i < d; i++) {
		if (ok == true) {
			if (p == n) {
				ok = false;
				o++;
			}
			if (p < n) {
				p++;
			}
		}
		
		if (ok != true) {
			if (p == 1) {
				ok = true;
				o++;
			}
			if (p > 1) {
				p--;
			}
			
		}
	}
	
	
	cout << o << " " << p << endl;
	
	
	return 0;
}
