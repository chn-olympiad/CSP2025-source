#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int T , n , a[3][N] , dp[110][110][110];
struct node{
	int x , y , z;
} b[N];
bool cmp (node a , node b) {
	return a.x + b.y > a.y + b.x;
}
signed main () {
	freopen ("club.in" , "r" , stdin);
	freopen ("club.out" , "w" , stdout);
	ios::sync_with_stdio (0);
	cin.tie (0); cout.tie (0);
	cin >> T;
	while (T --) {
		cin >> n;
		for (int i = 1;i <= n;i ++) cin >> a[0][i] >> a[1][i] >> a[2][i];
		if (n <= 200) {
			memset (dp , 0 , sizeof dp);
			for (int i = 1;i <= n;i ++) {
				for (int b = n / 2;b >= 0;b --) {
					for (int c = n / 2;c >= 0;c --) {
						int d = i - b - c;
						if (d < 0 || d > n / 2) continue;
						if (b >= 1) dp[b][c][d] = max (dp[b][c][d] , dp[b - 1][c][d] + a[0][i]);
						if (c >= 1) dp[b][c][d] = max (dp[b][c][d] , dp[b][c - 1][d] + a[1][i]);
						if (d >= 1) dp[b][c][d] = max (dp[b][c][d] , dp[b][c][d - 1] + a[2][i]);
					}
				}
			}
			int ans = 0;
			for (int i = 1;i <= n / 2;i ++) {
				for (int j = 1;j <= n /2;j ++) {
					int z = n - i - j;
					if (z < 0 || z > n / 2) continue;
					ans = max (ans , dp[i][j][z]);
				}
			}
			cout << ans << '\n';
			continue;
		}
		int fb = 0 , fc = 0;
		for (int i = 1;i <= n;i ++) {
			if ( a[1][i] ) fb = 1;
			if ( a[2][i] ) fc = 1;
		}
		if (!fb && !fc) {
			sort (a[0] + 1 , a[0] + n + 1);
			int ans = 0;
			for (int i = 1;i <= n / 2;i ++) {
				ans += a[0][i];
			}
			cout << ans << '\n';
			continue;
		}
		if ( !fc ) {
			for (int i = 1;i <= n;i ++) {
				b[i].x = a[0][i];
				b[i].y = a[1][i];
			}
			sort (b + 1 , b + n + 1 , cmp);
			int ans = 0;
			for (int i = 1;i <= n / 2;i ++) ans += b[i].x;
			for (int i = n / 2 + 1;i <= n;i ++) ans += b[i].y;
			cout << ans << '\n';
		} 
	}
	
	
	return 0;
} 
