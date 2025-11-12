#include <bits/stdc++.h>
using namespace std;

const int N = 2e4 + 10;
int a[N + 10][N + 10];

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

	int t, n, k;
	int ans = 0;
	int sum = 0;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++) {
				cin >> a[i][j];
				if (a[i][j] > n / 2) continue;
		    }
		    if (a[i][1] > a[i][2] && a[i][1] > a[i][3]) {
	    		ans = a[i][1];
			} else if (a[i][2] > a[i][1] && a[i][2] > a[i][3]) {
				ans = a[i][2];
			} else if (a[i][2] > a[i][1] && a[i][2] > a[i][3]){
				ans = a[i][3];
			}
			for (int b = 1;b <= t; b++) {
				sum = (a[i][1] + a[i][3]) * n / 2;
			}
	    }
	    cout << sum << endl;

    }
	return 0;
}
