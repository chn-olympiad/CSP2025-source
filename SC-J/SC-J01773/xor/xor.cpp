#include"bits/stdc++.h"
#define M ((L+R)>>1)
#define ls u<<1
#define rs u<<1|1
using namespace std;
const int N = 5e5+5, va = 1;
int n, k;
int a[N], s[N];
int ans;
struct qj {
	int l, r;
	bool operator<(const qj &x)const {
		if (l == x.l)
			return r < x.r;
		return l > x.l;
	}
};
struct node {
	int w, lzy;
} tree[N << 2];
void pushup(int u) {
	tree[u].w = tree[ls].w + tree[rs].w;
}
void maketag(int u, int len, int x) {
	tree[u].lzy += x;
	tree[u].w += x*len;
}
void pushdown(int u, int L, int R) {
	maketag(ls, M - L + 1, tree[u].lzy);
	maketag(rs, R - M, tree[u].lzy);
	tree[u].lzy = 0;
}
bool inrange(int L, int R, int l, int r) {
	return (L >= l) && (R <= r);
}
bool outrange(int L, int R, int l, int r) {
	return (L > r) || (R < l);
}
int caory(int u, int L, int R, int l, int r) {
	if (inrange(L, R, l, r))
		return tree[u].w;
	else if (!outrange(L, R, l, r)) {
		pushdown(u, L, R);
		return caory(ls, L, M, l, r) + caory(rs, M + 1, R, l, r);
	} else
		return 0;
}
void update(int u, int L, int R, int l, int r) {
	if (inrange(L, R, l, r))
		maketag(u, R - L + 1, va);
	else if (!outrange(L, R, l, r)) {
		pushdown(u, L, R);
		update(ls, L, M, l, r);
		update(rs, M + 1, R, l, r);
		pushup(u);
	}
}
signed main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i], s[i] = (s[i - 1] xor a[i]);
	bool xz_a = 1, xz_b = 1;
	for (int i = 1; i <= n; i++)
		xz_a &= (a[i] == 1);
	for (int i = 1; i <= n; i++)
		xz_b &= (a[i] <= 1);
	if (xz_a) {
		cout << n / 2;
		return 0;
	}
	if (xz_b) {
		int cnt1 = 0;
		for (int i = 1; i <= n; i++)
			cnt1 += (a[i] == 1);
		cout << (k ? cnt1 : cnt1 / 2);
		return 0;
	}
	vector<qj>a;
	for (int l = 1; l <= n; l++)
		for (int r = l; r <= n; r++)
			if ((s[r] xor s[l - 1]) == k)
				a.push_back({l, r});
	sort(a.begin(), a.end());
	for (auto t : a) {
		if (!caory(1, 1, n, t.l, t.r)) {
			ans++;
			update(1, 1, n, t.l, t.r);
		}
	}
	cout << ans;
	return 0;
}