#include <bits/stdc++.h>
#define mod 998244353
using namespace std;
using ll = long long;
using ull = unsigned long long;
int n, m, c[505];
ll dp[1 << 20][20];
string s;
int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	// cerr << sizeof(dp) / 1024 / 1024 << endl;
	cin >> n >> m >> s;
	s = '#' + s;
	for (int i = 1; i <= n; i++)
	{
		cin >> c[i];
	}
	sort(c + 1, c + n + 1);
	if (m == n)
	{
		ll ans = 1;
		for (int i = 1; i <= n; i++)
		{
			ans = ans * i % mod;
			if (s[i] == '0' || c[i] == 0)
			{
				ans = 0;
			}
		}
		cout << ans << '\n';
		return 0;
	}
	if (n > 20)
	{
		cout << 0 << '\n';
		return 0;
	}
	dp[0][0] = 1;
	for (int mask = 0; mask < (1 << n); mask++)
	{
		int i = 1 + __builtin_popcount(mask);
		// int max_fail = min(n - m, i);
		for (int fail = 0; fail < i; fail++)
		{
			for (int j = 0; j < n; j++)
			{
				if (~(mask >> j) & 1)
				{
					(dp[mask ^ (1 << j)][fail + (fail >= c[j + 1] || s[i] == '0')] += dp[mask][fail]) %= mod;
				}
			}
		}
		/*
		for (int fail = 0; fail < i; fail++)
		{
			cout << "dp[" << bitset<3>(mask) << "][" << fail << "] = " << dp[mask][fail] << endl;
		}
		*/
	}
	ll ans = 0;
	for (int i = 0; i <= n - m; i++)
	{
		ans = (ans + dp[(1 << n) - 1][i]) % mod;
	}
	cout << ans << '\n';
	return 0;
}

/*

T1 先贪心后反悔，暴力反悔直到合法

T2 先跑 kruskal 找出一颗最小生成树，不管选什么新点，都不会用除了这个生成树以外的原边，可以证，之后暴力枚举新点集合？分治归并排序优化边的排序，O(n * k * 2^k * log(k) * 阿尔法(n))。好像唐了。可以先排好全部 n*k+n-1 条边，每次枚举集合之后扫一遍全部边，O(n * k * 2^k * 阿尔法(n))，n=10010 阿尔法(n)<=5

T3 最先最先把 s[i][1]=s[i][2] 的刨去，先对于每一对查询串找出替换位置，包含这个位置的替换才是可以的，双串匹配，字符集大小平方一下？空间和时间都会爆炸。出题人显然想要一个 O(n*log(n)) 或 O(n*sigma) 及以下的做法，但是感觉双串匹配的转化方向是对的。观察到空间 2GB 是否从空间开刀？空间大就是可以 ACAM？（后来这个双串匹配被毙掉了）
先哈希？对于每一对 s 去掉相同的头尾，t 同理，把剩下的东西哈希一下，赌不会冲突，t 需要找和自己哈希值一样的 s。同一种哈希值建立前缀倒序和后缀正序的字典树？没法同时查吧？
似乎是可以的，在其中一颗字典树上找到前缀字典树的 dfn 区间，后缀字典树做一个字典树套平衡树（还好当天上午背了 pbds）在后面的对应节点找元素数量。时间复杂度 O(n*log(n))，空间复杂度 O(n*sigma+n*pbds)。非常奇怪解法。（分析复杂度的 n=\sum L）
上一段似乎想假了，要找的是两个字典树上的链上的节点交集大小，不是子树。做不了。
难道是双串匹配？但是这个哈希不同段的东西看起来很有用？
把询问建前后反正字典数，拿着串在上面标记，然后作一下到根的和！！！正难则反！！！
每一个后缀正字典树的节点挂一个按子树内串在前缀反字典树内的节点 dfn 排序的集合，每次是对这个集合的一个段的加，差分打个标记，用 vector 维护这个集合。

LCWZH

想了半小时 T1 T2；T1 写了十分钟，没调过了大样例；又想了一会 T2，感觉优化得差不多了，写了，没调过了大样例，算算时间差不多卡线，直到这里已经过了 70min 了；开始想 T3，感觉很奇怪的题啊，想了很多方法总是被卡；想了半个小时胡出一个屎山，感觉挺好，开写；20min 后突然发现想假了；然后 10min 后发现把逻辑反过来就是对的不需要 pbds；还是不对；似乎对了；16:43 开写，17:11 写完了，开调；17:32 调完了，小样例过来之后大样例一遍过，有点玄，希望没事，7KB；开始 T4，每时间做了，看看有多少暴力可以骗，状压是好写的，可是 20pts 太少，m=n 是送的，n=500 很奇怪；花了一点点时间，写了 n=m 和 n<=18。

*/