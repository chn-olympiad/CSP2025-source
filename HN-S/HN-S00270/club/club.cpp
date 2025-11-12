#include<bits/stdc++.h>
using namespace std;
long long a[100006][6], f[1006][506][506];
int main(){
	freopen("club2.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	long long t;
	cin >> t;
	while (t--) {
		long long n;
		cin >> n;
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= 3; j++) {
				cin >> a[i][j];
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j <= n / 2; j++) {
				for (int k = 0; k <= n / 2; k++) {
					if (j != 0 && k != 0)f[i][j][k] = max (f[i - 1][j][k] + a[i][3], max (f[i - 1][j - 1][k] + a[i][1], f[i - 1][j][k - 1] + a[i][2]));
					else if (j != 0)f[i][j][k] = max (f[i - 1][j][k] + a[i][3], f[i - 1][j - 1][k] + a[i][1]);
					else if (k != 0)f[i][j][k] = max (f[i - 1][j][k] + a[i][3], f[i - 1][j][k - 1] + a[i][2]);
					else f[i][j][k] = f[i - 1][j][k] + a[i][3];
				}
			}
		}
		long long maxx = 0;
		for (int i = 0; i <= n / 2; i++) {
			for (int j = 0; j <= n / 2; j++) {
				if (n - i - j >n / 2)continue;
				if (f[n][i][j] > maxx) {
					maxx = f[n][i][j];
				}
			}
		}
		cout << maxx << '\n';
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
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
