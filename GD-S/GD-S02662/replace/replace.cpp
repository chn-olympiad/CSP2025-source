#include<bits/stdc++.h>
#define ll long long
#define pa pair<int,int>
#define mk make_pair
#define fi first
#define se second
using namespace std;
const int N = 6000010;
const ll mod = 998244353, B = 101;
int sum[N];
int n, q;
int ch[N][26], tot = 0;
int dfn[N], siz[N], dft = 0;
int bghe[N], enhe[N];
int mato = 0;
int ans[N];
unordered_map<ll, int>ma;
vector<int>sd[N];
vector<pa>qu[N];
void add(int x, int v)
{
	while(x <= tot)
	{
		sum[x] += v;
		x += x&-x;
	}
}
int query(int x)
{
	int ans = 0;
	while(x)
	{
		ans += sum[x];
		x -= x&-x;
	}
	return ans;
}
char s[N], t[N];
ll has(char *s, int bg, int en)
{
	ll sm = 0;
	for(int i = bg; i <= en; i++)
		sm = (sm * B + s[i] - 'a' + 1) % mod;
	return sm;
}
void dfs(int now)
{
	dfn[now] = ++dft;
	siz[now] = 1;
	for(int i = 0; i < 26; i++)
		if(ch[now][i])
		{
			dfs(ch[now][i]);
			siz[now] += siz[ch[now][i]];
		}
}
void work(int now)
{
	for(int to : sd[now])
	{
		add(dfn[to], 1);
		add(dfn[to] + siz[to], -1);
	}
	for(pa to : qu[now])
		ans[to.se] = query(dfn[to.fi]);
	for(int i = 0; i < 26; i++)
		if(ch[now][i])
			work(ch[now][i]);
	for(int to : sd[now])
	{
		add(dfn[to], -1);
		add(dfn[to] + siz[to], 1);
	}
}
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf("%d%d", &n, &q);
	for(int i = 1; i <= n; i++)
	{
		scanf("%s%s", s + 1, t + 1);
		int m = strlen(s + 1);
		int bg = 0, en = 0;
		for(int j = 1; j <= m; j++)
		if(s[j] != t[j])
		{
			if(!bg)bg = j;
			en = j;
		}
		if(!bg)continue;
		ll v = (has(s, bg, en) << 30) + has(t, bg, en);
		if(!ma.count(v))
		{
			ma[v] = ++mato;
			bghe[mato] = ++tot;
			enhe[mato] = ++tot;
		}
		int id = ma[v];
		int now = enhe[id];
		for(int j = en + 1; j <= m; j++)
		{
			if(!ch[now][s[j] - 'a'])ch[now][s[j] - 'a'] = ++tot;
			now = ch[now][s[j] - 'a'];
		}
		int sn = bghe[id];
		for(int j = bg - 1; j; j--)
		{
			if(!ch[sn][s[j] - 'a'])ch[sn][s[j] - 'a'] = ++tot;
			sn = ch[sn][s[j] - 'a'];
		}
		sd[sn].push_back(now);
//		printf("%lld %d %d\n", v, sn, now);
	}
	for(int i = 1; i <= q; i++)
	{
		scanf("%s%s", s + 1, t + 1);
		if(strlen(s + 1) != strlen(t + 1))continue;
		int m = strlen(s + 1);
		int bg = 0, en = 0;
		for(int j = 1; j <= m; j++)
		if(s[j] != t[j])
		{
			if(!bg)bg = j;
			en = j;
		}
		ll v = (has(s, bg, en) << 30) + has(t, bg, en);
		if(!ma.count(v))continue;
		int id = ma[v];
		int sb = bghe[id], se = enhe[id];
		for(int j = en + 1; j <= m; j++)
		{
			if(!ch[se][s[j] - 'a'])break;
			se = ch[se][s[j] - 'a'];
		}
		for(int j = bg - 1; j; j--)
		{
			if(!ch[sb][s[j] - 'a'])break;
			sb = ch[sb][s[j] - 'a'];
		}
		if(se && sb)qu[sb].push_back(mk(se, i));
//		printf("%lld %d %d\n", v, se, sb);
	}
	for(int i = 1; i <= mato; i++)
		dfs(enhe[i]);
	for(int i = 1; i <= mato; i++)
		work(bghe[i]);
	for(int i = 1; i <= q; i++)printf("%d\n", ans[i]);
	return 0;
}
