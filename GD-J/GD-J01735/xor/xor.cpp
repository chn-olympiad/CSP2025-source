#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 10;

int a[N], n, k;
int s[N];
int c[N];
int vis[N]; 

inline int lowbit (int x) {
	return x & -x; 
}

inline void add (int x) {
	for (; x <= n; x += lowbit (x)) c[x] ++;
}

inline int ask (int x) {
	int res = 0;
	for (; x; x -= lowbit (x)) res += c[x];
	return res;
}

inline int query (int l, int r) {
	return ask (r) - ask (l - 1);
}

int res = 0;

inline void dfs (int id, int sm) {
	res = max (res, sm);
	if (id == n + 1) return ;
	for (int r = id; r <= n; r ++) {
		if ((s[r] ^ s[id - 1]) == k) {
			dfs (r + 1, sm + 1);
		}
	}
	dfs (id + 1, sm);
}

signed main () {
	freopen ("xor.in", "r", stdin);
	freopen ("xor.out", "w", stdout);
	scanf ("%d%d", &n, &k);
	for (int i = 1; i <= n; i ++) scanf ("%d", &a[i]);
	for (int i = 1; i <= n; i ++) s[i] = s[i - 1] ^ a[i];
	if (n <= 20) {
		dfs (1, 0);
		cout << res << '\n';
		return 0;
	}
	int ans = 0;
	for (int len = 0; len <= n; len ++) {
		for (int i = 1; i + len <= n; i ++) {
			if (query (i, i + len)) continue;
			int t = s[i + len] ^ s[i - 1];
			if (t == k) {
				ans ++;
				for (int j = i; j <= i + len; j ++) {
					add (j);
				}
			}
		}
	}
	cout << ans << '\n';
	return 0;
}
