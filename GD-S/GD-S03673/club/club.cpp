#include <cstdio>
#include <algorithm>
#include <vector>

using std::vector;
using std::sort;
using std::max;

const int MAXN = 100001;

int n, t, limit, ans, count;

int a[MAXN];
int b[MAXN];
int c[MAXN];
int aidx[MAXN];
int bidx[MAXN];
int cidx[MAXN];
int res[4];

bool cmp(const int &a, const int &b) {
	return a > b;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		scanf("%d", &n);
		limit = n >> 1;
		
		for (int j = 1; j <= n; j++) {
			scanf("%d %d %d", &a[j], &b[j], &c[j]);
			aidx[a[j]] = j;
			bidx[b[j]] = j;
			cidx[c[j]] = j;
		}

		sort(a + 1, a + 1 + n, cmp);
		sort(b + 1, b + 1 + n, cmp);
		sort(c + 1, c + 1 + n, cmp);

		vector<bool> vis(n + 1, false);
		
		// a + b
		for (int j = 1; j <= limit; j++) {
			vis[aidx[j]] = true;
			ans += a[j];
		}
		for (int j = 1; j <= n; j++) {
			if (vis[aidx[j]]) {
				continue;
			}
			if (count >= limit) {
				break;
			}
			ans += b[j];
			count++;
		}
		
		res[1] = ans;
		vis.resize(n + 1, false);
		ans = 0;
		count = 0;
		// b + c
		for (int j = 1; j <= limit; j++) {
			vis[bidx[j]] = true;
			ans += b[j];
		}
		for (int j = 1; j <= n; j++) {
			if (vis[bidx[j]]) {
				continue;
			}
			if (count >= limit) {
				break;
			}
			ans += c[j];
			count++;
		}
		
		res[2] = ans;
		vis.resize(n + 1, false);		
		ans = 0;
		count = 0;
		// a + c
		for (int j = 1; j <= limit; j++) {
			vis[aidx[j]] = true;
			ans += a[j];
		}
		for (int j = 1; j <= n; j++) {
			if (vis[aidx[j]]) {
				continue;
			}
			if (count >= limit) {
				break;
			}
			ans += c[j];
			count++;
		}
		
		res[3] = ans;
		
		ans = max(ans, res[2]);
		ans = max(ans, res[1]);
		
		printf("%d\n", ans);
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
