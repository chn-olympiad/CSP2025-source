#include <bits/stdc++.h>
#define LL long long

using namespace std;

const int N = 2e4 + 5, M = 2e6 + 5, K = 15;

LL n, m, m1, k, fa[N], ans;
struct edge {
	LL x, y, z;
} e[M], e1[N], e2[N + N * K];
struct aa {
	LL c, a[N];
} a[K];

bool cmp (edge x, edge y) {
	return x.z < y.z;
}

int fd (int x) {
	return fa[x] ? fa[x] = fd(fa[x]) : x;
}

LL get_ans (int x) {
    fill(fa + 1, fa + n + k + 1, 0);
	int m2 = m1;
	for (int i = 1; i <= m1; i++) {
		e2[i] = e1[i];
	}
	LL ret = 0, zs = n;
	for (int i = 1; i <= k; i++) {
		if (x & (1 << i - 1)) {
			zs++;
			ret += a[i].c;
			for (int j = 1; j <= n; j++) {
				e2[++m2] = {j, i + n, a[i].a[j]};
			}
		}
	}
	sort(e2 + 1, e2 + m2 + 1, cmp);
	for (int i = 1; i <= m2; i++) {
		int xx = fd(e2[i].x), yy = fd(e2[i].y);
		if (xx == yy) continue;
		fa[xx] = yy;
		ret += e2[i].z;
		zs--;
		if (zs == 1) break;
	}
	return ret;
}

int main () {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> e[i].x >> e[i].y >> e[i].z;
	}
	for (int i = 1; i <= k; i++) {
		cin >> a[i].c;
		for (int j = 1; j <= n; j++) {
			cin >> a[i].a[j];
		}
	}
	sort(e + 1, e + m + 1, cmp);
	for (int i = 1; i <= m; i++) {
		int xx = fd(e[i].x), yy = fd(e[i].y);
		if (xx == yy) continue;
		fa[xx] = yy;
		e1[++m1] = e[i];
		ans += e[i].z;
		if (m1 >= n - 1) break;
	}
	for (int i = 1; i < (1 << k); i++) {
		ans = min(ans, get_ans(i));
	}
	cout << ans;
	return 0;
}
/*
suo yi ccf ping ce ji 1s 1e9 shi zhen de ma????? qwq
wo yao bao 0 le qwq
*/
