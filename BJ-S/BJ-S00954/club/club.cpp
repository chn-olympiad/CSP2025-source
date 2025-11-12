#include<cstdio>
#include<cstring>
#include<algorithm>
const int N = 100005;
int t, n;
struct node {
	int a[3];
	int want;
	int cha;
} a[N];
int most;
bool cmp(const node &x, const node &y) {
	return x.cha > y.cha;
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		int sum[3];
		memset(sum, 0, sizeof(sum));
		for (int i = 1; i <= n; ++i) {
			scanf("%d %d %d", &a[i].a[0], &a[i].a[1], &a[i].a[2]);
			int max = std::max({a[i].a[0], a[i].a[1], a[i].a[2]});
			if (max == a[i].a[0])
				a[i].want = 0;
			else if (max == a[i].a[1])
				a[i].want = 1;
			else
				a[i].want = 2;
			sum[a[i].want]++;
		}
		int ans = 0;
		if (std::max({sum[0], sum[1], sum[2]}) <= n / 2) {
			for (int i = 1; i <= n; ++i)
				ans += a[i].a[a[i].want];
		} else {
			if (sum[0] > n / 2)	
				most = 0;
			else if (sum[1] > n / 2)
				most = 1;
			else
				most = 2;
			for (int i = 1; i <= n; ++i)
				a[i].cha = a[i].a[most] - std::max(a[i].a[(most + 1) % 3], a[i].a[(most + 2) % 3]);
			std::sort(a + 1, a + n + 1, cmp);
			for (int i = 1; i <= n / 2; ++i)
				ans += a[i].a[most];
			for (int i = n / 2 + 1; i <= n; ++i)
				ans += std::max(a[i].a[(most + 1) % 3], a[i].a[(most + 2) % 3]);
		}
		printf("%d\n", ans);
	}
	return 0;
}