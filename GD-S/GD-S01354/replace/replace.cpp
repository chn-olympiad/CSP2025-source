#include <bits/stdc++.h>
typedef long long LL;
typedef std::string Str;
typedef std::pair<int, int> pii;
#define MP std::make_pair
#define fi first
#define se second
char buf[1 << 20], *p1 = 0, *p2 = 0; 
#define getchar() ((p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 20, stdin), (p1 == p2))) ? 0 : (*p1++))
int read()
{
	int s = 0; int f = 1, c = getchar();
	for (; !isdigit(c); c = getchar()) f ^= (c == '-');
	for (; isdigit(c); c = getchar()) s = s * 10 + (c ^ 48);
	return f ? s : -s;
}
void reads(Str &s)
{
	s.clear();
	char c = getchar();
	for (; !islower(c); c = getchar());
	for (; islower(c); c = getchar()) s += c;
}
template<typename T> void write(T x, char end = '\n')
{
	if (x < 0) putchar('-'), x = -x;
	static int d[100]; int cur = 0;
	do { d[++cur] = x % 10; } while (x /= 10);
	while (cur) putchar(48 ^ d[cur--]);
	putchar(end);
}
template<typename T> void Fmax(T &x, T y){ if (x < y) x = y; }
template<typename T> void Fmin(T &x, T y){ if (y < x) x = y; }
const int MAXN = 200005, MAXS = 5100005;
int n, Q, m, ans[MAXN];
Str s[MAXN][2], t[MAXN][2];
int N;
int ch[MAXS][26];
int col[MAXS], in[MAXS], out[MAXS], dcnt;
std::vector<int> rec[MAXN];
std::vector<int> q[MAXS];
bool input(Str &L, Str &mid, Str &R)
{
	L.clear(), mid.clear(), R.clear();
	static Str s1, s2;
	reads(s1), reads(s2);
	if (s1.size() != s2.size()) return false;
	int i = 0, j = (int)s1.size() - 1;
	while (i < s1.size() && s1[i] == s2[i]) i++;
	if (i == s1.size()) return false;
	while (j >= 0 && s1[j] == s2[j]) j--;
	for (int k = i - 1; k >= 0; k--) L += s1[k];
	for (int k = i; k <= j; k++) mid += s1[k];
	for (int k = i; k <= j; k++) mid += s2[k];
	for (int k = j + 1; k < s1.size(); k++) R += s1[k];
	return true;
}
void clear()
{
	for (int i = 0; i <= N; i++)
	{
		memset(ch[i], 0, sizeof ch[i]);
		in[i] = out[i] = 0;
		q[i].clear();
	}
	N = dcnt = 0;
}
int insert(Str &s)
{
	int x = 0;
	for (char c : s)
	{
		int o = c - 'a';
		if (!ch[x][o]) ch[x][o] = ++N;
		x = ch[x][o];
	}
	return x;
}
int find(Str &s)
{
	int x = 0;
	for (char c : s)
	{
		int o = c - 'a';
		if (!ch[x][o]) break;
		x = ch[x][o];
	}
	return x;
}
void input()
{
	n = read(), Q = read();
	Str mid;
	for (int i = 1; i <= n; i++)
		if (input(s[i][0], mid, s[i][1]))
		{
//			printf("S%d: %s %s %s\n", i, s[i][0].c_str(), mid.c_str(), s[i][1].c_str());
			int id = insert(mid);
			if (!col[id]) col[id] = ++m;
			rec[col[id]].push_back(i);
		}
	for (int i = 1; i <= Q; i++)
		if (input(t[i][0], mid, t[i][1]))
		{
//			printf("T%d: %s %s %s\n", i, t[i][0].c_str(), mid.c_str(), t[i][1].c_str());
			int x = 0;
			for (char c : mid)
			{
				if (!ch[x][c - 'a']) { x = -1; break; }
				x = ch[x][c - 'a'];
			}
			if (x != -1 && col[x]) rec[col[x]].push_back(-i);
		}
}
pii dfns[MAXN];
int dfnt[MAXN];
void dfs(int x)
{
	in[x] = ++dcnt;
//	fprintf(stderr, "!%d\n", x);
	for (int c = 0; c < 26; c++)
		if (ch[x][c]) dfs(ch[x][c]);
	out[x] = dcnt;
}
namespace BIT
{
	int c[MAXS], n;
	void init(int _n){ memset(c + 1, 0, (n = _n) << 2); }
	void modify(int x, int v){ for (; x <= n; x += x & -x) c[x] += v; }
	void modify(int l, int r, int v){ modify(l, v), modify(r + 1, -v); }
	int query(int x)
	{
		int res = 0;
		for (; x; x -= x & -x) res += c[x];
		return res;
	}
}
void dfs1(int x)
{
	for (int i : q[x]) if (i > 0) BIT::modify(dfns[i].fi, dfns[i].se, 1);
	for (int i : q[x]) if (i < 0) ans[-i] = BIT::query(dfnt[-i]);
	for (int c = 0; c < 26; c++) if (ch[x][c]) dfs1(ch[x][c]);
	for (int i : q[x]) if (i > 0) BIT::modify(dfns[i].fi, dfns[i].se, -1);
}
void calc(int C)
{
	bool viss = false, vist = false;
	for (int i : rec[C]) viss |= i > 0, vist |= i < 0;
	if (!viss || !vist) return ;
	static int tmp[MAXN];
	clear();
	for (int i : rec[C])
		if (i > 0) tmp[i] = insert(s[i][0]);
	dfs(0);
	for (int i : rec[C])
		if (i > 0) dfns[i] = MP(in[tmp[i]], out[tmp[i]]);
		else dfnt[-i] = in[find(t[-i][0])];
	BIT::init(dcnt);
	clear();
	for (int i : rec[C])
		if (i > 0) q[insert(s[i][1])].push_back(i);
	for (int i : rec[C])
		if (i < 0) q[find(t[-i][1])].push_back(i);
	dfs1(0);
}
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	input();
	for (int i = 1; i <= m; i++) calc(i);
	for (int i = 1; i <= Q; i++) write(ans[i]);
	return 0;
} 
