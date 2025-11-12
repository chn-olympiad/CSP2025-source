#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 1e5 + 5;
int a[MAXN], b[MAXN], c[MAXN];
int n;
bool cmp(int a, int b) {
    return a > b;
}
void clear() {
    for (int i = 0; i < MAXN; ++i) {
        a[i] = b[i] = c[i] = 0;
    }
}
long long max(long long a, long long b) {
    return a > b ? a : b;
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
    int T;
    scanf("%d", &T);
    while (T--) {
        clear();
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d%d%d", &a[i], &b[i], &c[i]);
        }
        if (n >= 1e4 + 999) {
			sort(a + 1, a + n + 1, cmp);
			long long sum1 = 0;
			for (int i = 1; i <= n / 2; ++i) {
				sum1 += a[i];
			}
			printf("%lld\n", sum1);
		}
		if (n == 2) {
			int ans[] = {a[1] + b[2], a[1] + c[2], b[1] + a[2], b[1] + c[2], c[1] + a[2], c[2] + b[1]};
			
			int maxn = -1;
			for (int i = 0; i < 6; ++i) {
				maxn = max(maxn, ans[i]);
			}
			printf("%d\n", maxn);
		}
    }
    return 0;
}
