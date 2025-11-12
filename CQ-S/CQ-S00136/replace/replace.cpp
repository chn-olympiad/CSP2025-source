#include <stdio.h>
#include <queue>
#include <map>
const long long mod = 1145141919827LL;
const long long k = 31;
int n, q;
char s[5000005], t[5000005];
struct node
{
	int val, pi;
	int son[27];
} p[5000005];
std::map<long long, int> mp;
int pcnt = 0;
void initKMP(int root)
{
	static std::queue<std::pair<int, std::pair<int, char> > > q;
	q.push({ root, { 0, 0 } });
	while (!q.empty())
	{
		int u = q.front().first, fa = q.front().second.first;
		char c = q.front().second.second;
		q.pop();
		if (fa != 0)
		{
			if (p[fa].pi != 0)
			{
				int np = p[fa].pi;
				while (np != root && p[np].son[c] == 0)
					np = p[np].pi;
				if (p[np].son[c] != 0)
					np = p[np].son[c];
				p[u].pi = np;
			}
			else
				p[u].pi = root;
			p[u].val += p[p[u].pi].val;
		}
		for (int i = 0; i <= 26; ++i)
			if (p[u].son[i])
				q.push({ p[u].son[i], { u, i } });
	}
}
void autoMachine(int root)
{
	static std::queue<int> q;
	q.push(root);
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (int i = 0; i <= 26; ++i)
			if (p[u].son[i] == 0)
				if (u == root)
					p[u].son[i] = root;
				else
					p[u].son[i] = p[p[u].pi].son[i];
			else
				q.push(p[u].son[i]);
	}
}
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf("%d%d", &n, &q);
	while (~--n)
	{
		scanf("%s%s", s, t);
		int len = 0;
		while (s[len])
			++len;
		int l = 0, r = len - 1;
		while (l != len && s[l] == t[l])
			++l;
		if (l == len)
			continue;
		while (s[r] == t[r])
			--r;
		long long hash = 0;
		for (int i = l; i <= r; ++i)
		{
			hash = (hash * k + s[i] - 'a') % mod;
			hash = (hash * k + t[i] - 'a') % mod;
		}
		if (mp.find(hash) == mp.end())
			mp[hash] = ++pcnt;
		int root = mp[hash];
		for (int i = 0; i < l; ++i)
		{
			if (p[root].son[s[i] - 'a'] == 0)
				p[root].son[s[i] - 'a'] = ++pcnt;
			root = p[root].son[s[i] - 'a'];
		}
		if (p[root].son[26] == 0)
			p[root].son[26] = ++pcnt;
		root = p[root].son[26];
		for (int i = r + 1; i < len; ++i)
		{
			if (p[root].son[s[i] - 'a'] == 0)
				p[root].son[s[i] - 'a'] = ++pcnt;
			root = p[root].son[s[i] - 'a'];
		}
		++p[root].val;
	}
	for (auto p : mp)
	{
		initKMP(p.second);
		autoMachine(p.second);
	}
	while (~--q)
	{
		scanf("%s%s", s, t);
		int len = 0;
		while (s[len])
			++len;
		int l = 0, r = len - 1;
		while (l != len && s[l] == t[l])
			++l;
		if (l == len)
			continue;
		while (s[r] == t[r])
			--r;
		long long hash = 0;
		for (int i = l; i <= r; ++i)
		{
			hash = (hash * k + s[i] - 'a') % mod;
			hash = (hash * k + t[i] - 'a') % mod;
		}
		if (mp.find(hash) == mp.end())
		{
			puts("0");
			continue;
		}
		int root = mp[hash], ans = 0;
		for (int i = 0; i < l; ++i)
		{
			if (p[root].son[s[i] - 'a'] == 0)
				goto end;
			ans += p[root = p[root].son[s[i] - 'a']].val;
		}
		if (p[root].son[26] == 0)
			goto end;
		ans += p[root = p[root].son[26]].val;
		for (int i = r + 1; i < len; ++i)
		{
			if (p[root].son[s[i] - 'a'] == 0)
				goto end;
			ans += p[root = p[root].son[s[i] - 'a']].val;
		}
	end:
		printf("%d\n", ans);
	}
	return 0;
}