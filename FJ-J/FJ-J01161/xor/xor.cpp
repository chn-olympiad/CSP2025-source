#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5, M = 1e3 + 5; 
int n, k, a[N], sum[M][M], dp[M][M], top, mx;
struct tmp {
	int l, r;
} s[M * M];
bool cmp(tmp o, tmp u) {
	if (o.l != u.l) {
		return o.l < u.l;
	}
	return o.r < u.r;
}
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		mx = max(mx, a[i]);
	}
	if (k > mx) {
		printf("0");
		return 0;
	}
	int scoreA = 1;
	for (int i = 1; i <= n; i++) {
		if (a[i] != 1) {
			scoreA = 0;
			break;
		}
	}
	if (scoreA) {
		if (k == 0) {
			printf("%d", n / 2);
		} else if (k == 1) {
			printf("%d", n);
		} else {
			printf("0");
		}
		return 0;
	}
	int scoreB = 1;
	for (int i = 1; i <= n; i++) {
		if (a[i] > 1) {
			scoreB = 0;
			break; 
		}
	}
	if (scoreB) {
		int cnta = 0, cntb = 0;
		for (int i = 1; i <= n; i++) {
			if (a[i] == 0) {
				cnta++;
			} else {
				cntb++;
			}
		}
		if (k == 0) {
			printf("%d", cnta);
		} else if (k == 1) {
			printf("%d", cntb);
		} else {
			printf("0");
		}
		return 0;
	}
	if (n <= 400) {
		for (int i = 1; i <= n; i++) {
			int xorsum = 0;
			for (int j = i; j <= n; j++) {
				xorsum ^= a[j];
				sum[i][j] = xorsum;
				if (sum[i][j] == k) {
					dp[i][j] = 1;
				}
			}
		}	
		for (int len = 2; len <= n; len++) {
			for (int l = 1; l + len - 1 <= n; l++) {
				int r = l + len - 1;
				for (int ko = l; ko < r; ko++) {
					dp[l][r] = max(dp[l][r], dp[l][ko] + dp[ko + 1][r]);
				}
			}
		}
		printf("%d", dp[1][n]);
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		int num = 0;
		for (int j = i; j <= n; j++) {
			num ^= a[j];
			sum[i][j] = num;
			if (num == k) {
				s[++top].l = i, s[top].r = j;
			}
		}
	}
	sort(s + 1, s + top + 1, cmp);
	int ans = 0, now = 0;
	for (int i = 1; i <= top; i++) {
		if (s[i].l > now) {
			now = s[i].r;
			ans++;
		}
	}
	printf("%d", ans);
	return 0;
}
