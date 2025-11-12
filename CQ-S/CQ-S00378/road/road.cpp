/*The code is from @luogu-koukilee*/ 
#include <bits/stdc++.h>

typedef long long i64;
typedef int i32;

const i64 MAXN = 2010100, INF = 992009100720100812;

inline void read (i64& x) {scanf ("%lld", &x);}
inline void print (i64 x) {printf ("%lld", x);}
inline void put (i64 x) {print (x), putchar ('\n');} 

/*
	开 T2
	这个数据范围，，怪怪的，，
	欸欸欸，注意到 k 是比较小的，，我寻思这个城市化改造不就又相当于一些边吗，，
	那么我们不就是要求最小生成树吗（
	只不过这些边额外还需要一个权值而已
	我不管啊，这个就非常状态压缩，，假设我们枚举一个子集 S
	那么就相当于多加了 kn 条边，我们要快速求出新图中的最小生成树
	有 48 分是送的
	我们考虑先建出原来的最小生成树
	然后考虑添加一个点之后，最小生成树会怎么变
	感觉这样还是很麻烦的，我们是否可以一次最小生成树解决呢，，
	我们发现很多边是无用的呃呃呃，原图只会保留 n - 1 条边嘛，， 
	首先枚举这个子集的过程是 2^n 的，并且还没啥好优化的，，
	一个点能让原来的边，，这个每个点的权重太恶心了，，
	我们先只考虑这些边怎么样，
	我们先按照所有的边排序，然后二分，使用前 i 个能不能构成出来，，不对啊 
	有一个可能实现的方法？先把所有边的最小生成树建造出来
	感觉这个 n = 1e4,,呃呃呃
	首先如果我们使用普通的边都把一些需要花费的边给打败了，那么就不需要理会这些边了
	这样下来，有用的点的规模会大大下降？
	其实也下降的不多，只到了 (k+1)n 那么先选前面的还是先选后面的更优呢？
	我们直接考虑选了 v 之后会不会更优，，，不管了，先把能打的打了，欸等等，突然发现是将第 j 个乡镇给，，
	那么说明能城市化的是一段连续的乡镇，我服了，怎么是存在 i 满足啊，这怎么做，， 
	感觉 kn2^n 还是有点太吃操作了，，
	我们把每一个值都先插一个 c_i 进去，这样第一次遇到的时候不会更劣！！！
	然后我们再动态维护后面的最小值即可？？！！！
	，题目读错了，这个乡镇不是城市，是新的点，，没事，，也可以做？？
	完了，， 没事，一样做，， 假了，，废了，， 
*/

struct node {i64 x, y, v;} g[MAXN], sg[MAXN];

i64 n, m, k, s[MAXN], c[MAXN], vis[MAXN], rv[MAXN];
std::vector <i64> F[12];

i64 find (i64 x) {return x == s[x] ? x : s[x] = find (s[x]);}

inline void SUB_1 ()  {
	std::sort (g + 1, g + m + 1, [&] (node a, node b)  {
		return a.v < b.v;
	});
	
	i64 ans = 0;
	
	for (i32 i = 1; i <= m; i++) {
		i64 x = find (g[i].x), y = find (g[i].y);
		if (x != y) 
			ans += g[i].v, s[x] = y;		

	}
	
	put (ans);
} 

struct cnode {
	i64 x, y, val, id;
	
	bool operator < (const cnode& nex) const {
		return val == nex.val ? (y == nex.y ? x < nex.x : y < nex.y) : val < nex.val;
	}
};

std::map <cnode, bool> Del;

inline void SUB_2 ()  {
	std::multiset <cnode> p;
	for (i32 i = 1; i <= m; i++) 
		p.insert ((cnode) {g[i].x, g[i].y, g[i].v, 0});
	for (i32 i = 1; i <= k; i++) {
		i64 t = 1;
		for (auto it : F[i]) {
			p.insert ((cnode) {i + n, t, it, i});
			t++;
		}
	}
	
	i64 ans = 0, d = 0;
	
	while (!p.empty ()) {
		cnode nex = *p.begin (); p.erase (p.begin ());
//		printf ("%lld %lld %lld %lld\n", nex.x, nex.y, nex.val, nex.id);
		if (Del[nex]) continue;
		
		i64 x = find (nex.x), y = find (nex.y);
		if (x != y) {
			if (!nex.id || (nex.id && vis[nex.id])) {
				if (!nex.id)
					s[x] = y, ans += nex.val;
				else {
					if (vis[nex.id] == 1) {
						ans += nex.val + rv[nex.id], s[x] = y;
						i64 t = 1;
						for (auto it : F[nex.id]) {
							Del[(cnode) {nex.id + n, t, c[nex.id] + it, nex.id}] = 1;
							p.insert ((cnode) {nex.id + n, t, it, nex.id});
							t++;
						}
						vis[nex.id] = 2;
					} else s[x] = y, ans += nex.val;
				}
				d++;
			}
		}
		
		if (d == n - 1) break;
		
		if (nex.id && !vis[nex.id]) {
			i64 t = 1;
			for (auto it : F[nex.id]) {
				Del[(cnode) {nex.id + n, t, it, nex.id}] = 1;
				p.insert ((cnode) {nex.id + n, t, c[nex.id] + it, nex.id});
				t++;
			}
			s[x] = y; vis[nex.id] = 1, rv[nex.id] = nex.val;
		}
	}
	
	put (ans);
}

inline void SUB_3 () noexcept {
	std::sort (g + 1, g + m + 1, [&] (node a, node b)  {
		return a.v < b.v;
	});
	
	i64 ans = 0, cnt = 0, d = 0;
	
	for (i32 i = 1; i <= m; i++) {
		i64 x = find (g[i].x), y = find (g[i].y);
		if (x != y) 
			ans += g[i].v, s[x] = y, g[++cnt] = g[i], d++;
		if (d == n - 1) break;
	}
	
	i64 S = (1ll << k) - 1;
	
	for (i32 sa = 0; sa < S; sa++) {
		if ((double)clock () / CLOCKS_PER_SEC > 0.95) {
			put (ans); return;
		}
		i64 sum = 0, tot = 0, d = 0;
		for (i32 j = 1; j <= k; j++) {
			if ((sa >> (j - 1)) & 1) {
				i64 t = 1; sum += c[j];
				for (auto it : F[j])	
					sg[++tot] = (node) {j + n, t++, it}; 
			}
		}
		for (i32 i = 1; i <= cnt; i++)
			sg[++tot] = g[i];
		if (sum >= ans) continue;
		
		std::sort (sg + 1, sg + tot + 1, [&] (node a, node b)  {
			return a.v < b.v;
		});
		for (i32 t = 1; t <= n + k; t++)
			s[t] = t;
		
		for (i32 i = 1; i <= tot; i++) {
			i64 x = find (sg[i].x), y = find (sg[i].y);
			if (x != y) 
				sum += sg[i].v, s[x] = y, d++;
			if (sum >= ans) break;
		}
		ans = std::min (ans, sum);
	}
	
	put (ans);
}

int main () {
	freopen ("road.in", "r", stdin);
	freopen ("road.out", "w", stdout);
	read (n), read (m), read (k);
	
	for (i32 i = 1; i <= m; i++) {
		read (g[i].x), read (g[i].y), read (g[i].v);
	}
	for (i32 i = 1; i <= n + k; i++) s[i] = i;
	for (i32 i = 1; i <= k; i++) {
		read (c[i]); 
		for (i64 j = 1, x; j <= n; j++) {
			read (x), F[i].push_back (x);
		}
	}
	
	if (!k) SUB_1 ();
	else if (k <= 5) SUB_3 ();
	else SUB_3 ();
	
	return 0;
}
