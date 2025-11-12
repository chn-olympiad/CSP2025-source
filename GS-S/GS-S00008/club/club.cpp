#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10, maxm = 1e2 + 10;
int e[maxn][4], dp[maxm << 1][maxm][maxm][maxm];
int T, n, ans, flag1;
struct Node {
	int a, b, c;
} E[maxn];
bool cmp(Node&A, Node& B) {
	return A.a > B.a;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d", &T);
	while(T--) {
		flag1 = 0;
		memset(dp, -0x3f3f3f3f, sizeof dp);
		ans = -0x3f3f3f3f;
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%d%d%d", &e[i][1], &e[i][2], &e[i][3]);
			if(e[i][2] !=0 || e[i][3] != 0) {
				flag1 = 1;
			}
		}
		if(n == 2) {
			for (int i = 1; i <= 3; ++i) {
				for (int j = 1; j <= 3; ++j) {
					if (i == j) {
						continue;
					}
					ans = max(ans, e[1][i]+e[2][j]);
				}
			}
		} else if(n <= 200) {
			dp[1][1][0][0] = e[1][1];
			dp[1][0][1][0] = e[1][2];
			dp[1][0][0][1] = e[1][3];
			for (int i = 2; i <= n; ++i) {
				for (int A = 0; A <= i; ++A) {
					for (int B = 0; B <= i - A; ++B) {
						int C = i - A - B;
						if(A <= n / 2 && B <= n / 2 && C <= n / 2) {
							dp[i][A][B][C] = max(dp[i - 1][A - 1][B][C] + e[i][1], max(dp[i - 1][A][B - 1][C] + e[i][2], dp[i - 1][A][B][C - 1] + e[i][3]));
							if(i == n) {
								ans = max(ans, dp[n][A][B][C]);
							}
						}
					}
				}
			}
		} else if(flag1 == 0) {
			ans = 0;
			for(int i = 1; i <= n; ++i) {
				E[i].a = e[i][1];
				E[i].b = e[i][2];
				E[i].c = e[i][3];
			}
			sort(E + 1, E + n + 1, cmp);
			for(int i = 1; i <= n / 2; ++i) {
				ans += E[i].a;
			}
		}
		printf("%d\n", max(ans, 0));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
