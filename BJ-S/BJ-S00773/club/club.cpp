#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 2005,K = 1e5+5,M = 4;
int T;
int n,a[K][M];//,f[2][M];
int f[2][N / 2][N / 2];
int b[K];
int c[K][2];
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> T;
	while (T--) {
		cin >> n;
		if (n > N) {
			int x,y;
			cin >> x >> x >> y;
			if (x == 0) {
				b[0] = y;
				for (int i = 1;i < n;i++) {
					cin >> b[i];
				}
				int ans = 0;
				sort(b,b + n,greater<int>());
				for (int i = 0;i < n / 2;i++) {
					ans += b[i];
				}
				cout << ans << endl;
			}/* else {
				
			}*/
		} else {
			for (int i = 1;i <= n;i++) {
				cin >> a[i][1] >> a[i][2] >> a[i][3];
			}
			f[0][0][0] = 0;
			for (int i = 1;i <= n;i++) {
				for (int j = 0;j <= i && j <= n / 2;j++) {
					for (int k = 0;k + j <= i && k <= n / 2;k++) {
						int l = i - k - j;
						if (l > n / 2) {
							continue;
						}
						f[1][j][k] = 0;
						if (j > 0) {
							f[1][j][k] = max(f[0][j - 1][k] + a[i][1],
							f[1][j][k]);
						}
						if (k > 0) {
							f[1][j][k] = max(f[0][j][k - 1] + a[i][2],
							f[1][j][k]);
						}
						if (l > 0) {
							f[1][j][k] = max(f[0][j][k] + a[i][3],
							f[1][j][k]);
						}
						//cout << i << ' ' << j << ' ' << k << ' ' << l << ' ' << f[i][j][k][l] << endl;
					}
				}
				memcpy(f[0],f[1],sizeof(f[1]));
			}
			int i = n,ans = 0;
			for (int j = 0;j <= i && j <= n / 2;j++) {
				for (int k = 0;k + j <= i && k <= n / 2;k++) {
					int l = i - k - j;
					if (l > n / 2) {
						continue;
					}
					ans = max(ans,f[1][j][k]);
				}
			}
			cout << ans << endl;
		}
	}
	return 0;
}