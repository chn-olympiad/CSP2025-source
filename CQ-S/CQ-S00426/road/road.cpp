#include<bits/stdc++.h>
using namespace std;
namespace IO {
	constexpr int bufsize = 230005;
	char buf[bufsize], *f1, *f2;
	char gtchar() {return f1 == f2 && (f1 = buf + fread(f2 = buf, 1, bufsize, stdin)) == buf? EOF: *f2++;}
	template<typename t> void read(t &ret)
	{
		int f = ret = 0;
		char ch = gtchar();
		while(!isdigit(ch)) f = ch == '-', ch = gtchar();
		while(isdigit(ch)) ret = ret * 10 + (ch ^ 48), ch = gtchar();
		if(f) ret = -ret;
	}
	template<typename t, typename ...T> void read(t &a, T &...b) {read(a), read(b...);}
}using IO::read;
typedef long long ll;
constexpr int maxn = 10005, maxk = 11, maxm = 1000005;
int n, m, k, a[maxk][maxn], f[maxn + maxk];
ll ans = 9e18;
struct edge {int u, v, w;} s[maxm], tmp[maxn * maxk];
int find(int x)
{
	while(x != f[x]) x = f[x] = f[f[x]];
	return x;
}
auto cmp = [](edge a, edge b) {return a.w < b.w;};
int main()
{
	// freopen("./road/road3.in", "r", stdin);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	read(n, m, k);
	for(int i = 1; i <= m; ++i) read(s[i].u, s[i].v, s[i].w);
	sort(s + 1, s + 1 + m, cmp);
	for(int i = 1; i <= k; ++i) for(int j = 0; j <= n; ++j) read(a[i][j]);
	int lim = 1 << k;
	for(int i = 0; i < lim; ++i)
	{
		ll tot = 0;
		int cnt = 0;
		for(int j = 1; j <= n + k; ++j) f[j] = j;
		for(int j = 1; j <= k; ++j)
			if(i >> j - 1 & 1)
			{
				tot += a[j][0];
				for(int p = 1; p <= n; ++p)
					tmp[++cnt] = {j + n, p, a[j][p]};
			}
		sort(tmp + 1, tmp + 1 + cnt, cmp);
		int ita = 1, itb = 1;
		while(ita <= m || itb <= cnt)
		{
			auto ret = itb > cnt || ita <= m && s[ita].w < tmp[itb].w? s[ita++]: tmp[itb++];
			if(find(ret.u) == find(ret.v)) continue;
			f[find(ret.u)] = find(ret.v);
			tot += ret.w;
		}
		bool flag = 0;
		int rt = find(1);
		for(int j = 1; j <= n; ++j)
			if(find(j) != rt)
			{
				flag = 1;
				break;
			}
		if(!flag) ans = min(ans, tot);
	}
	printf("%lld\n", ans);
	return 0;
}