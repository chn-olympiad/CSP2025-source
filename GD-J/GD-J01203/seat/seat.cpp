#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long
 
bool cmp(int x, int y) {
	return x > y;
}
int n, m, pam[144], a[12][12];
int zt;
signed main() {
	freopen ("seat.in", "r", stdin);
	freopen ("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < n * m; i++) {
		cin >> pam[i];
	}
	int b = pam[0];
	sort (pam, pam + n * m, cmp);
	for (int i = 0, j = 0, k = 0; k < n * m; k++) {
		if (i == n - 1 && j % 2 == 0) {
			zt = 1;
			a[i][j] = pam[k];
			j++;
			continue;
		}
		if (i == 0 && j % 2 != 0) {
			zt = 0;
			a[i][j] = pam[k];
			j++;
			continue;
		}
		else {
			if (zt == 1) {
				a[i][j] = pam[k];
				i--;
			}
			else {
				a[i][j] = pam[k];
				i++;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == b) {
				cout << j + 1 << " " << i + 1;
				return 0;
			}
		}
	}
	fclose (stdin);
	fclose (stdout);
	return 0;
}
