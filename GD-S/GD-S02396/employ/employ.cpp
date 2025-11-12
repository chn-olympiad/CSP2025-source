#include <bits/stdc++.h>
using namespace std;

int n, m, ans;
int a[20], c[20], s[20], vis[20];

int rd()
{
	char c = getchar();
	while(!isdigit(c)) c = getchar();
	return c ^ 48;
}

int rd2()
{
	char c = getchar(); int s = 0;
	while(!isdigit(c)) c = getchar();
	do s = (s << 1) + (s << 3) + (c ^ 48), c = getchar(); while(isdigit(c));
	return s;
}

void wr(int x)
{
	if(x > 9) wr(x / 10);
	putchar(x % 10 | 48);
}

void dfs(int x)
{
	if(x > n)
	{
		int k = 0, cnt = 0;
		for(int i = 1; i <= n; ++i)
		{
			if(!s[i])
			{
				++cnt;
				continue;
			}
			if(cnt < c[a[i]]) ++k;
			else ++cnt;
		}
		if(k >= m) ++ans;
		return;
	}
	for(int i = 1; i <= n; ++i)
	{
		if(vis[i]) continue;
		a[x] = i;
		vis[i] = 1;
		dfs(x+1);
		vis[i] = 0;
	}
}

int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	n = rd2(), m = rd2();
	for(int i = 1; i <= n; ++i)
	{
		s[i] = rd();
		if(n == m && !s[i]) return wr(0), 0;
	}
	for(int i = 1; i <= n; ++i)
	{
		c[i] = rd2();
		if(n == m && !c[i]) return wr(0), 0;
	}
	if(n == m)
	{
		int mul = 1;
		for(int i = 1; i <= n; ++i) mul = 1ll * mul * i % 998244353;
		return wr(mul), 0;
	}
	dfs(1);
	wr(ans);
	return 0;
}
