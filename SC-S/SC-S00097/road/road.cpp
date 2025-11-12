#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstdint>
#include <cstring>
using namespace std;
typedef pair <int, int> pii;
typedef int64_t i64;
const int N = 1e4 + 20; // 检查大小、空间
const int M = 1e6 + 20;
struct Node {
	int u, v, w;
	bool operator < (const Node &p) const {
		return w < p.w;
	}
};
// 先跑一遍 MST 
// 再在 MST (n 条边) 跑 O(2^k 10n \log 10n)

int n, m, k;
vector <Node> v1;
vector <Node> v2;
vector <Node> fv;
int c[N], a[11][N]; // Right
int fa[N]; // Right
i64 ans = 1e18; // Right
i64 success[(1 << 12)];

int read() {
	int x = 0, f = 1; char ch = getchar();
	while(!(ch >= '0' && ch <= '9')) {
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		x = (x << 3) + (x << 1) + (ch - '0');
		ch = getchar();
	}
	return x * f;
}

int Find(int u) {
	if(u == fa[u]) return fa[u];
	fa[u] = Find(fa[u]);
	return fa[u];
}
void solve() {
	n = read(), m = read(), k = read();
	for(int i = 1; i <= m; i++) {
		int u, v, w; u = read(), v = read(), w = read();
		v1.push_back({u, v, w});
	}
	for(int i = 1; i <= k; i++) {
		c[i] = read();
		for(int j = 1; j <= n; j++) a[i][j] = read();
	}
	for(int i = 1; i <= n; i++) fa[i] = i;
	sort(v1.begin(), v1.end());
	i64 lim = 0;
	for(auto k : v1) {
		int u = k.u, v = k.v, w = k.w;
		int uu = Find(u), vv = Find(v);
		if(uu == vv) continue;
		fa[uu] = vv;
		v2.push_back({u, v, w}); 
		lim += w;
	}
	// 以上 跑第一遍 MST ss
	// O(2^k N log N) N = 10n
	for(int s = 0; s < (1 << k); s++) {
		// 加一个剪枝
		bool flag = 0;
		for(int t = s; t; t = (t - 1) & s) {
			if(success[t] > success[0]) flag = 1;
		}
		if(flag) continue;
		i64 res = 0;
		for(int i = 1; i <= k; i++) if((1 << (i - 1)) & s)  {
			res += c[i];
		}
		fv.clear();
		for(auto k : v2) fv.push_back(k);
		for(int i = 1; i <= k; i++) if((1 << (i - 1)) & s) {
			for(int j = 1; j <= n; j++) {
				fv.push_back({i + n, j, a[i][j]});
			}
		}
		for(int i = 1; i <= n + k; i++) fa[i] = i;
		sort(fv.begin(), fv.end());
		for(auto k : fv) {
			int u = k.u, v = k.v, w = k.w;
			int uu = Find(u), vv = Find(v);
			if(uu == vv) continue;
			fa[uu] = vv;
			res += w;
			//cout << "Choose: " << u << " " << v << " " << w << '\n';
		}
		//cout << res << '\n';
		ans = min(ans, res);
		success[s] = res;
	}
	//cout << success[0] << '\n';
	cout << ans << '\n';
	return void(0);
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	solve();
	return 0;
}
// 检查调试语句、i64、空间、时间、代码版本、freopen
// Think twice, code once.
// 注意 Win 和 Linux 双过
// rp++　!!!!!
// 15:37 road ver.1 O(2^k 10n log 10n)
// 17:27 Trying to think 好像不能剪枝了
// 17:56 这道题期望 [64, 80], 80 以上有概率吧看看 CCF 评测机给不给力
// 18:05 加了个剪枝，但愿是对的。
// 18:08 要加个快读
//freopen()  // freopen()
// 总共估分 60 + [64, 80] + 10 + 8 = [142, 158] Maybe AFO
// 我常常追忆过去，只发现了遗憾。