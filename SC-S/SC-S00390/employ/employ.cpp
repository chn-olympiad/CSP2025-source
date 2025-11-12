#include <cstdio>
#include <vector>
const int N = 505, S = (1 << 19) + 5, M = 25;
typedef long long ll;
const ll Q = 998244353;
int len[S];
ll f[2][M][S];
int n, m, u;
int a[N], c[N];
std::vector < int > ts[N];
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) {
		char t;
		scanf(" %c", &t);
		a[i] = t - '0';
	}
	for(int i = 1; i <= n; i++) scanf("%d", &c[i]);
//	if(n <= 18) {
	u = (1 << n) - 1;
	ts[0].push_back(0);
	for(int i = 1; i <= u; i++) {
		len[i] = len[i >> 1] + (i & 1);
		ts[len[i]].push_back(i);
	}
	for(int i = 0; i <= n - m; i++) f[0][i][u] = 1;
	for(int i = n; i >= 1; i--) {
		for(int j = 0; j <= i - 1; j++) {
			for(int s : ts[i - 1]) {
				f[1][j][s] = 0;
				for(int k = 1; k <= n; k++) {
					if(s >> (k - 1) & 1) continue;
					if(a[i] == 1) {
						if(j >= c[k]) f[1][j][s] += f[0][j + 1][s | (1 << (k - 1))];
						else f[1][j][s] += f[0][j][s | (1 << (k - 1))];
					} else f[1][j][s] += f[0][j + 1][s | (1 << (k - 1))];
					f[1][j][s] %= Q;
				}
			}
		}
		std::swap(f[0], f[1]);
	}
	printf("%lld\n", f[0][0][0]);
//	} else {
//		int cnt = 0;
//		for(int i = 1; i <= n)
//	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}