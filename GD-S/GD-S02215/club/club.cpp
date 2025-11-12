#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
struct node {
	int val, id;
};
struct Edge {
	int a, b;
	int x, y;
};
node a[N][3];
Edge b[N];
int cnt[4];

bool cmp1(node x, node y) {
	return x.val > y.val;
}

bool cmp2(Edge x, Edge y) {
	return x.a - x.b > y.a - y.b;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while (T--) {
		memset(cnt, 0, sizeof(cnt));
		memset(a, 0, sizeof(a));
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d%d%d", &a[i][1].val, &a[i][2].val, &a[i][3].val);
			a[i][1].id = 1; a[i][2].id = 2; a[i][3].id = 3;
			sort(a[i] + 1, a[i] + 4, cmp1);
			b[i].a = a[i][1].val; b[i].x = a[i][1].id;
			b[i].b = a[i][2].val; b[i].y = a[i][2].id;
		}
		sort(b + 1, b + n + 1, cmp2);
		int maxn = n / 2;
		long long tot = 0;
		for (int i = 1; i <= n; i++) {
			if (cnt[b[i].x] < maxn) {
				cnt[b[i].x]++;
				tot += b[i].a;
			}
			else {
				tot += b[i].b;
			}
		}
		printf("%lld\n", tot);
	}
	return 0;
} 
