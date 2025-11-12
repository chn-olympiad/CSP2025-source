#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 101000;

int t, n, b[4];
struct Node {
	int x, y, z;
} a[N];

bool flag[N];

bool cmp(Node u, Node v) {
	return u.x > v.x;
}

void solve() {
	scanf("%d", &n);
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 3; j++) {
			scanf("%d", &a[(i - 1) * 3 + j].x);
			a[(i - 1) * 3 + j].y = j;
			a[(i - 1) * 3 + j].z = i;
		}
	}
	sort(a + 1, a + 3 * n + 1, cmp);
	for (int i = 1; i <= 3 * n; i++) {
		if (flag[a[i].z]) continue;
		if (b[a[i].y] + 1 <= n / 2) {
			b[a[i].y]++;
			flag[a[i].z] = true;
			ans += a[i].x;
		}
	}
	printf("%d\n", ans);
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &t);
	while (t--) {
		solve();
		for (int i = 1; i <= 3; i++) b[i] = 0;
		for (int i = 1; i <= n; i++) flag[i] = false;
	}
	return 0;
}
