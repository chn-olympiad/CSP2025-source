#include <bits/stdc++.h> 
#define LL long long

using namespace std;

struct node {
	int v;
	int cnt1, cnt2, cnt3;
};

struct node2 {
	int a, b, c;
};

bool cmp(node2 x, node2 y) {
	return x.a + x.b + x.c > y.a + y.b + y.c;
}

const int N = 1e5 + 100;
const int M = 5;

int t, n;
node2 a[N];
node dp[N][M];
int cnt1, cnt2, cnt3;
int cnt;

int main () {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		scanf("%d", &n);
		memset(dp, 0, sizeof(dp));
		for (int j = 1; j <= n; j++) 
			scanf("%d%d%d", &a[j].a, &a[j].b, &a[j].c);
		sort (a + 1, a + n + 1, cmp);
		for (int j = 1; j <= n; j++) {
			if (dp[j - 1][1].cnt1 <= n / 2 - 1) {
				if (dp[j - 1][1].v + a[j].a >= dp[j][1].v) {
					dp[j][1].v = dp[j - 1][1].v + a[j].a;
					dp[j][1].cnt1 = dp[j - 1][1].cnt1 + 1;
					dp[j][1].cnt2 = dp[j - 1][1].cnt2;
					dp[j][1].cnt3 = dp[j - 1][1].cnt3;
				}
			}
			if (dp[j - 1][2].cnt1 <= n / 2 - 1) {
				if (dp[j - 1][2].v + a[j].a >= dp[j][1].v) {
					dp[j][1].v = dp[j - 1][2].v + a[j].a;
					dp[j][1].cnt1 = dp[j - 1][2].cnt1 + 1;
					dp[j][1].cnt2 = dp[j - 1][2].cnt2;
					dp[j][1].cnt3 = dp[j - 1][2].cnt3;
				}
			}
			if (dp[j - 1][3].cnt1 <= n / 2 - 1) {
				if (dp[j - 1][3].v + a[j].a >= dp[j][1].v) {
					dp[j][1].v = dp[j - 1][3].v + a[j].a;
					dp[j][1].cnt1 = dp[j - 1][3].cnt1 + 1;
					dp[j][1].cnt2 = dp[j - 1][3].cnt2;
					dp[j][1].cnt3 = dp[j - 1][3].cnt3;
				}
			}
			
			if (dp[j - 1][1].cnt2 <= n / 2 - 1) {
				if (dp[j - 1][1].v + a[j].b >= dp[j][2].v) {
					dp[j][2].v = dp[j - 1][1].v + a[j].b;
					dp[j][2].cnt1 = dp[j - 1][1].cnt1;
					dp[j][2].cnt2 = dp[j - 1][1].cnt2 + 1;
					dp[j][2].cnt3 = dp[j - 1][1].cnt3;
				}
			}
			if (dp[j - 1][2].cnt2 <= n / 2 - 1) {
				if (dp[j - 1][2].v + a[j].b >= dp[j][2].v) {
					dp[j][2].v = dp[j - 1][2].v + a[j].b;
					dp[j][2].cnt1 = dp[j - 1][2].cnt1;
					dp[j][2].cnt2 = dp[j - 1][2].cnt2 + 1;
					dp[j][2].cnt3 = dp[j - 1][2].cnt3;
				}
			}
			if (dp[j - 1][3].cnt2 <= n / 2 - 1) {
				if (dp[j - 1][3].v + a[j].b >= dp[j][2].v) {
					dp[j][2].v = dp[j - 1][3].v + a[j].b;
					dp[j][2].cnt1 = dp[j - 1][3].cnt1;
					dp[j][2].cnt2 = dp[j - 1][3].cnt2 + 1;
					dp[j][2].cnt3 = dp[j - 1][3].cnt3;
				}
			}
			
			if (dp[j - 1][1].cnt3 <= n / 2 - 1) {
				if (dp[j - 1][1].v + a[j].c >= dp[j][3].v) {
					dp[j][3].v = dp[j - 1][1].v + a[j].c;
					dp[j][3].cnt1 = dp[j - 1][1].cnt1;
					dp[j][3].cnt2 = dp[j - 1][1].cnt2;
					dp[j][3].cnt3 = dp[j - 1][1].cnt3 + 1;
				}
			}
			if (dp[j - 1][2].cnt3 <= n / 2 - 1) {
				if (dp[j - 1][2].v + a[j].c >= dp[j][3].v) {
					dp[j][3].v = dp[j - 1][2].v + a[j].c;
					dp[j][3].cnt1 = dp[j - 1][2].cnt1;
					dp[j][3].cnt2 = dp[j - 1][1].cnt2;
					dp[j][3].cnt3 = dp[j - 1][2].cnt3 + 1;
				}
			}
			if (dp[j - 1][3].cnt3 <= n / 2 - 1) {
				if (dp[j - 1][3].v + a[j].c >= dp[j][3].v) {
					dp[j][3].v = dp[j - 1][3].v + a[j].c;
					dp[j][3].cnt1 = dp[j - 1][3].cnt1;
					dp[j][3].cnt2 = dp[j - 1][3].cnt2;
					dp[j][3].cnt3 = dp[j - 1][3].cnt3 + 1;
				}
			}
		}
		printf("%d\n",max(dp[n][1].v, max(dp[n][2].v, dp[n][3].v)));
	}
	return 0;
}
/*

1
6
0 0 1
0 0 2
0 0 3
0 0 4
0 0 19
0 100 0

*/
