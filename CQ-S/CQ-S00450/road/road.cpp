#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10005, MAXM = 1000005;
int u[MAXM + 10 * MAXN], v[MAXM + 10 * MAXN], w[MAXM + 10 * MAXN];
int ord[MAXM]; int c[11]; vector<int> mord[11];
namespace dsu {
	int fa[MAXN + 11]; void build(int n) {for (int i = 1; i <= n; i++) fa[i] = i;}
	int findfa(int a) {return fa[a] == a ? a : fa[a] = findfa(fa[a]);}
	void merge(int u, int v) {fa[findfa(u)] = findfa(v);}
}
vector<int> lst[1 << 10];

char buf[1 << 25], *S, *T;
char gc() {return S == T && (T = (S = buf) + fread(buf, 1, 1 << 25, stdin)) == buf ? 0 : *S++;}
int read() {
	char ch; while ((ch = gc()) <= ' '); int x = ch - '0';
	while ((ch = gc()) > ' ') x = 10 * x + ch - '0'; return x;
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	const auto cmp = [&](int x, int y) {return w[x] < w[y];};
	int n = read(), m = read(), k = read();
	for (int i = 1; i <= m; i++) {
		u[i] = read(); v[i] = read(); w[i] = read(); ord[i] = i;
	} dsu::build(n);
	sort(ord + 1, ord + 1 + m, cmp);
	vector<int> hi; hi.reserve(n); long long ans = 0; for (int _ = 1; _ <= m; _++) {
		int i = ord[_]; if (dsu::findfa(u[i]) != dsu::findfa(v[i])) {
			dsu::merge(u[i], v[i]); hi.push_back(i); ans += w[i];
		}
	}
	// printf("%lld\n", ans);
	int cnt = m;
	for (int i = 1; i <= k; i++) {
		c[i] = read(); for (int j = 1; j <= n; j++) {
			cnt++; w[cnt] = read(), mord[i].push_back(cnt);
			u[cnt] = n + i; v[cnt] = j;
		}
		sort(mord[i].begin(), mord[i].end(), cmp);
	}
	lst[0] = hi; for (int i = 1; i < 1 << k; i++) {
		for (int j = 0; j < k; j++) if (i >> j & 1) {
			lst[i].resize(lst[i ^ 1 << j].size() + mord[j].size());
			merge(lst[i ^ 1 << j].begin(), lst[i ^ 1 << j].end(), mord[j].begin(), mord[j].end(), lst[i].begin(), cmp);
			vector<int> tmp; tmp.reserve(n + k);
			dsu::build(n + k); long long ret = 0;
			for (int j = 0; j < k; j++) if (i >> j & 1) ret += c[j];
			for (int x : lst[i]) {
				if (dsu::findfa(u[x]) != dsu::findfa(v[x])) {
					dsu::merge(u[x], v[x]); ret += w[x]; tmp.push_back(x);
				}
			}
			lst[i].swap(tmp); ans = min(ans, ret);
			break;
		}
	}
	printf("%lld\n", ans);
}
/*
run road < road1.in > road1.out
run road < road2.in > road2.out
run road < road3.in > road3.out
run road < road4.in > road4.out
diff road1.out road1.ans -Z
diff road2.out road2.ans -Z
diff road3.out road3.ans -Z
diff road4.out road4.ans -Z
*/
/*
read in UTF-8 mode

我草懒得写这个 byd 超速检测了，纯粹依托
*/