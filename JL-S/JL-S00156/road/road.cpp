#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e4 + 10;
const int K = 15;
const int M = 2e6 + 10;

int n, m, k, cnt, ans, nowk;
int c[K], p[K], a[K][N];

struct stu {
	int u, v, w;
} e[M], ee[M];

int f[N];

int Find(int x) {return f[x] == x ? x : f[x] = Find(f[x]);}

bool cmp(stu a1, stu a2) {return a1.w < a2.w;}

int Kruscal() {
	for (int i = 1; i <= n + nowk; i++) f[i] = i;
	for (int i = 1; i <= cnt; i++) ee[i] = e[i];
	sort(ee + 1, ee + cnt + 1, cmp);
	int num = 0, sum = 0;
	for (int i = 1; i <= cnt; i++) {
		int u = ee[i].u, v = ee[i].v;
		if (Find(u) != Find(v)) {
			//cout << u << ' ' << v << "sb";
			f[Find(u)] = Find(v);
			num++, sum += ee[i].w;
		}
		if (sum > ans) return 1e18;
	}
	return sum;
}

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> e[i].u >> e[i].v >> e[i].w;
	}
	int kk = k; k = 0;
	for (int i = 1; i <= kk; i++) {
		cin >> c[i];
		for (int j = 1; j <= n; j++) cin >> a[i][j];
		int f = !c[i];
		if (!f) {
			p[++k] = i; continue;
		}
		for (int j = 1; j <= n; j++) f &= a[i][j];		
		if (f) {
			p[++k] = i; continue;
		}
		else {
			nowk++;
			for (int j = 1; j <= n; j++) 
				e[++m] = {i + n, j, a[i][j]};
		}
	}
	cnt = m, ans = 1e18;
	int nnn = nowk;
	for (int i = 0; i < (1 << k); i++) {
		cnt = m; nowk = nnn;		
		int now = 0;
		for (int j = 0; j < k; j++) {
			if ((i >> j) & 1) {
				now += c[p[j + 1]]; nowk ++;
				for (int l = 1; l <= n; l++) e[++cnt] = (stu){p[j + 1] + n, l, a[p[j + 1]][l]};
			}
		}
		//cout << m << ' ' << cnt << " ";
		//for (int j = 1; j <= cnt; j++) cout << e[j].w << " ";
		//cout << "\n";
		///cout << nowk << " " << cnt << " " << Kruscal() << "\n";
		ans = min(ans, now + Kruscal());
	}
	cout << ans << "\n";
	return 0;
}
