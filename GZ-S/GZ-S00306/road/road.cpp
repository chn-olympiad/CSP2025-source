//GZ-S00306 贵阳市云城中学 王乾隆
#include <bits/stdc++.h>
#define X first
#define Y second
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
using namespace std;
using ll = long long int;
using ull = unsigned long long int;
using ld = double;
using pii = pair<int, int>;
constexpr int maxn = 1e6 + 10, mod = 998244353;
struct edge { int u, v, w; } e[maxn], d[13 * 10005]; int id[13], p = 0, tot = 0;
inline int cmp(edge p1, edge p2) { return p1.w < p2.w; }
int n, m, k, fa[13 * 10005], c[13 * 10005], a[13][10010], cf[15], qwq[15]; 
int fd(int x) { return fa[x] == x ? x : fa[x] = fd(fa[x]); }
void solve() {
	scanf("%d%d%d", &n, &m, &k); ll ans = 1e16, sum = 0;
	rep(i, 1, n + k) fa[i] = i;
	rep(i, 1, m) scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
	rep(i, 1, k) {
		scanf("%d", &c[i]);
		rep(j, 1, n) {
			scanf("%d", &a[i][j]), ++p, d[p].u = n + i, d[p].v = j, d[p].w = a[i][j];	
		}
	}
	sort(e + 1, e + m + 1, cmp); int N = n;
	rep(i, 1, m) {
		int x = e[i].u, y = e[i].v; 
		if (fd(x) != fd(y)) {
			++p; d[p].u = x, d[p].v = y, d[p].w = e[i].w; sum += e[i].w;
			fa[fd(x)] = fd(y);
			if (--N == 1) break;
		} 
	} 
	sort(d + 1, d + p + 1, cmp);
	ans = sum;
	// cout << ans << "\n"; exit(0);
	rep(s, 1, (1 << k) - 1) {	
		ll sum = 0; int cnt = 0;
		rep(i, 1, k) if (s >> i - 1 & 1) sum += c[i], ++cnt;
		rep(i, 1, n + k) fa[i] = i;
		int N = n + cnt;
		rep(i, 1, (n + 1) * k - 1) {
			int x = d[i].u, y = d[i].v, w = d[i].w;
			if (x > n && !(s >> x - n - 1 & 1)) continue;
			// cout << x << " " << y << " " << w << "\n";
			if (fd(x) == fd(y)) continue;
			if (x > n) ++cf[x - n], qwq[x - n] = w;
			fa[fd(x)] = fd(y); sum += w; if (--N == 1) break;
		}
		rep(i, 1, k) {
			if ((s >> i - 1 & 1) && cf[i] == 1) sum -= qwq[i];
			cf[i] = qwq[i] = 0;	
		}
		ans = min(ans, sum);
		// cout << sum << "\n"; exit(0);
	}
	printf("%lld\n", ans);
}
int main() {
 	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	solve();
	return 0;
}
/*
我们显然有一个 2^k * mlogn 的做法
接下来考虑怎么规避掉二进制枚举乡镇改造的复杂度
哦也有可能复杂度是 2^k * n，这时候我们可以接受
考虑先不用任何额外边，搞出最小生成树
把最小生成树的边跟额外边塞一起跑个最小生成树
注意到有些额外边是没有用的 
复杂度 O(mlogn + 2^k * n * k * a(n))
考虑怎么去掉这个 k
现在我们不考虑这个树边，考虑这几个乡镇自己之间跑一个最小生成树

实际上可以对这若干个乡镇跑一个传递闭包，然后把它们连起来

这里复杂度实际上可以 O(n + k) 

2^k * k * n *  
卡卡常可以通过 
先贪一遍
令 c 是最多的出现的，按新贡献分别调整到 b 和 a
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

*/

