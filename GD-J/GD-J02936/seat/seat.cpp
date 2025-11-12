#include <bits/stdc++.h>
using namespace std;

int n, m, g, c = 1, r = 1, a[1000];
double cc = 1;

int main() {
	
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	cin >> n >> m;
	cin >> a[1];
	g = a[1];
	for(int i = 2; i <= n * m; i++) {
		cin >> a[i];
		if(a[i] > g) cc++;
	}
	
	c = ceil(cc / n);

	//cout << c;
	if(c % 2 != 0) {
		if(((int)cc % n) != 0) r = (int)cc % n;
		else r = n;
	}
	else {
		//cout << cc;
		//cout << 3 % 2 << " ";
		r = n - (int)cc % n + 1;
	}
	
	cout << c << " " << r;
	
	return 0;
} 
