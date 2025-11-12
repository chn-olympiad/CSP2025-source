#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5, V = (1 << 20) + 5;
struct Tree {
	int l, r;
	long long maxn;
} tree[N << 2];
long long a[N], s[N], dp[N], pre[V], b[N];

void build(int p, int l, int r) {
	tree[p].l = l;
	tree[p].r = r;
	if (l == r)
		return;
	int mid = l + r >> 1;
	build(p << 1, l, mid);
	build(p << 1 | 1, mid + 1, r);
}

void modify(int p, int k, long long x) {
	if (tree[p].r < k || tree[p].l > k)
		return;
	if (tree[p].l == tree[p].r && tree[p].r == k) {
		tree[p].maxn = x;
		return;
	}
	modify(p << 1, k, x);
	modify(p << 1 | 1, k, x);
	tree[p].maxn = max(tree[p << 1].maxn, tree[p << 1 | 1].maxn);
}

long long query(int p, int l, int r) {
	if (l > r)
		return 0;
	if (tree[p].r < l || tree[p].l > r)
		return 0;
	if (l <= tree[p].l && tree[p].r <= r)
		return tree[p].maxn;
	return max(query(p << 1, l, r), query(p << 1 | 1, l, r));
}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	build(1, 1, n);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s[i] = s[i - 1] ^ a[i];
	}
	for (int i = 1; i <= n; i++) {
		b[i] = (pre[s[i] ^ k] == 0 ? -1 : pre[s[i] ^ k]);
		if (b[i] == -1 && s[i] == k)
			b[i] = 0;
		pre[s[i]] = i;
	}
	dp[1] = (a[1] == k);
	modify(1, 1, dp[1]);
	for (int i = 2; i <= n; i++) {
		if (b[i] == -1) {
			dp[i] = query(1, 1, i - 1);
			modify(1, i, dp[i]);
			continue;
		}
		dp[i] = max(query(1, 1, b[i]) + 1, query(1, b[i] + 1, i - 1));
		modify(1, i, dp[i]);
	}
	cout << query(1, 1, n) << '\n';
	return 0;
}
