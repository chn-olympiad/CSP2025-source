#include <bits/stdc++.h>
#define lep(i, a, b) for (int i = (a), ed##i = (b); i <= ed##i; ++i)
#define rep(i, a, b) for (int i = (a), ed##i = (b); i >= ed##i; --i)
#define pb push_back
#define fi first
#define se second

const int LN = 4e4 + 7;
const int LM = 2e6;
typedef long long ll;

bool FISPOS;

const ll inf = 1e18;
int n, m, k, c[11][LN], fa[LN], tot, cnt;
ll ans, sum;
std::array<int, 3> e[LM], a[LM], b[LM];

bool ENDPOS;

int fnd(int x) { return fa[x] == x ? x : fa[x] = fnd(fa[x]); }
bool mrg(int x, int y) { if ((x = fnd(x)) != (y = fnd(y))) return fa[x] = y, --tot, true; return false; }
void dfs(int u, int p, ll su) {
	if (u == k) { if (!p) return;
		lep(i, 1, cnt) a[i] = b[i];
		std::sort(a + 1, a + 1 + cnt); tot = n + p, sum = su;
		lep(i, 1, n + k) fa[i] = i;
		lep(i, 1, cnt) if (tot > 1 and mrg(a[i][1], a[i][2])) {
			sum += a[i][0]; if (sum > ans) return;
		}
		ans = std::min(ans, sum);
		return;
	}
	dfs(u + 1, p, su);
	lep(i, 1, n) b[++cnt] = { c[u][i], u + 1 + n, i };
	dfs(u + 1, p + 1, su + c[u][0]);
	cnt -= n;
}

int main() {
#ifndef DEBUG
	freopen("road.in", "r", stdin);
	freopen("road.out","w",stdout);
#endif
	std::ios::sync_with_stdio(false),
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	int c1 = clock();
	
	std::cin >> n >> m >> k;
	lep(i, 1, n) fa[i] = i; tot = n;
	lep(i, 1, m) std::cin >> e[i][1] >> e[i][2] >> e[i][0];
	lep(j, 0, k - 1) {
		std::cin >> c[j][0];
		lep(i, 1, n) std::cin >> c[j][i];
	}
	
	std::sort(e + 1, e + 1 + m);
	lep(i, 1, m) if (tot > 1 and mrg(e[i][1], e[i][2])) sum += e[i][0], b[++cnt] = e[i];
	ans = sum, sum = 0;
	
	dfs(0, 0, 0);
	std::cout << ans << '\n';
	
	std::cerr << clock() - c1 << " ms " << std::fabs(&FISPOS - &ENDPOS) / 1024 / 1024 << " MB\n";
	return 0;
}
