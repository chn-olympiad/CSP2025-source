#include <bits/stdc++.h>
using namespace std;
long long a[105];
long long s[15][15];
bool cmp (long long x,long long y) {
	if (x < y) return y < x;
	return x;
}
int main () {
	freopen ("seat.in","r",stdin);
	freopen ("seat.out","w",stdout);
	long long n,m;
	cin >> n >> m;
	for (int i = 1; i <= n*m; i++) {
		cin >> a[i]; 
	}
	long long x = a[1];
	sort (a +1, a + n*m + 1, cmp);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j+=2) {
			s[i][j] = a[(j - 1) * n + i];
		}
		for (int k = 2; k <= m; k+=2) {
			s[i][k] = a[k * n + 1 - i];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1;  j <= m; j ++) {
			if (s[i][j] == x) {
				cout << j << ' ' << i;
				return 0;
			}
		}
	}
	return 0;
} 
