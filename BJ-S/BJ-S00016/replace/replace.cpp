#include <bits/stdc++.h>
// #include <bits/extc++.h>
using namespace std;
/*
using namespace __gnu_pbds;
using inner_tree = tree<pair<int, int>, // {前缀字典树 dfn，谐音串 id}
						null_type,
						less<pair<int, int> >,
						rb_tree_tag,
						tree_order_statistics_node_update>;
*/
using ull = unsigned long long;
#define B 3111
#define P 24435339042357
#define MAXN 1000005
#define MAXL 10000005
int n, m, s_first_diff[MAXN], s_last_diff[MAXN], t_first_diff[MAXN], t_last_diff[MAXN], s_len[MAXN], t_len[MAXN];
int dfn[MAXL], dfn_end[MAXL], stamp, t_pre_dfn[MAXN];
int pre_id[MAXN], sur_id[MAXN], ans[MAXN];
string s[MAXN][2], t[MAXN][2];
struct node {
	int son[27];
	int fa;
	vector<pair<int, int> > pre_dfn;
	// inner_tree pre_id;
} pool[MAXL];
int pool_pointer;
int new_node()
{
	return ++pool_pointer;
}
unordered_map<ull, int> pre_root, sur_root;
ull s_hash[MAXN];
#define cd1e(a, ...) cout << #a << '[' << __VA_ARGS__ << "] = " << a[__VA_ARGS__] << endl;
bool cmp(pair<int, int> x, pair<int, int> y)
{
	return t_pre_dfn[x.first] < t_pre_dfn[y.first];
}
void dfs(int id)
{
	if (!id) return;
	// cout << "dfs(" << id << ")" << endl;
	dfn[id] = ++stamp;
	for (int i = 0; i < 26; i++)
	{
		if (pool[id].son[i])
		{
			pool[pool[id].son[i]].fa = id;
			dfs(pool[id].son[i]);
		}
	}
	dfn_end[id] = stamp;
}
void dfs_fa(int id)
{
	if (!id) return;
	// cout << "dfs_fa(" << id << ")" << endl;
	// dfn[id] = ++stamp;
	for (int i = 0; i < 26; i++)
	{
		if (pool[id].son[i])
		{
			pool[pool[id].son[i]].fa = id;
			dfs_fa(pool[id].son[i]);
		}
	}
	// dfn_end[id] = stamp;
}
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> m;
	int unique_count = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> s[++unique_count][0];
		cin >> s[unique_count][1];
		if (s[unique_count][0] == s[unique_count][1])
		{
			s[unique_count][0] = s[unique_count][1] = "";
			unique_count--;
		}
	}
	n = unique_count;
	for (int i = 1; i <= n; i++)
	{
		// cout << "s[" << i << "] : " << s[i][0] << ' ' << s[i][1] << endl;
		s_last_diff[i] = (s_len[i] = s[i][0].size()) - 1;
		while (s[i][0][s_first_diff[i]] == s[i][1][s_first_diff[i]]) s_first_diff[i]++;
		while (s[i][0][s_last_diff[i]] == s[i][1][s_last_diff[i]]) s_last_diff[i]--;
	}
	for (int i = 1; i <= m; i++)
	{
		cin >> t[i][0] >> t[i][1];
		// cout << "t[" << i << "] : " << t[i][0] << ' ' << t[i][1] << endl;
		if (t[i][0].size() != t[i][1].size())
		{
			continue;
		}
		t_last_diff[i] = (t_len[i] = t[i][0].size()) - 1;
		while (t[i][0][t_first_diff[i]] == t[i][1][t_first_diff[i]]) t_first_diff[i]++;
		while (t[i][0][t_last_diff[i]] == t[i][1][t_last_diff[i]]) t_last_diff[i]--;
		ull hash_value = 0;
		// cout << "diff : ";
		for (int j = t_first_diff[i]; j <= t_last_diff[i]; j++)
		{
			hash_value = (hash_value * B + (t[i][0][j] - 'a' + 1) * 26 + t[i][1][j] - 'a' + 1) % P;
			// cout << t[i][0][j] << t[i][1][j];
		}
		// cout << endl;
		// cout << "prefix : ";
		if (!pre_root[hash_value]) pre_root[hash_value] = new_node();
		pre_id[i] = pre_root[hash_value];
		for (int j = t_first_diff[i] - 1; ~j; j--)
		{
			// cout << t[i][0][j];
			if (!pool[pre_id[i]].son[t[i][0][j] - 'a'])
			{
				pool[pre_id[i]].son[t[i][0][j] - 'a'] = new_node();
			}
			pre_id[i] = pool[pre_id[i]].son[t[i][0][j] - 'a'];
		}
		// cout << endl;
		// cout << "surfix : ";
		if (!sur_root[hash_value]) sur_root[hash_value] = new_node();
		sur_id[i] = sur_root[hash_value];
		for (int j = t_last_diff[i] + 1; j < t_len[i]; j++)
		{
			// cout << t[i][0][j];
			if (!pool[sur_id[i]].son[t[i][0][j] - 'a'])
			{
				pool[sur_id[i]].son[t[i][0][j] - 'a'] = new_node();
			}
			sur_id[i] = pool[sur_id[i]].son[t[i][0][j] - 'a'];
		}
		// cout << endl;
		// cout << "t : i = " << i << endl;
		// cout << "hash = " << hash_value << endl << endl << endl;
	}
	for (pair<ull, int> i : pre_root)
	{
		dfs(i.second); // get dfn fa
	}
	for (pair<ull, int> i : sur_root)
	{
		dfs_fa(i.second); // get fa
	}
	for (int i = 1; i <= m; i++)
	{
		t_pre_dfn[i] = dfn[pre_id[i]];
		int x = sur_id[i];
		// cout << "MARKING " << i << endl;
		// cd1e(sur_id, i);
		while (x)
		{
			pool[x].pre_dfn.push_back({i, 0});
			// cout << i << " -> " << x << endl;
			// cout << "fa[" << x << "] = " << pool[x].fa << endl;
			x = pool[x].fa;
		}
	}
	for (int i = 1; i <= pool_pointer; i++)
	{
		sort(pool[i].pre_dfn.begin(), pool[i].pre_dfn.end(), cmp);
		/*
		if (!pool[i].pre_dfn.empty())
		{
			// cout << i << " : ";
			for (pair<int, int> j : pool[i].pre_dfn)
			{
				// cout << j.first << ' ';
			}
			// cout << endl;
		}
		*/
	}
	for (int i = 1; i <= n; i++)
	{
		ull hash_value = 0;
		for (int j = s_first_diff[i]; j <= s_last_diff[i]; j++)
		{
			hash_value = (hash_value * B + (s[i][0][j] - 'a' + 1) * 26 + s[i][1][j] - 'a' + 1) % P;
		}
		// cout << "s : i = " << i << endl;
		// cout << "hash = " << hash_value << endl;
		int s_pre_id = pre_root[hash_value];
		// cout << "prefix : ";
		for (int j = s_first_diff[i] - 1; ~j; j--)
		{
			// cout << s[i][0][j];
			s_pre_id = pool[s_pre_id].son[s[i][0][j] - 'a'];
		}
		// cout << endl;
		// cout << "surfix : ";
		int s_sur_id = sur_root[hash_value];
		for (int j = s_last_diff[i] + 1; j < s_len[i]; j++)
		{
			// cout << s[i][0][j];
			s_sur_id = pool[s_sur_id].son[s[i][0][j] - 'a'];
		}
		// cout << endl;
		if (s_sur_id == 0 || s_pre_id == 0)
		{
			// cout << "s[" << i << "] fail : " << s_pre_id << ' ' << s_sur_id << endl << endl << endl << endl;
			continue;
		}
		// cout << "s[" << i << "] success : " << s_pre_id << ' ' << s_sur_id << endl;
		unsigned int l = 0, r = pool[s_sur_id].pre_dfn.size();
		while (l < r)
		{
			int mid = (l + r) / 2;
			if (t_pre_dfn[pool[s_sur_id].pre_dfn[mid].first] >= dfn[s_pre_id])
			{
				r = mid;
			}
			else
			{
				l = mid + 1;
			}
		}
		if (l != pool[s_sur_id].pre_dfn.size())
		{
			pool[s_sur_id].pre_dfn[l].second++;
		}
		l = 0, r = pool[s_sur_id].pre_dfn.size();
		while (l < r)
		{
			int mid = (l + r) / 2;
			if (t_pre_dfn[pool[s_sur_id].pre_dfn[mid].first] > dfn_end[s_pre_id])
			{
				r = mid;
			}
			else
			{
				l = mid + 1;
			}
		}
		if (l != pool[s_sur_id].pre_dfn.size())
		{
			pool[s_sur_id].pre_dfn[l].second--;
		}
		// cout << endl << endl << endl;
	}
	for (int i = 1; i <= pool_pointer; i++)
	{
		for (unsigned int j = 0; j < pool[i].pre_dfn.size(); j++)
		{
			if (j)
			{
				pool[i].pre_dfn[j].second += pool[i].pre_dfn[j - 1].second;
			}
			ans[pool[i].pre_dfn[j].first] += pool[i].pre_dfn[j].second;
		}
	}
	for (int i = 1; i <= m; i++)
	{
		cout << ans[i] << '\n';
	}
	// for (int i = 1; i <= n; i++)
	// {
		// cd1e(s_first_diff, i);
		// cd1e(s_last_diff, i);
	// }
	// for (int i = 1; i <= m; i++)
	// {
		// cd1e(pre_id, i);
		// cd1e(sur_id, i);
		// cd1e(t_first_diff, i);
		// cd1e(t_last_diff, i);
	// }
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

想了半小时 T1 T2；T1 写了十分钟，没调过了大样例；又想了一会 T2，感觉优化得差不多了，写了，没调过了大样例，算算时间差不多卡线，直到这里已经过了 70min 了；开始想 T3，感觉很奇怪的题啊，想了很多方法总是被卡；想了半个小时胡出一个屎山，感觉挺好，开写；20min 后突然发现想假了；然后 10min 后发现把逻辑反过来就是对的不需要 pbds；还是不对；似乎对了；16:43 开写，17:11 写完了，开调

*/