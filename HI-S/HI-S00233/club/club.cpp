#include <bits/stdc++.h>
using namespace std;
int N, n, a[100005][4], sum;
void dfs (int s, int ii, int jj, int a1, int a2, int a3) {
	s += a[ii][jj];
	if (ii == n) {
		if (s > sum) {
			sum = s;
		}
	} else {
		if (a1+1 <= n/2) dfs (s, ii+1, 1, a1+1, a2, a3);
		if (a2+1 <= n/2) dfs (s, ii+1, 2, a1, a2+1, a3);
		if (a3+1 <= n/2) dfs (s, ii+1, 3, a1, a2, a3+1);
	}
	return ;
}
int main () {
	freopen ("club.in", "r", stdin); 
	freopen ("club.out", "w", stdout);
	cin >> N;
	while (N--) {
		cin >> n;
		sum = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++) {
				cin >> a[i][j];
			}
		}
		dfs (0, 1, 1, 1, 0, 0);
		dfs (0, 1, 2, 0, 1, 0);
		dfs (0, 1, 3, 0, 0, 1);
		cout << sum << endl;
	}
	return 0;
} 
