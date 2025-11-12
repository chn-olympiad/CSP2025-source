#include <cstdio>
#include <algorithm>
typedef long long ll;
const int N = 500005, logW = 22;
int n, k, a[N];
int ch[N * logW][2];
int id[N * logW];
int root, pcnt = 0;
int stk[logW], top;
void to_bin(int val) {
	for (top = 0; val; val >>= 1)
		stk[++top] = val & 1;
	while (top < 20) stk[++top] = 0;
}
void insert(int val, int _id) {
	int u = root;
	to_bin(val);
	for (int i = 20; i >= 1; i--) {
		int& nxt = ch[u][stk[i]];
		if (!nxt) nxt = ++pcnt;
		u = nxt;
	}
	id[u] = _id;
}
int query(int val) {
	int u = root;
	to_bin(val);
	for (int i = 20; i >= 1; i--) {
		int nxt = ch[u][stk[i]];
		if (!nxt) return -1;
		u = nxt;
	}
	return id[u];
}
int pre[N], f[N];
int main() {
	//qwq rp++!
	//Ya int_4096 desu.
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	root = ++pcnt;
	scanf("%d%d", &n, &k);
	insert(0, 0);
	f[0] = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		a[i] ^= a[i - 1]; // sum[i]
		pre[i] = query(a[i] ^ k);
		insert(a[i], i);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		f[i] = f[i - 1];
		if (pre[i] != -1)
			f[i] = std::max(f[i], f[pre[i]] + 1);
		ans = std::max(ans, f[i]);
	}
	printf("%d\n", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
CSP-J 2025
KaoShengMiHuoXingWeiDaShang:
8:38
Open T3.
Oh, no, J is difficult, I can't solve this fast.
8:45
Rethink about this, but it's still hard to solve.
Maybe leave it to the last.
9:04
Now I go back.
This is hard to solve..
n = 500000, it's so big.
9:06
We might try to dp.
f(i) = max f(j) + w(j + 1, i)
and one thing is that you won't go any longer than a seq that
got the value of k.
so the dp might looks like
f(i) = max{f(i - 1), f(pre_i) + 1}
and now the problem is just how to calc pre_i.
using a trie?
I think it is, let's try to code then.
9:26
Wa on sample 3.
We have enough time to debug.
9:31
Ah, I forgot to sum.
Now passed the samples.

*/