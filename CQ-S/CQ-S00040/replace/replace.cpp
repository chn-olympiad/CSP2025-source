#include<bits/stdc++.h>
using namespace std;
#define LL long long

const int N = 2e5 + 10, M = 5e6 + 10, P = 13331, mod = 1e9 + 7;
int n, m, ans[N];
char c1[M], c2[M];
struct node
{
	int id;
	LL h;
	vector<char> s1, s2;
	bool operator<(const node &t) const
	{
		return h < t.h;
	}
};
vector<node> s;

int son[M][30], tot;
vector<int> d[M];
void insert(int x)
{
	int p = 1;
	for(char i : s[x].s2)
	{
		int t = i - 'a';
		if(!son[p][t]) son[p][t] = ++tot;
		p = son[p][t];
	}
	d[p].push_back(x);
}

unordered_map<int, int> cnt;
void dfs(int p)
{
	vector<int> delta;
	for(int i : d[p])
		if(!s[i].id)
		{
			LL h = 0;
			for(int j = s[i].s1.size() - 1; ~j; j--)
				h = (h * P + s[i].s1[j]) % mod;
			cnt[h]++, delta.push_back(h);
		}
	for(int i : d[p])
		if(s[i].id)
		{
			int res = cnt[0];
			LL h = 0;
			for(int j = s[i].s1.size() - 1; ~j; j--)
			{
				h = (h * P + s[i].s1[j]) % mod;
				if(cnt.count(h)) res += cnt[h];
			}
			ans[s[i].id] = res;
		}
	
	for(int i = 0; i <= 25; i++)
		if(son[p][i]) dfs(son[p][i]);
	
	for(int i : delta) cnt[i]--;
}

void solve(int l, int r)
{
	if(l == r) return;
	cnt.clear();
	for(int i = 1; i <= tot; i++)
	{
		memset(son[i], 0, sizeof(son[i]));
		d[i].clear();
	}
	tot = 1;
	
	for(int i = l; i <= r; i++) insert(i);
	dfs(1);
}

int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
	{
		scanf("%s%s", c1 + 1, c2 + 1);
		int len = strlen(c1 + 1), l = 0, r = 0;
		for(int j = 1; j <= len; j++)
			if(c1[j] != c2[j])
			{
				r = j;
				if(!l) l = j;
			}
		if(!l) continue;
			
		LL h1 = 0, h2 = 0;
		for(int j = l; j <= r; j++)
		{
			h1 = (h1 * P + c1[j]) % mod;
			h2 = (h2 * P + c2[j]) % mod;
		}
		node a;
		a.id = 0, a.h = h1 * mod + h2;
		a.s1.resize(l - 1), a.s2.resize(len - r);
		for(int j = 1; j < l; j++) a.s1[j - 1] = c1[j];
		for(int j = r + 1; j <= len; j++) a.s2[j - r - 1] = c1[j];
		s.push_back(a);
	}
	for(int i = 1; i <= m; i++)
	{
		scanf("%s%s", c1 + 1, c2 + 1);
		int len = strlen(c1 + 1), l = 0, r = 0;
		if(len != strlen(c2 + 1)) continue;
		for(int j = 1; j <= len; j++)
			if(c1[j] != c2[j])
			{
				r = j;
				if(!l) l = j;
			}
			
		LL h1 = 0, h2 = 0;
		for(int j = l; j <= r; j++)
		{
			h1 = (h1 * P + c1[j]) % mod;
			h2 = (h2 * P + c2[j]) % mod;
		}
		node a;
		a.id = i, a.h = h1 * mod + h2;
		a.s1.resize(l - 1), a.s2.resize(len - r);
		for(int j = 1; j < l; j++) a.s1[j - 1] = c1[j];
		for(int j = r + 1; j <= len; j++) a.s2[j - r - 1] = c1[j];
		s.push_back(a);
	}
	
	sort(s.begin(), s.end());
	for(int i = 0; i < s.size(); i++)
	{
		int j = i;
		while(j + 1 < s.size() && s[j].h == s[j + 1].h) j++;
		solve(i, j);
		i = j;
	}
	
	for(int i = 1; i <= m; i++) printf("%d\n", ans[i]);
	return 0;
}

