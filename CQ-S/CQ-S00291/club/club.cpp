#include <cstdio>
#include <algorithm>

using std::max; using std::min;
int a[100005][3], b[100005], cnt[3], op[100005], n, mn;
void Main() {
	scanf("%d", &n), cnt[0] = cnt[1] = cnt[2] = 0;
	long long ans = 0;
	for (int i = 1; i <= n; ++ i) {
		scanf("%d%d%d", a[i], a[i] + 1, a[i] + 2);
		int mx = max(max(a[i][0], a[i][1]), a[i][2]); ans += mx;
		if (mx == a[i][0]) ++ cnt[op[i] = 0];
		else if (mx == a[i][1]) ++ cnt[op[i] = 1];
		else ++ cnt[op[i] = 2];
	}
	for (int j = 0; j <= 2; ++ j) if (cnt[j] > n / 2) {
		int need = cnt[j] - n / 2, len = 0;
		for (int i = 1; i <= n; ++ i) if (op[i] == j) {
			int cost = 1e9;
			for (int k = 0; k <= 2; ++ k) if (j != k) cost = min(cost, a[i][j] - a[i][k]);
			b[++ len] = cost;
		}
		std::sort(b + 1, b + len + 1);
		for (int i = 1; i <= need; ++ i) ans -= b[i];
		break;
	}
	printf("%lld\n", ans);
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int _; scanf("%d", &_);
	while (_ --) Main();
	return 0;
}
