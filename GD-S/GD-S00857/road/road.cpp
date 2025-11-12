#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5, M = 2e6 + 5;
typedef pair<int,int> PII;
int n, m, kk, c[15], a[15][10005], idx;

struct EEde {
	int u, v, c;
}e[M], ee[M], eee[M], eeee[M];

bool cmp(EEde x, EEde y) {
	return x.c < y.c;
}

int f[10005];

int find(int x) {
	return x == f[x] ? x : f[x] = find(f[x]);
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &kk);
	for (int i = 1; i <= m; i++) {
		int u, v, c;
		scanf("%d%d%d", &u, &v, &c);
		e[i] = {u, v, c};
	}
	for (int i = 1; i <= n; i++) {
		f[i] = i;
	}
	for (int i = 1; i <= kk; i++) {
		scanf("%d", &c[i]);
		for (int j = 1; j <= n; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	sort(e + 1, e + m + 1, cmp);
	int cnt = 1;
	long long ans = 0;
	for (int i = 1; i <= m; i++) {
		int u = e[i].u, v = e[i].v, w = e[i].c;
		int fu = find(u), fv = find(v);
		if (fu == fv) continue;
		ee[++idx] = {u, v, w};
		ans += w;
		f[fu] = fv;
		cnt++;
		if (cnt == n) break;
	}
	if (kk == 0) {
		cout << ans << endl;
		return 0;
	}
	long long nans = 0;
	for (int i = 1; i <= kk; i++) {
		nans = c[i];
		for (int j = 1; j <= idx; j++) {
			eee[j] = ee[j];
		}
		int iix = idx, idd = 0;
		for (int j = 1; j <= n; j++) {
			for (int k = j + 1; k <= n; k++) {
				eee[++iix] = {j, k, a[i][j] + a[i][k]};
			}
			f[j] = j;
		}
		cnt = 1;
		sort(eee + 1, eee + iix + 1, cmp);
		for (int j = 1; j <= iix; j++) {
			int u = eee[j].u, v = eee[j].v, w = eee[j].c;
			int fu = find(u), fv = find(v);
			if (fu == fv) continue;
			eeee[++idd] = {u, v, w};
			nans += w;
			f[fu] = fv;
			cnt++;
			if (cnt == n) break;
		}
		if (nans < ans) {
			ans = nans;
			for (int j = 1; j <= idx; j++) {
				ee[j] = eeee[j];
			}
		}
	}
	cout << ans << endl;
	return 0;
} 
