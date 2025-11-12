//Ren5Jie4Di4Ling5%
#include <bits/stdc++.h>
using namespace std;
int N = 1e5 + 5;
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while (t--) {
		int n, a[N][3], b[N][3], maxx[3] = {}, ans = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++) {
				cin >> a[i][j];
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++) {
				if (a[i][j] > maxx[j]) {
					maxx[j] = a[i][j];
				}	
			}
		}
		for (int i = 1; i <= n; i++)  {
			for (int j = 1; j <= 3; j++) {
				ans += maxx[j];
			}
		}
		cout << ans;
	}
	return 0;
}
/* 
3
4
4 2 1
3 2 4
5 3 4
3 5 1
184
0 1 0
0 1 0
0 2 0
0 2 0
362
10 9 8
4 0 0
*/
