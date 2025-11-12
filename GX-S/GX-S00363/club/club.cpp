#include <bits/stdc++.h>
using namespace std;

const int m = 1e5 + 5;
	
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int a; cin >> a;
	while(a--) {
		int n, f[m][3], a1 = 0, a2 = 0, a3 = 0, ans = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> f[i][0] >> f[i][1] >> f[i][2];
		}
		for (int i = n; i >= 1; i--) {
			if(a1 >= n / 2) {
				for (int i = 1; i <= n; i++) f[i][0] = 0;
			} else if(a2 >= n / 2) {
				for (int i = 1; i <= n; i++) f[i][1] = 0;
			} else if(a3 >= n / 2) {
				for (int i = 1; i <= n; i++) f[i][2] = 0;
			}
			if (f[i][0] > f[i][1] && f[i][0] > f[i][2]){
				ans += f[i][0];
				a1++;
			} else if (f[i][1] > f[i][0] && f[i][1] > f[i][2]){
				ans += f[i][1];
				a2++;
			} else if (f[i][2] > f[i][0] && f[i][2] > f[i][1]){
				ans += f[i][2];
				a3++;
			}
			cout << ans;
		}
	}
	return 0;
}
