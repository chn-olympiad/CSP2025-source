#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
typedef double f16;
typedef pair <int, int> pii;

const int N = 1e4 + 10 + 10, M = 1e6 + 1e5 + 10, K = 15;
int n, m, k, c[N], fa[N], ew[K][N], ecnt;

struct edge { int u, v, w, in; }; edge e[M];

int find (int u) { return (fa[u] < 0 ? u : fa[u] = find (fa[u])); }
void merge_ (int u, int v)
{
	u = find (u), v = find (v);
	if (u == v) return;
	if (fa[u] < fa[v]) fa[u] += fa[v], fa[v] = u;
	else fa[v] += fa[u], fa[u] = v;
}

void Sub_k0 ()
{
	memset (fa, -1, sizeof (fa));
	sort (e + 1, e + 1 + m, [](edge a, edge b){ return a.w < b.w; });
	i64 ans = 0;
	for (int i = 1; i <= m; i ++)
	{
		int u = e[i].u, v = e[i].v, w = e[i].w;
		if (find (u) == find (v)) continue;
		merge_ (u, v), ans += w;
	}
	cout << ans;
}

void Sub_new0 ()
{
	memset (fa, -1, sizeof (fa));
	sort (e + 1, e + 1 + ecnt, [](edge a, edge b){ return a.w < b.w; });
	i64 ans = 0;
	for (int i = 1; i <= ecnt; i ++)
	{
		int u = e[i].u, v = e[i].v, w = e[i].w;
		if (find (u) == find (v)) continue;
		merge_ (u, v), ans += w;
	}
	cout << ans;
}

void Sub_nxx2 ()
{
	i64 ans = LLONG_MAX;
	for (int st = 0; st < (1 << k); st ++)
	{
		i64 cur = 0; ecnt = m;
		memset (fa, -1, sizeof (fa));
		for (int b = 0; b < k; b ++)
			if ((st >> b) & 1)
			{
				cur += c[n + 1 + b];
				for (int l = 1; l <= n; l ++)
					++ ecnt, e[ecnt] = {l, n + 1 + b, ew[b + 1][l], n + 1 + b}; 
			}
		sort (e + 1, e + 1 + ecnt, [](edge a, edge b){ return a.w < b.w; });
		for (int i = 1; i <= ecnt; i ++)
		{
			int u = e[i].u, v = e[i].v;
			if (find (u) == find (v)) continue;
			merge_ (u, v), cur += e[i].w;
		}
		ans = min (ans, cur);
	}
	cout << ans;
}

int main ()
{
	freopen ("road.in", "r", stdin);
	freopen ("road.out", "w", stdout);
	cin.tie (0) -> sync_with_stdio (0);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i ++)
		cin >> e[i].u >> e[i].v >> e[i].w, e[i].in = 0;
	if (k == 0) return Sub_k0 (), 0;
	ecnt = m;
	bool sub_new0 = true;
	for (int i = 1; i <= k; i ++)
	{
		cin >> c[i + n]; sub_new0 &= (!c[i + n]);
		for (int j = 1, w; j <= n; j ++)
			++ ecnt, cin >> w, ew[i][j] = w, e[ecnt] = {i + n, j, w, i + n};
	}
	if (sub_new0) return Sub_new0 (), 0;
	if (n <= 1e3) return Sub_nxx2 (), 0;
	// 以下为非常 [数据删除] 的假贪心 
	memset (fa, -1, sizeof (fa));
	sort (e + 1, e + 1 + ecnt, [](edge a, edge b){ return a.w < b.w; });
	i64 ans = 0;
	for (int i = 1; i <= ecnt; i ++)
	{
		int u = e[i].u, v = e[i].v, w = e[i].w;
		if (find (u) == find (v)) continue;
		merge_ (u, v), ans += w;
		if (c[e[i].in]) ans += c[e[i].in], c[e[i].in] = 0;
	}
	cout << ans;
	return 0;
}

/*
14:34 哦貌似 T1 贪心假了
14:42 哦好像 T2 就是变种 MST, 跳 T1 码码码 
15:31 伏笔回收, 孩子们 T1 贪心假了 T2 贪心也假了
	  看来和珅被处死是有道理的, 憋当普通和珅了
	  OI 生涯差不多就在这两题上了, 拼拼拼
15:43 T1 糊了个最大减去其他的贪心, 只能过大样例 145
15:55 上面做法的 hack 已出 :
	  10 9 0
	  4 2 2
	  ans : 13 out : 12
	  15 9 8
	  4 0 0
	  ans : 15 out : 13
16:08 哦换了个 max 与 ave 之差, 好像还是有问题, 显然随机生成的那个大样例 5 狗狗都过得去
	  等我 hack 一下 
16:22 先把 T2 MST 的 16pts 打一下, 5min
16:38 [数据删除], 一个 T4 的 8pts 磨了我 15min, 哎是不是要坠机了 (哭哭
16:56 正在调 T1 的 O(n^4) ??? 我要不别说出来丢人现眼了
17:10 哦 T1 现在期望得分仅 50, 废大了
	  想一下 T2 的贪心能不能改对
	  退役倒计时不到 1.5h 
17:29 T2 发现特殊性质 A 很好写, 目前 T2 48pts
	  考虑一下 n <= 10^3 怎么写, 我想要 72 qwq 
17:37 哦我好像会了, 哦不不不我不会, 哥们你总不可能 2^(kn) 枚举放了哪些边以后吧
	  但是 O(2^k * n + n log) 似乎可行 (?) 然而我还没想出来怎么写
	  2^k 显然是枚举新点集, 但是卵用没有, 贪心在 c[j] > 0 的时候还是会假
	  不对似乎可行 ?! 枚举完点集计算 c[j] 的贡献后贪心的正确性即能保证 
	  但是只能过 k <= 5 的部分分 () 我说为什么要搞个 k <= 5 的分 
17:54 woc怎么大样例跑了 4s, 复杂度应该是 O(k * 2^k * m * alpha  的啊 
	  哦我汤碗了, k * 2^k > 100 显然和一个 > 10^6 的 m 乘在一起会炸飞, 何况还有个反阿克曼 
18:04 好吧 T2 弃了弃了, 坠机咯↑
18:07 T1 改了下条件, 现在五个大样例全过但是显然第 4 个是超时的以及第 5 个的正确性玄学
18:14 写了下 T1 特殊性质 A, 我赌整个 S 组的考生没有哪个像我一样又菜又想赢部分分还拿得这么散的
	  想赢当然要有对应的实力啊.
	  哎. 
18:22 写了 T1 的性质 B, 哎.
	  要结束了啊.
	  没啥好写的感想呢.
	  有啥想说的去邮寄里写吧.
	  另外如果 HN 有人做迷惑行为大赏记得也带上我啊,
	  我觉得能写这么多也是迷惑行为了, 浪费了大概 10min.
	  哎,
	  可能要再见啦. 
18:29 woc T4 8pts 假了 ( 
*/
