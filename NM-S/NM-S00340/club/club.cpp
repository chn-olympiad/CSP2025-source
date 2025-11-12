#include <bits/stdc++.h>

using namespace std;
int T;
int f[202][102][102][102];
int a[100005][4];	
int main ( ) {
	freopen("club.in", "r", stdin);
	freopen("clud.out", "w", stdout);
	cin >> T;
	while (T --) {
		int n;	
		cin >> n;
		int ans = -0x7fffffff;
		if (n <= 200) {
			for (int i = 1; i <= n; i ++) {
			for (int j = 1; j <= 3; j ++) cin >> a[i][j];
			}
			for (int i = 1; i <= n; i ++) {
			for (int j = 0; j <= (n >> 1); j ++) {
				for (int k = 0; k <= (n >> 1); k ++) {
					int l = i - j - k;
					if (l > (n >> 1)) continue;
					f[i][j][k][l] = 0; 
				}
			}
		} 
		
		for (int i = 1; i <= n; i ++) {
			for (int j = 0; j <= (n >> 1); j ++) {
				for (int k = 0; k <= (n >> 1); k ++) {
					if(j + k > i)continue;
					int l = i - j - k;
					if (l > (n >> 1)) continue;
					if (j >= 1) f[i][j][k][l] = max(f[i - 1][j - 1][k][l] + a[i][1], f[i][j][k][l]);
					if (k >= 1) f[i][j][k][l] = max(f[i][j][k][l], f[i - 1][j][k - 1][l] + a[i][2]);
					if (l >= 1) f[i][j][k][l] = max(f[i][j][k][l], f[i - 1][j][k][l - 1] + a[i][3]);
					if (i == n) {
						ans = max(ans, f[i][j][k][l]);
					}
				}
			}
		} 
			cout << ans << '\n';
		} else {
			int asn = 0;
			int xl[100005];
			for (int i = 1; i <= n; i ++) {
				int tr, op;
				cin >> xl[i] >> tr >> op;
			}
			sort(xl + 1, xl + 1 + n);
			for (int i = n; i > (n >> 1); i --) {
				asn += xl[i];
//				cout << xl[i] << " " ;
			}
			cout << asn << '\n';
		}
		
	}
	return 0;
} 

/*
3
4
0 1 0
0 1 0
0 2 0
0 2 0
4
4 2 1
3 2 4
5 3 4
3 5 1
2
10 9 8
4 0 0

1
6
3 0 0
9 0 0
6 0 0
7 0 0
5 0 0
10 0 0



---------> 26
*/
