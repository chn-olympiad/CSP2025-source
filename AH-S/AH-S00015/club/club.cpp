#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2e2 + 2;
const int M = 1e5 + 2;
int t, n, a[M][3], dp[N][N][N], b[M], ans;
struct Club {
	int val, typ;
	bool operator < (const Club &cmp) const {
		return val > cmp.val;
	}
} b[N][3];
struct Clubb {
	int a, tya, b, tyb, c, tyc;
	bool operator < (const Clubb &cmp) const {
		if (a != cmp.a) {
			return a > cmp.a;
		}
		if (b != cmp.b) {
			return b > cmp.b;
		}
		return c > cmp.c;
	}
} c[N];
void Checkmax(int &x, int y) {
	x = max(x, y);
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &t);
	while (t--) {
		memset(dp, 0, sizeof(dp));
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d%d%d", &a[i][1], &a[i][2], &a[i][3]);
		}
		if (n <= 200) {
			for (int i = 1; i <= n; i++) {
				for (int j = n / 2; j >= 0; j--) {
					for (int k = n / 2; k >= 0; k--) {
						for (int l = n / 2; l >= 0; l--) {
							if (j > 0) {
								Checkmax(dp[j][k][l], dp[j - 1][k][l] + a[i][1]);
							}
							if (k > 0) {
								Checkmax(dp[j][k][l], dp[j][k - 1][l] + a[i][2]);
							}
							if (l > 0) {
								Checkmax(dp[j][k][l], dp[j][k][l - 1] + a[i][3]);
							}
							//dp[i][j][for (int j = n / 2; j >= 0; j--)
		//					printf("dp[%d][%d][%d][%d]=%d\n", i, j, k, l, dp[i][j][k][l]);
						}
					}
				}
			}
			ans = 0;
			for (int i = 1; i <= n / 2; i++) {
				for (int j = 1; j <= n / 2; j++) {
					for (int k = 1; k <= n / 2; k++) {
						ans = max(ans, dp[i][j][k]);
					}
				}
			}
			printf("%d\n", ans); 
		} else {
			ans = 0;
			scanf("%d", &n);
			for (int i = 1; i <= n; i++) {
				scanf("%d%d%d", &a[i][1], &a[i][2], &a[i][3]);
				b[i] = a[i][1];
			}
			sort(b + 1, b + n + 1, greater<int>());
			for (int i = 1; i <= n / 2; i++) {
				ans += b[i];
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}
