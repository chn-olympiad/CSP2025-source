#include <bits/stdc++.h>
#define il inline
#define int long long
using namespace std;
il void read(int &x) {
	x = 0; bool f = 0; char c = getchar();
	while (!isdigit(c)) f |= (c == '-'), c = getchar();
	while (isdigit(c)) x = x * 10 + c - 48, c = getchar();
	x = f ? -x : x;
}

const int Maxn = 100005;
const int Maxm = 1000005;
const int Maxk = 20;
struct Line {int u, v, w;} line[Maxm << 2];
int n, m, k, c[Maxk], a[Maxk][Maxn], ans, tot, g[1005][1005], sum;

namespace Sub1 {
	int fa[Maxn];
	il bool cmp(Line a, Line b) {return a.w < b.w;}
	il int getf(int u) {return u == fa[u] ? u : fa[u] = getf(fa[u]);}
	il void solve() {
		for (int i = 1; i <= n; i ++) fa[i] = i;
		sort(line + 1, line + tot + 1, cmp);
		int cnt = 0; ans = 0;
		for (int i = 1; i <= tot; i ++) {
			int fu = getf(line[i].u), fv = getf(line[i].v);
			if (fu != fv) {
				cnt ++;
				fa[fu] = fv;
				ans += line[i].w;
				if (cnt == n - 1) return ;
			}
		}
	}
}

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	read(n), read(m), read(k);
	for (int i = 1; i <= m; i ++) {
		int u, v, w; read(u), read(v), read(w);
		line[++tot] = {u, v, w};
	}
	bool tagA = 1;
	for (int i = 1; i <= k; i ++) {
		read(c[i]);
		sum += c[i];
		if (c[i] != 0) tagA = 0;
		bool tagin = 0;
		for (int j = 1; j <= n; j ++)
			read(a[i][j]), tagin |= (a[i][j] == 0), sum += a[i][j];
		if (tagin == 0) tagA = 0;
	}
	if (k == 0) {
		Sub1::solve();
		cout << ans << "\n";
		return 0;
	}
	//此时 ans 是最终答案的上界 
	if (tagA) { //特殊性质 A 
		for (int i = 1; i <= n; i ++)
			for (int j = 1; j <= n; j ++)
				g[i][j] = 2000000000;
		for (int i = 1; i <= k; i ++) {
			for (int x = 1; x <= n; x ++)
				for (int y = 1; y <= n; y ++)
					if (x != y)
						g[x][y] = min(g[x][y], a[i][x] + a[i][y]);
		}
		for (int x = 1; x <= n; x ++)
			for (int y = 1; y <= n; y ++) line[++tot] = {x, y, g[x][y]};
		Sub1::solve();
		cout << ans << "\n";
		return 0;
	}
	cout << sum << "\n";
	fclose(stdin), fclose(stdout);
	return 0;
}
/*
504898585


Ren5Jie4Di4Ling5%
*/
