#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
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
int n, a[N][3], c[N], cnt[3], ans;

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	int T = read();
	while(T--)
	{
		n = read();
		
		ans = cnt[0] = cnt[1] = cnt[2] = 0;
		for(int i = 1; i <= n; i++)
		{
			a[i][0] = read(), a[i][1] = read(), a[i][2] = read();
			int maxn = max({a[i][0], a[i][1], a[i][2]});
			if(maxn == a[i][0]) c[i] = 0;
			else if(maxn == a[i][1]) c[i] = 1;
			else c[i] = 2;
			cnt[c[i]]++, ans += maxn;
		}
		
		int id = 0;
		if(cnt[1] > cnt[id]) id = 1;
		if(cnt[2] > cnt[id]) id = 2;
		if(cnt[id] * 2 <= n)
		{
			printf("%d\n", ans);
			continue;
		}
		vector<int> s;
		for(int i = 1; i <= n; i++)
			if(c[i] == id)
			{
				int maxn = 0;
				if(id != 0) maxn = max(maxn, a[i][0]);
				if(id != 1) maxn = max(maxn, a[i][1]);
				if(id != 2) maxn = max(maxn, a[i][2]);
				s.push_back({a[i][id] - maxn});
			}
		sort(s.begin(), s.end());
		for(int i = 0; i < cnt[id] - n / 2; i++) ans -= s[i];
		printf("%d\n", ans);
	}
	return 0;
}

