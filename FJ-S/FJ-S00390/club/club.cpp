#include <bits/stdc++.h>
using namespace std;

inline int read() {
	int x = 0; char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	x = ch ^ 48, ch = getchar();
	while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
	return x;
}

const int N = 1e5 + 5;
int T, n, a[N][3], Max[N], id[N];
int cnt[3], x[N], y[N];
long long ans, sum;

inline void get(int t) {	// 强制 t 选 n/2 个 
	for (int i = 1; i <= n; i++) {
		x[i] = a[i][t], y[i] = 0;
		for (int j = 0; j <= 2; j++) if (j ^ t) y[i] = max(y[i], a[i][j]);
	}
	// x 要选 n/2 个并最大化 
	sum = 0; for (int i = 1; i <= n; i++) sum += x[i], y[i] -= x[i];
	sort(y + 1, y + 1 + n);
	for (int i = n / 2 + 1; i <= n; i++) sum += y[i];
	ans = max(ans, sum);
}

void solve() {
	n = read();
	cnt[0] = cnt[1] = cnt[2] = 0;
	for (int i = 1; i <= n; i++) Max[i] = 0;
	for (int i = 1; i <= n; i++) {
		a[i][0] = read(), a[i][1] = read(), a[i][2] = read();
		Max[i] = max(a[i][0], max(a[i][1], a[i][2]));
		if (Max[i] == a[i][0]) id[i] = 0;
		else if (Max[i] == a[i][1]) id[i] = 1;
		else id[i] = 2;
	}
	ans = 0, sum = 0;
	for (int i = 1; i <= n; i++) sum += Max[i], cnt[id[i]]++;
	if (cnt[0] <= n / 2 && cnt[1] <= n / 2 && cnt[2] <= n / 2) ans = sum;	// 都取最大值合法 
	get(0), get(1), get(2);
	printf("%lld\n", ans);
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &T);
	while (T--) solve();
	return 0;
}
