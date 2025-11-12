#include <bits/stdc++.h>

using namespace std;

const int maxm = 1e6 + 1;
const int maxn = 1e4 + 1;
const int maxk = 11;
int n, m, k;
int father[maxn], cnt[maxn];
void init() {
	for (int i = 1; i <= n; i++) {
		father[i] = i;
		cnt[maxn] = 0;
	}
}

int fa(int x) {
	if (x == father[x]) return x;
	return father[x] = fa(father[x]);
}
int tot;
void merge(int a, int b) {
	a = fa(a), b = fa(b);
	if (a != b) {
		father[a] = b;
		cnt[b] += cnt[a] + 1;
		tot = max(tot, cnt[b]);
	}
}
struct road {
	int u, v, w; 
	void input() {
		cin >> u >> v >> w;
	}
	bool operator < (const road & o) {
		return w < o.w;
	}
	void output() {
		cout << u << " " << v << " " << w << endl;
	}
} r[maxm];
int c[maxk][maxn];
int Kruskal() {
	int num;
	for (int i = 1; i <= m; i++) {
		if (tot + 1 < n) {
			merge(r[i].u, r[i].v);
			num += r[i].w;
		}
	}
	return num;
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	init();
	for (int i = 1; i <= m; i++) {
		r[i].input(); 
	}
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> c[i][j];
		}
	}
	sort(r + 1, r + n + 1);
	cout << Kruskal() << endl;
}
