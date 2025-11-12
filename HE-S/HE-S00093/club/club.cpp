#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int T;
void solve() {
	int n;
	int ans = 0;
	cin >> n;
	int c[N];
	int a[N][4];
	bool f = false;
	for(int i = 1;i <= n;i ++ ) {
		for(int j = 1;j <= 3;j ++ ) {
			cin >> a[i][j];
		}
		if(a[i][2] != 0 || a[i][3] != 0) f = true;
		c[i] = max(a[i][1], max(a[i][2], a[i][3]));
	}
	sort(c + 1, c + n + 1);
	if(!f) {
		for(int i = n;i > n / 2;i -- ) {
			ans += c[i];
		}
		cout << ans;
	}
	else if(f) {
		int d[4];
		for(int i = n;i >= 1;i -- ) {
			for(int k = 1;k <= n;k ++ ) {
				for(int j = 1;j <= 3;j ++ ) {
					if(a[k][j] == c[i]) {
						if(d[j] < n / 2) {
							d[j] ++ ;
							ans += c[i];
						}
						else {
							if(a[k][1] == c[i] && a[k][2] > a[k][3]) {
								if(d[2] < n / 2) {
									ans += a[k][2];
									d[2] ++ ;
								}
								else {
									ans += a[k][3];
									d[3] ++ ;
								}
							}
							else if(a[k][1] == c[i] && a[k][3] > a[k][2]) {
								if(d[3] < n / 2) {
									ans += a[k][3];
									d[3] ++ ;
								}
								else {
									ans += a[k][2];
									d[2] ++ ;
								}
							}
							else if(a[k][2] == c[i] && a[k][3] > a[k][1]) {
								if(d[3] < n / 2) {
									ans += a[k][3];
									d[3] ++ ;
								}
								else {
									ans += a[k][1];
									d[1] ++ ;
								}
							}
							else if(a[k][2] == c[i] && a[k][1] > a[k][3]) {
								if(d[1] < n / 2) {
									ans += a[k][1];
									d[1] ++ ;
								}
								else {
									ans += a[k][3];
									d[3] ++ ;
								}
							}
							else if(a[k][3] == c[i] && a[k][1] > a[k][2]) {
								if(d[1] < n / 2) {
									ans += a[k][1];
									d[1] ++ ;
								}
								else {
									ans += a[k][2];
									d[2] ++ ;
								}
							}
							else if(a[k][3] == c[i] && a[k][2] > a[k][1]) {
								if(d[2] < n / 2) {
									ans += a[k][2];
									d[2] ++ ;
								}
								else {
									ans += a[k][1];
									d[1] ++ ;
								}
							}
						}
					}
				}
			}
		}
		cout << ans;
	}
}
signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while(T -- ) {
		solve();
	}
	return 0;
}
