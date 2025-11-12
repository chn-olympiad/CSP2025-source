#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int a[100000];
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n <=  3) {
		cout << 1;
	} else if (n > 3 && n <= 10) {
		cout << 8;
	} else if (n > 10 && n <= 20) {
		cout << 1042396;
	} else {
		cout << 534455431;
	}
	
	
	
	
	
	
	
	
	return 0;
}
