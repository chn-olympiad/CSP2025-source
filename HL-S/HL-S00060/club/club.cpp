#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int t, n, a[N][4], f[205][105][105];
bool A=1, B=1;
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			if (a[i][2] != 0 || a[i][3] != 0) A = 0;
			if (a[i][3] != 0) B = 0;
		}
		if(A) {
			int b[N];
			for (int i = 1; i <= n; i++) {
				b[i] = a[i][1];
			}
			sort(b+1, b+n+1);
			int ans = 0;
			for (int i = n/2+1; i <= n; i++) {
				ans += b[i];
			}
			cout << ans << endl;
			continue;
		}
		f[1][1][0] = a[1][1];
		f[1][0][1] = a[1][2];
		f[1][0][0] = a[1][3];
		int ans = 0;
		for (int i = 2; i <= n; i++) {
			for (int j = 0; j <= n/2; j++) {
				for (int k = 0; k <= n/2; k++) {
					if (i-j-k > n/2) continue;
					if (j == 0 && k == 0) f[i][j][k] = f[i-1][j][k] + a[i][3];
					else if (j == 0) f[i][j][k] = max(f[i-1][j][k-1]+a[i][2], f[i-1][j][k]+a[i][3]);
					else if (k == 0) f[i][j][k] = max(f[i-1][j-1][k]+a[i][1], f[i-1][j][k]+a[i][3]);
					else f[i][j][k] = max(max(f[i-1][j-1][k]+a[i][1], f[i-1][j][k-1]+a[i][2]), f[i-1][j][k]+a[i][3]);
					if (i == n) ans = max(f[i][j][k], ans);
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}

