#include <bits/stdc++.h>
using namespace std;
int t,n;
int max1 (int x, int y, int z) {
	return max (max(x,y),z);
}

int func (int n) {
	int m = 0,b[n],d = 0;
	int a[n][3];
	for (int i = 0; i < n; i++) {
		for (int j = 0;j < 3; j++) {
			cin >> a[i][j];
		}
	}
	int x, y, z;
	for (int i = 0; i < n; i++) {
		x = a[i][0],y = a[i][1],z = a[i][2];
		m += max1(x,y,z);
	}
	return m;
}

int main () {
	freopen ("club.in","r",stdin);
	freopen ("club.out","w",stdout);
	cin >> t;
	int b[t];
	for (int i = 0; i < t; i++) {
		cin >> n;
		b[i] = func(n);
	}
	for (int i = 0; i <= sizeof(b); i++) cout << b[i] << endl;
	return 0;
} 
