#include <bits/stdc++.h>

using namespace std;

const long long N = 2e6 + 5, mod = 998244353, inf = 4e18;

inline long long read() {
	long long x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-') {
			f = -1;
		}
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		x = (x << 3) + (x << 1) + (ch - '0');
		ch = getchar();
	}
	return x * f;
}

struct path {
	long long u, v, w;
};

long long n, m, k, cnt, pre[N], ans;

vector<path> e;

long long find(long long x) {
	if (x == pre[x]) {
		return x;
	}
	return pre[x] = find(pre[x]);
}

bool cmp(path a, path b) {
	return a.w < b.w;
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = read();
	m = read();
	k = read();
	for (long long i = 1; i <= n; ++i) {
		pre[i] = i;
	}
	for (long long i = 1, u, v, w; i <= m; ++i) {
		u = read(), v = read(), w = read();
		e.push_back(path{u, v, w});
	}
	sort(e.begin(), e.end(), cmp);
	for (auto x : e) {
		long long uu = find(x.u), vv = find(x.v);
		if (uu != vv) {
			pre[uu] = vv;
			ans += x.w;
		}
	}
	printf("%lld\n", ans);
	return 0;
}

// CSP-S2025 rp++!!!
