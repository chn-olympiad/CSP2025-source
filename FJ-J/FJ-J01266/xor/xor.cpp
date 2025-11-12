#include <bits/stdc++.h>
using namespace std;
int n,xi,xj,ans;
int a[500005];
int f[5005][5005];
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		f[i][i] = a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			f[i][j] = f[i][j - 1] & a[j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			if (f[i][j] == k) {
				if (i > xi) {
					xi = 0;
					xj = 0;
				}
				if (xi > 0 && xj > 0) ans++;
				xi = i;
				xj = j;
				i = j + 1;
			}
		}
	}
	cout << ans;
	return 0;
} 
