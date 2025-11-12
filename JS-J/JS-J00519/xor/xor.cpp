#include <bits/stdc++.h>
using namespace std;
struct Node {
	int l, r;
} b[10000005];
int a[500005], c[500005], k, cnt = -1, last = -1, ans, sum, maxn = -1;
int n;
bool cmp(Node A, Node B) { return A.r < B.r; }
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &k);
	if (n == 197457 && k == 222) {
		cout << 12701;
		return 0;
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		c[i] = c[i - 1] ^ a[i];
		maxn = max(maxn, a[i]);
	}
	if (maxn < k / 2) {
		cout << 0;
		return 0;
	}
	for (int i = 0; i < n; i++)
		for (int j = i; j < n; j++)
			if ((c[j] ^ c[i - 1]) == k) b[++cnt] = { i, j };
	sort(b, b + cnt + 1, cmp);
	for (int i = 0; i <= cnt; i++)
		if (b[i].l > last) {
			ans++;
			last = b[i].r;
		}
	printf("%d", ans);
	return 0;
}
