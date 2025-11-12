#include <queue>
#include <bitset>
#include <cstdio>
#include <cstring>
#include <unordered_set>
const int MAXN = 5e6 + 7;
struct AC
{
	struct ACNode { int ch[26], fail, nxtkey, dep; } tr[MAXN]; int tot;
	std::bitset<MAXN> iskey;
	inline int insert(char *s)
	{
		int u = 0, len = strlen(s + 1);
		for (int i = 1; i <= len; ++i)
			!tr[u].ch[s[i] - 'a'] && (tr[u].ch[s[i] - 'a'] = ++tot), u = tr[u].ch[s[i] - 'a'];
		return iskey.set(u), u;
	}
	inline void getfail()
	{
		std::queue<int> q;
		for (int i = 0; i < 26; ++i)
			tr[0].ch[i] && (q.push(tr[0].ch[i]), tr[tr[0].ch[i]].dep = 1, true);
		while (q.size())
		{
			int u = q.front(); q.pop();
			for (int i = 0; i < 26; ++i)
				if (tr[u].ch[i])
					tr[tr[u].ch[i]].fail = tr[tr[u].fail].ch[i], tr[tr[u].ch[i]].dep = tr[u].dep + 1, q.push(tr[u].ch[i]);
				else
					tr[u].ch[i] = tr[tr[u].fail].ch[i];
		}
		for (int i = 1; i <= tot; ++i)
			tr[i].nxtkey = -1;
	}
	int getnxtkey(int u)
	{
		if (!u)
			return 0;
		if (~tr[u].nxtkey)
			return tr[u].nxtkey;
		tr[u].nxtkey = getnxtkey(tr[u].fail);
		return iskey.test(u) ? u : tr[u].nxtkey;
	}
	inline void build()
	{
		getfail();
		for (int i = 1; i <= tot; ++i)
			getnxtkey(i);
	}
} T[2];
int n, m, len[2];
unsigned long long hsh[2][2][MAXN];
char s[2][MAXN];
std::unordered_set<long long> st;
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
		scanf("%s%s", s[0] + 1, s[1] + 1), st.insert((long long)(T[0].insert(s[0])) * MAXN + T[1].insert(s[1]));
	T[0].build(), T[1].build();
//	for (int i = 1; i <= T[0].tot; ++i)
//		printf("%d %d %d %d\n", T[0].tr[i].fail, T[0].tr[i].nxtkey, T[0].tr[i].dep, T[0].tr[T[0].tr[i].fail].dep);
	for (int i = 1, u[2], v[2], ans; i <= m; ++i)
	{
		scanf("%s%s", s[0] + 1, s[1] + 1), len[0] = strlen(s[0] + 1), len[1] = strlen(s[1] + 1), u[0] = u[1] = ans = 0;
		if (len[0] != len[1] && (putchar('0'), putchar('\n'), true))
			continue;
		for (int j = 1; j <= len[0]; ++j)
			hsh[0][0][j] = hsh[0][0][j - 1] * 27 + (s[0][j] - 'a' + 1);
		hsh[0][0][len[0] + 1] = 0;
		for (int j = len[0]; j; --j)
			hsh[0][1][j] = hsh[0][1][j + 1] * 27 + (s[0][j] - 'a' + 1);
		for (int j = 1; j <= len[0]; ++j)
			hsh[1][0][j] = hsh[1][0][j - 1] * 27 + (s[1][j] - 'a' + 1);
		hsh[1][0][len[0] + 1] = 0;
		for (int j = len[0]; j; --j)
			hsh[1][1][j] = hsh[1][1][j + 1] * 27 + (s[1][j] - 'a' + 1);
		for (int j = 1; j <= len[0]; ++j)
		{
			if (!(u[0] = T[0].tr[u[0]].ch[s[0][j] - 'a']) || !(u[1] = T[1].tr[u[1]].ch[s[1][j] - 'a']))
				break;
//			printf("%llu %llu\n", hsh[0][1][j + 1], hsh[1][1][j + 1]);
			if (hsh[0][1][j + 1] != hsh[1][1][j + 1])
				continue;
//			printf("incondition1: %d\n", j);
			for (v[0] = T[0].iskey.test(u[0]) ? u[0] : T[0].tr[u[0]].nxtkey, v[1] = T[1].iskey.test(u[1]) ? u[1] : T[1].tr[u[1]].nxtkey; v[0] && v[1]; v[0] = T[0].tr[v[0]].nxtkey)
			{
				while (v[1] && T[1].tr[v[1]].dep < T[0].tr[v[0]].dep)
					v[1] = T[1].tr[v[1]].nxtkey;
//				if (T[0].tr[v[0]].dep == T[1].tr[v[1]].dep)
//					printf("2: %d %d %d\n", v[0], v[1], j);
//				if (hsh[0][0][j - T[0].tr[v[0]].dep] == hsh[1][0][j - T[0].tr[v[0]].dep])
//					printf("3: %d %d %d\n", v[0], v[1], j);
//				if (st.count((long long)(v[0]) * MAXN + v[1]))
//					printf("4: %d %d %d\n", v[0], v[1], j);
				if (T[0].tr[v[0]].dep == T[1].tr[v[1]].dep && hsh[0][0][j - T[0].tr[v[0]].dep] == hsh[1][0][j - T[0].tr[v[0]].dep] && st.count((long long)(v[0]) * MAXN + v[1]))
					++ans/*, printf("%d %d %d\n", v[0], v[1], j)*/;
			}
		}
		printf("%d\n", ans);
	}
	fclose(stdin), fclose(stdout);
	return 0;
}