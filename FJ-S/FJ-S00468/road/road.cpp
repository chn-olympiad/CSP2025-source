#include <bits/stdc++.h>
using namespace std;

inline long long read(void) {
	long long x = 0, f = 1; char c = getchar();
	while (c > '9' || c < '0') {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') x = (x << 1) + (x << 3) + c - 48, c = getchar();
	return x * f;
}

struct node {
	long long x, y, w;
	friend bool operator< (node x, node y) {
		return x. w > y. w;
	}
} qwq[1000005];

long long n, m, k, f[10050], c[20], t[20], ans, cnt;
vector<node> e[11];
priority_queue<node> Es;

bool cmp (node x, node y) {
	return y < x;
}

long long find (long long x) {
	if (f[x] != x) f[x] = find(f[x]);
	return f[x];
}

long long calc (long long x) {
	long long rtn = 0;
	cnt = n;
	while (!Es. empty()) Es. pop();
	for (int i = 1; i <= n + k; i++) f[i] = i;
	for (int i = 0; i < k; i++) {
		if (x >> i & 1)
			t[i] = 0, rtn += c[i], cnt++, Es. push(e[i][0]);
	}
	t[k] = 0;
	Es. push(e[k][0]);
	while (cnt > 1) {
		auto tp = Es. top();
		Es. pop();
		long long id = tp. y <= n ? k : tp. y - n - 1;
		t[id]++;
		if (t[id] < e[id]. size()) Es. push(e[id][t[id]]);
		if (find(tp. x) == find(tp. y)) continue;
		rtn += tp. w, cnt--;
		f[find(tp. x)] = find(tp. y);
	}
	return rtn;
}

int main(void) {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cnt = n = read(), m = read(), k = read();
	for (int i = 1; i <= n; i++) f[i] = i;
	for (int i = 1; i <= m; i++) qwq[i]. x = read(), qwq[i]. y = read(), qwq[i]. w = read();
	sort(qwq + 1, qwq + 1 + m, cmp);
	for (int i = 1; i <= m; i++) {
		if (find(qwq[i]. x) == find(qwq[i]. y)) continue;
		cnt--, ans += qwq[i]. w;
		f[find(qwq[i]. x)] = find(qwq[i]. y);
		e[k]. push_back(qwq[i]);
		if (cnt == 1) break;
	}
	for (int i = 0; i < k; i++) {
		c[i] = read();
		for (int j = 1; j <= n; j++) e[i]. push_back({j, n + 1 + i, read()});
		sort(e[i]. begin(), e[i]. end(), cmp);
	}
	for (int i = 1; i < 1 << k; i++) ans = min(ans, calc(i));
	printf("%lld", ans);
	return 0;
}
