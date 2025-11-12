#include<bits/stdc++.h>
using namespace std;
int n, m, a[110];
bool cmp(int x, int y) {
	return x > y;
}
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i=1; i<=n*m; i++) {
		cin >> a[i];
	}
	
	bool f = 1;
	for(int i=1; i<=n*m; i++) {
		if(a[i] != i) {
			f = 0;
			break;
		}
	} if(f == 1) {
		cout << m << " " << (m%2 ? n : 1) << endl;
		return 0;
	}
	f = 1;
	for(int i=1; i<=n*m; i++) {
		if(a[i] != n * m - i + 1) {
			f = 0;
			break;
		}
	} if(f == 1) {
		cout << 1 << " " << 1 << endl;
		return 0;
	}
	
	int p = a[1];
	sort(a+1, a+n*m+1, cmp);
	for(int i=1; i<=n*m; i++) {
		if(a[i] == p) {
			p = i;
		}
	}
	for(int i=1; i<=m; i++) {
		if(p <= i*n) {
			if(i % 2) {
				cout << i << " " << p - (i-1) * n << endl;
			} else {
				cout << i << " " << n - (p - (i-1) * n) + 1 << endl;
			}
			return 0;
		}
	}
	return 0;
}
