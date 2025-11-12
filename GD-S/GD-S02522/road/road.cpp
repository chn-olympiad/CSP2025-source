#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = l; i <= r; i ++)
#define per(i, r, l) for (int i = r; i >= l; i --)
#define int long long

using namespace std;

const int maxn = 2e4 + 5;

/*
这个题的意思是这样的：
考虑性质 A 就是让你找到那个价值为 "0" 的中转点 x，然后把他加边 {s -> x, x -> t} 然后就可以联通这两条边。
不难发现此时问题是和原问题等价的。

然后现在你就状压强硬加点，如果一个点用不上，那为什么还要加呢？
所以本质就是考虑有所有虚点的最小生成树？如果它没有一个新加的中转点，那么必然劣于原情况。
每次在原图的最小生成树上做最小生成树即可。（忘记为啥了） 
但这样有点慢谔谔。 
*/

struct edge {
	int x, y, z;
	bool operator < (const edge &v) const {
		return z < v.z;
	} 
} ;
vector <edge> t1, t2, t3;

int n, m, k, fa[maxn], a[11][maxn], c[11];
void init() { rep(i, 1, n + k) fa[i] = i; }
int find (int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
bool mer (int x, int y) {
	x = find(x), y = find(y);
	if (x == y) return 0;
	fa[y] = x; return 1;
}
int krus () {
	int ret = 0;
	t2.clear(); t2.shrink_to_fit();
	init();
	sort(t3.begin(), t3.end());
	for (auto [x, y, z] : t3) 
		if (mer(x, y)) ret += z, t2.push_back({x, y, z});
	t3.clear(); t3.shrink_to_fit();
	return ret;
} // t3 存所有边，t2 存新的 mst，t1 存原图最小生成树 
signed main() {
	
	
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	/**/
	cin >> n >> m >> k;
	rep(i, 1, m) {
		int x, y, z;
		scanf("%lld%lld%lld", &x, &y, &z);
		t3.push_back({x, y, z});
	}
	int ans = krus();
	swap(t1, t2); 
	rep(i, 0, k - 1) {
		scanf("%lld", &c[i]);
		rep(j, 1, n) scanf("%lld", &a[i][j]);
	}
	rep(st, 1, (1 << k) - 1) {
		int ret = 0, cnt = 0;
		for (auto it : t1) t3.push_back(it);
		rep(i, 0, k - 1) 
			if (st & (1 << i)) {
				cnt ++;
				ret += c[i];
				rep(j, 1, n) t3.push_back({n + cnt, j, a[i][j]});
			}
		ret += krus();
		if (ret < ans) ans = ret;
	}
	cout << ans;
} 
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/

