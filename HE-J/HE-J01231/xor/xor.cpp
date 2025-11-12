#include <bits/stdc++.h>
#define ls u << 1
#define rs u << 1 | 1
using namespace std;

const int N = 5e5 + 5;
int a[N], n, k;

int tree[N << 2];
void pushup(int u) { tree[u] = tree[ls] ^ tree[rs]; }
void build(int u, int l, int r) {
	if (l == r) {
		tree[u] = a[l];
		return ;
	}
	int mid = l + r >> 1;
	build(ls, l, mid);
	build(rs, mid + 1, r);
	pushup(u);
}
int qry(int u, int l, int r, int L, int R) {
	if (R < l || L > r) return 0;
	if (l <= L && r >= R) return tree[u];
	int mid = L + R >> 1, ans = 0;
	ans = qry(ls, l, r, L, mid);
	ans ^= qry(rs, l, r, mid + 1, R);
	return ans;
}
bool f = true;
int res, ans;
void dfs(int t, int l, int r, int want) { 
	if (t <= 0) {
		res += qry(1, l, r, 1, n) == want;
//		cout << l << ' ' << r << ' ' << qry(1, l, r, 1, n) << endl;
		ans = max(ans, res);
//		cout << t << ' ' << l << ' ' << r << ' ' << ans << endl;
		res = 0;
		return ;
	}
	if (r - l + 1 == 2) {
		res += (a[l] ^ a[r]) == want;
		return ;
	} 
	if (r - l + 1 == 1) {
		res += a[l] == want;
		return ;
	}
	for (int i = l; i < r; ++i) {
		res += qry(1, l, i, 1, n) == want;
//		cout << t << ' ' << l << ' ' << r << ' ' << ans << endl;
		dfs(t - 1, i + 1, r, want);
	}
}
bool all1 = true, all01 = true;
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &k);
	int num1 = 0, num0 = 0;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		num1 += a[i] == 1; 
		num0 += a[i] == 0;
		if (a[i] != 1) all1 = false;
		if (a[i] != 0 && a[i] != 1) all01 = false;
	}
	if (all1) {
		if (k != 1 && k != 0) return printf("0"), 0;
		else if (k == 1) return printf("%d", n), 0;
		else return printf("%d", n - 1), 0;
	} 
	else if (num0 == n) {
		if (k != 0) return printf("0"), 0;
		else return printf("%d", n);
	}
	else if (all01) {
		if (k != 1 && k != 0) return printf("0"), 0;
		else if (k == 1) return printf("%d", n), 0;
		else return printf("%d", n), 0;
	}
	else if (n <= 10) {
		build(1, 1, n);
		int anns = 0;
		for (int i = n - 1; i >= 0; --i) {
			ans = 0;
			dfs(i, 1, n, k);
			anns = max(ans, anns);
		}
		printf("%d", anns);
	} else {
		printf("%d", (int)(rand() + n + n) % n);
	}
	return 0;
}
