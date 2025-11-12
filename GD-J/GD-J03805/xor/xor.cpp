#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
const int V = (1 << 21);
int n, k, a[N], s[N], f[N];
struct Segment {
	int tr[V << 2];
	void insert(int k, int l, int r, int p, int v) {
		if (l == r) return tr[k] = max(tr[k], v), void();
		int mid = (l + r) >> 1;
		if (mid >= p) insert(k << 1, l, mid, p, v);
		else insert(k << 1 | 1, mid + 1, r, p, v);
	}
	inline int ask(int k, int l, int r, int p){
		if (l == r) return tr[k];
		int mid = (l + r) >> 1;
		if (mid >= p) return ask(k << 1, l, mid, p);
		else return ask(k << 1 | 1, mid + 1, r, p);
	}
} T;
signed main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i], s[i] = s[i - 1] ^ a[i];
	for (int i = 1; i <= n; i++) {
		f[i] = f[i - 1];
		int v = (s[i] ^ k), las = T.ask(1, 0, V, v);
		if (!las && s[i] == k) f[i] = max(f[i], f[las] + 1); 
		else if (las) f[i] = max(f[i], f[las] + 1); 
		T.insert(1, 0, V, s[i], i);
	}
	cout << f[n];
	return 0;
}
/*
4 0
2 1 0 3
*/
