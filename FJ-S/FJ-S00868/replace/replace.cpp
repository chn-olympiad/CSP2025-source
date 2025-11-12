#include <iostream> 

using namespace std;

namespace Fast_read
{
	template <typename T>
	inline void read(T &w) ;
	template <typename T>
	inline void print(T ans) ;
	inline void read(char *s, int &len) ;
};
using namespace Fast_read;

int n, Q, m = 0;
int be[200010][2], ed[200010][2];
int nxt[10000010];
int path1[10000010], cnt1 = 0, path2[10000010], cnt2 = 0;
int lenS = 0, lenT = 0;
char str[5000010], S[5000010], T[5000010], p[10000010];

int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out","w", stdout);
	read(n), read(Q), str[m = 0] = '!';
	for (register int u = 1; u <= n; ++ u)
	{
		be[u][0] = m + 1, read(str, m);
		ed[u][0] = m, str[ ++ m] = '#';
		be[u][1] = m + 1, read(str, m);
		ed[u][1] = m, str[ ++ m] = '@';
	}
	long long res = 0;
	while (Q -- )
	{
		read(S, lenS = 0), read(T, lenT = 0), res = 0;
		if (lenS != lenT)
		{
			puts("0");
			continue;
		}
		int beS = -1, edS = 0;
		for (register int i = 1; i <= lenS; ++ i)
		{
			if (S[i] != T[i])
			{
				if (beS == -1) beS = i;
				edS = i;
			}
		}
		if (beS == -1)
		{
			puts("0");
			continue;
		}
		for (register int u = 1; u <= n; ++ u)
		{
			cnt1 = cnt2 = 0;
			for (register int i = be[u][0]; i <= ed[u][0]; ++ i)
			{
				p[i - be[u][0] + 1] = str[i];
			}
			p[ed[u][0] - be[u][0] + 2] = '#';
			for (register int i = 1, o = ed[u][0] - be[u][0] + 2; i <= lenS; ++ i)
			{
				p[o + i] = S[i];
			}
			nxt[0] = -1;
			for (register int i = 1, j, I = ed[u][0] - be[u][0] + 2 + lenS; i <= I; ++ i)
			{
				j = nxt[i - 1];
				while (j != -1 && p[i] != p[j + 1]) j = nxt[j];
				nxt[i] = j + 1;
			}
			for (register int i = ed[u][0] - be[u][0] + 3, I = ed[u][0] - be[u][0] + 2 + lenS, o = ed[u][0] - be[u][0] + 2; i <= I; ++ i)
			{
				if (nxt[i] == ed[u][0] - be[u][0] + 1)
				{
					path1[ ++ cnt1] = i - o;
				}
			}
			for (register int i = be[u][1]; i <= ed[u][1]; ++ i)
			{
				p[i - be[u][1] + 1] = str[i];
			}
			p[ed[u][1] - be[u][1] + 2] = '#';
			for (register int i = 1, o = ed[u][1] - be[u][1] + 2; i <= lenS; ++ i)
			{
				p[o + i] = T[i];
			}
			nxt[0] = -1;
			for (register int i = 1, j, I = ed[u][1] - be[u][1] + 2 + lenS; i <= I; ++ i)
			{
				j = nxt[i - 1];
				while (j != -1 && p[i] != p[j + 1]) j = nxt[j];
				nxt[i] = j + 1;
			}
			for (register int i = ed[u][1] - be[u][1] + 3, I = ed[u][1] - be[u][1] + 2 + lenS, o = ed[u][1] - be[u][1] + 2; i <= I; ++ i)
			{
				if (nxt[i] == ed[u][1] - be[u][1] + 1)
				{
					path2[ ++ cnt2] = i - o;
				}
			}
			int r = 1;
			for (register int l = 1; l <= cnt1; ++ l)
			{
				while (r <= cnt2 && path2[r] < path1[l]) ++ r;
				if (r > cnt2) break;
				if (path1[l] - (ed[u][0] - be[u][0] + 1) + 1 <= beS && edS <= path1[l] && path1[l] == path2[r])
				{
					++ res;
				}
			}
		}
		print(res), puts("");
	}
	return 0;
}

namespace Fast_read
{
	int op, stk[35], top = 0; 
	char c;
	template <typename T>
	inline void read(T &w)
	{
		w = 0, op = 1;
		do {c = getchar();}while ((c < '0' || c > '9') && c != '-');
		if (c == '-') op = -1, c = getchar();
		do {w = (w << 3) + (w << 1) + (c ^ 48), c = getchar();}while (c >= '0' && c <= '9');
		w *= op;
	}
	template <typename T>
	inline void print(T ans)
	{
		top = 0;
		if (ans < 0) putchar('-'), ans = -ans;
		do {stk[ ++ top] = ans % 10, ans /= 10;}while (ans);
		while (top) putchar(stk[top -- ] ^ 48);
	}
	
	inline void read(char *s, int &len)
	{
		do {c = getchar();}while (c < 'a' || c > 'z');
		do {s[ ++ len] = c, c = getchar();}while (c >= 'a' && c <= 'z');
	}
};
