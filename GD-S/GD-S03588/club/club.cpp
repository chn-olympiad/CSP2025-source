#include <cstdio>
#include <algorithm>
using namespace std;

int T, n, a[100001][5], ans, f[101][101][101];
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		ans = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= 3; j++)
				scanf("%d", &a[i][j]);
		for (int j = n / 2; j >= 0; j--)
			for (int l = n / 2; l >= 0; l--)
				for (int k = n / 2; k >= 0; k--)
					f[j][l][k] = 0;
		for (int i = 1; i <= n; i++)
			for (int j = n / 2; j >= 0; j--)
				for (int l = n / 2; l >= 0; l--)
					for (int k = n / 2; k >= 0; k--) {
						if (j > 0)
							f[j][l][k] = f[j - 1][l][k] + a[i][1];
						if (l > 0)
							f[j][l][k] = max(f[j][l][k], f[j][l - 1][k] + a[i][2]);
						if (k > 0)
							f[j][l][k] = max(f[j][l][k], f[j][l][k - 1] + a[i][3]);
					}
		printf("%d\n", f[n / 2][n / 2][n / 2]);
	}
	return 0;
}
