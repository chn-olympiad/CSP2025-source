#include<bits/stdc++.h>
using namespace std;
#define LL long long

const int N = 1e4 + 20, M = 1e6 + 10;
namespace IO
{
	char buf[1 << 21], *p1 = buf, *p2 = buf;
	inline char gc()
	{
		if(p1 == p2) p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin);
		return p1 == p2 ? EOF : *p1++;
	}
	template<typename T = int>
	inline T read()
	{
		int f = 1;
		T w = 0;
		char ch = gc();
		while(ch < '0' || '9' < ch)
		{
			if(ch == '-') f = -1;
			ch = gc();
		}
		while('0' <= ch && ch <= '9')
		{
			w = (w << 1) + (w << 3) + (ch ^ 48);
			ch = gc();
		}
		return f * w;
	}
	char obuf[1 << 21], *p3 = obuf;
	inline void flush()
	{
		fwrite(obuf, p3 - obuf, 1, stdout);
	}
	inline void pc(char c)
	{
		p3 - obuf < 1 << 21 ? (*p3++ = c) : (flush(), p3 = obuf, *p3++ = c);
	}
	template<typename T>
	inline void write(T x)
	{
		if(x < 0) pc('-'), x = -x;
		if(!x) pc('0');
		static char c[50];
		static int tt;
		while(x) c[++tt] = x % 10 ^ 48, x /= 10;
		while(tt) pc(c[tt--]);
	}
}
using namespace IO;
int n, m, k, c[20];
struct Edge
{
	int a, b, w;
	bool operator<(const Edge &t) const
	{
		return w < t.w;
	}
}edge[M];
LL ans = 1e18;

int fa[N];
int getfather(int x)
{
	return x == fa[x] ? x : fa[x] = getfather(fa[x]);
}

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	n = read(), m = read(), k = read();
	for(int i = 1; i <= m; i++)
		edge[i].a = read(), edge[i].b = read(), edge[i].w = read();
	sort(edge + 1, edge + m + 1);
	for(int i = 1; i <= n; i++) fa[i] = i;
	for(int i = 1, j = 1; i <= m; i++)
	{
		int a = getfather(edge[i].a), b = getfather(edge[i].b);
		if(a != b) fa[a] = b, edge[j++] = edge[i];
	}
	m = n - 1;
	
	for(int i = 1; i <= k; i++)
	{
		c[i] = read();
		for(int j = 1; j <= n; j++)
			edge[++m] = {i + n, j, read()};
	}
	sort(edge + 1, edge + m + 1);
	for(int s = 0; s < 1 << k + 1; s += 2)
	{
		LL res = 0;
		for(int i = 1; i <= k; i++)
			if(s >> i & 1) res += c[i];
		for(int i = 1; i <= n + k; i++) fa[i] = i;
		for(int i = 1; i <= m; i++)
			if(edge[i].a <= n || (s >> edge[i].a - n & 1))
			{
				int a = getfather(edge[i].a), b = getfather(edge[i].b);
				if(a != b) fa[a] = b, res += edge[i].w;
			}
		ans = min(ans, res);
	}
	cout << ans << endl;
	return 0;
}

