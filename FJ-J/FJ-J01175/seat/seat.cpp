#include<bits/stdc++.h> 
using namespace std;
long long a[200];
long long b[200][200];
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	long long n, m;
	cin >> n >> m;
	long long mm = m;
	long long ml;
	for (long long i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	ml = a[1];
	sort(a + 1, a + n + 1);
	long long i = 1;
	long long j = 1;
	long long ii = 1;
	long long jj = 1;	
	if (m % 2 == 0) {			
		while(m / 2) {
			for (long long k = 1; k <= n; k++) {
				b[k][j] = a[i];
				i++;
			}
			j++;
			for (long long k = n; k >= 1; k--) {
				b[k][j] = a[i];
				i++;
			}
		}
	} else {
		m--;
		while (m / 2) {
			for (long long k = 1; k <= n; k++) {
				b[k][jj] = a[ii];
				ii++;
			}
			jj++;
			for (long long k = n; k >= 1; k--) {
				b[k][jj] = a[ii];
				ii++;
			}
		}
		for (long long k = 1; k <= n; k++) {
			b[k][mm] = a[ii];
			ii++;
		}
	}
	for (long long x = 1; x <= n; x++) {
		for (long long y = 1; y <= mm; y++) {
			if (b[x][y] == ml) {
				cout << x << " " << y;				
			}
		}
	}	
	return 0;
}
