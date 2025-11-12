#include <bits/stdc++.h>
using namespace std;

const int N = 500010;
long long n, k, a[N], tr[N][21], s[N], f[N], idx = 0, w[10000010];

void insert(long long x, long long id) {
	long long u = 0;
	for (int i = 20; i >= 0; i--) {
		int now = ((x >> i) & 1);
		if (!tr[u][now]) tr[u][now] = ++idx;
		u = tr[u][now];
	}
	if (f[w[u]] < f[id]) w[u] = id;
}

int query(long long x) {
	long long u = 0;
	for (int i = 20; i >= 0; i--) {
		int now = ((x >> i) & 1);
		if (!tr[u][now]) return -1;
		u = tr[u][now];
	}
	return w[u];
}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%lld%lld", &n, &k);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &a[i]), s[i] = s[i-1] ^ a[i];
	insert(0, 0);
	for (int i = 1; i <= n; i++) {
		f[i] = f[i-1];
		long long x = (s[i] ^ k);
		int id = query(x);
		if (id != -1) f[i] = max(f[i], f[id] + 1);
		insert(s[i], i);
	}
	printf("%lld", f[n]);
	return 0;
}
