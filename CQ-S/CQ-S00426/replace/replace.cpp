#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
constexpr int maxn = 200005, maxm = 5000005;
int n, q, head, tail, idx, ch[maxm][26], fail[maxm], que[maxm], ans[maxn];
ull flag[maxm][2];
string s[maxn][2], t[maxn][2];
void init()
{
	fail[0] = -1, head = tail = 0;
	for(int i = 0; i < 26; ++i) if(ch[0][i]) que[tail++] = ch[0][i], fail[ch[0][i]] = 0;
	while(head < tail)
	{
		int t = que[head++];
		// printf("fail %d,%d\n", t, fail[t]);
		flag[t][0] |= flag[fail[t]][0];
		flag[t][1] |= flag[fail[t]][1];
		for(int i = 0; i < 26; ++i)
		{
			if(ch[t][i]) fail[ch[t][i]] = ch[fail[t]][i], que[tail++] = ch[t][i];
			else ch[t][i] = ch[fail[t]][i];
		}
	}
}
void clear()
{
	for(int i = 0; i <= idx; ++i) memset(ch[i], 0, sizeof ch[i]), flag[i][0] = flag[i][1] = fail[i] = 0;
	idx = 0;
}
void insert(string &str, ull f1, ull f2)
{
	int now = 0;
	for(auto c : str)
	{
		if(!ch[now][c - 'a']) ch[now][c - 'a'] = ++idx;//, printf("%d->%d\n", now, idx);
		// printf("%d->%d\n", now, ch[now][c - 'a']);
		now = ch[now][c - 'a'];
	}
	// printf("flag %d:%llu %llu\n", now, f1, f2);
	flag[now][0] |= f1, flag[now][1] |= f2;
}
int main()
{
	// freopen("./replace/replace4.in", "r", stdin);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> q;
	for(int i = 1; i <= n; ++i) cin >> s[i][0] >> s[i][1];
	for(int i = 1; i <= q; ++i) cin >> t[i][0] >> t[i][1];
	for(int i = 1; i <= n; i += 64)
	{
		int right = min(n, i + 63);
		clear();
		for(int j = i; j <= right; ++j) insert(s[j][0], 1ull << j - i, 0), insert(s[j][1], 0, 1ull << j - i);
		init();
		// puts("ff");
		for(int j = 1; j <= q; ++j)
		{
			int nowa = 0, nowb = 0, len = t[j][0].size();
			int same = 0, Same = 0;
			while(same < len && t[j][0][len - 1 - same] == t[j][1][len - 1 - same]) ++same;
			while(Same < len && t[j][0][Same] == t[j][1][Same]) ++Same;
			// printf("%d:%d,%d\n", j, same, Same);
			for(int p = 0; p < len; ++p)
			{
				nowa = ch[nowa][t[j][0][p] - 'a'];
				nowb = ch[nowb][t[j][1][p] - 'a'];
				if(p >= len - same - 1)
				{
					// printf("%d:%d\n", j, p);
					ull val = flag[nowa][0] & flag[nowb][1];
					for(int k; val; val ^= 1ull << k)
					{
						k = __builtin_ctzll(val);
						// printf("idx: %d %llu\n", k, val);
						if(p < Same + s[k + i][0].size()) ++ans[j];
					}
				}
			}
		}
	}
	for(int j = 1; j <= q; ++j) printf("%d\n", ans[j]);
	return 0;
}