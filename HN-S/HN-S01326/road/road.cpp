#include <bits/stdc++.h>

using namespace std;
using LL = long long;

const int kMaxN = 1e4 + 5, kMaxM = 1e6 + 5, kL = 16;

struct Edge {
	int x, y;
	LL z;
} edge[kMaxN + kMaxM], te[kMaxN + kMaxM];
int n, m, k, r[kMaxN], len, v[kMaxN], c[15][kMaxN];
LL ans, sum;
bool b[kMaxN], flag = 1;

int R(int i) { return r[i] == i ? i : r[i] = R(r[i]); }

LL K(int tar) {
	sort(edge + 1, edge + 1 + len, [&](Edge x, Edge y) {
		return x.z < y.z;
	});
	for (int i = 0; i <= n + k; i++) {
		r[i] = i;
	}
	LL c = 0;
	for (int i = 1, j = 0; i <= len && j < tar; i++) {
		int x = edge[i].x, y = edge[i].y, z = edge[i].z;
		if (R(x) != R(y)) {
			r[R(x)] = R(y), j++, c += z;
		}
	}
	return c;
}

void S(int x) {
	if (sum > ans) {
		return;
	}
	if (x > k) {
		int tlen = len, s = 0;
		for (int i = 1; i <= k; i++) {
			if (b[i]) {
				s++;
			}
		}
		for (int i = 1; i <= k; i++) {
			if (b[i]) {
				for (int j = 1; j <= n; j++) {
					edge[++len] = {i + n, j, c[i][j]};
				}
			}
		}
		if (sum > ans) {
			return;
		}
		ans = min(ans, sum + K(n - 1 + s));
		len = tlen;
		for (int i = 1; i <= len; i++) {
			edge[i] = te[i];
		}
		return;
	}
	b[x] = 1;
	sum += v[x];
	S(x + 1);
	sum -= v[x];
	b[x] = 0;
	S(x + 1);
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1, x, y, z; i <= m; i++) {
		cin >> x >> y >> z;
		edge[++len] = {x, y, z};
		te[len] = edge[len];
	}
	ans = K(n - 1);
	if (!k) {
		cout << ans;
		return 0;
	}
	for (int i = 1; i <= k; i++) {
		cin >> v[i];
		if (v[i] != 0) {
			flag = 0;
		}
		for (int j = 1; j <= n; j++) {
			cin >> c[i][j];
		}
	}
	if (flag) {
		for (int i = 1; i <= k; i++) {
			for (int j = 1; j <= n; j++) {
				edge[++len] = {i + n, j, c[i][j]};
			}
		}
		cout << K(n - 1 + k);
		return 0;
	}
	S(1);
	cout << ans;
	return 0;
}

