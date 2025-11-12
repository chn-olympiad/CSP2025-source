#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int t, n, a[4][N];
bool flag;
int mmax(int i) {
	return max(a[1][i], max(a[2][i], a[3][i]));
}
int mmin(int i) {
	return min(a[1][i], min(a[2][i], a[3][i]));
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> t;
	while(t --) {
		cin >> n;
		for(int i = 1;i <= n;i ++) {
			cin >> a[1][i] >> a[2][i] >> a[3][i];
			if(a[2][i] != 0 || a[3][i] != 0) {
				flag = 1;
			}
		}
		int ans = 0;		
		if(n == 2) {
			int max_a = 0, max_b = 0, ida = 0, idb = 0, mida = 0, midb = 0, flaga = 0, flagb = 0;
			for(int i = 1;i <= n;i ++) {
				if(a[i][1] > max_a) {
					mida = max_a;
					max_a = a[i][1];
					ida = i;
					flaga = 1;
				} else if(a[i][1] == max_a) {
					flaga ++;
				}
				if(a[i][2] > max_b) {
					midb = max_b;
					max_b = a[i][2];
					idb = i;
					flagb = 1;
				} else if(a[i][2] == max_b) {
					flagb ++;
				}
				if(ida == idb) {
					if(flaga == 1 && flagb == 1) {
						if(max_a > max_b) {
						    cout << max_a + midb;
						} else {
							cout << max_b + mida;
						}
						return 0;
					}
				}
				cout << max_a + max_b;
			}
		} else if(!flag) {
			sort(a[1] + 1,a[1] + n + 1);
			for(int i = 1;i <= n / 2;i ++) {
				ans += a[i][1];
			}
			cout << ans << "\n";
		} else {
			for(int i = 1;i <= n;i ++) {
				ans += mmax(i); 
			}
			cout << ans << "\n";
		}
	}
	return 0;
}
