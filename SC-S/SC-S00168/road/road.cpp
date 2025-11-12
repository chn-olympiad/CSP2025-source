#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5, M = 1e6 + 5;
typedef long long ll;
int n, m, k;
int rt[N];
int fd(int x)
{
	if(x == rt[x]) return x;
	return rt[x] = fd(rt[x]);
}
int cnt, head[N];
struct edge
{
	int u, v, w, nxt;
	bool operator < (const edge& x) const
	{
		return w < x.w;
	}
} e[M];
signed main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios :: sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> k;
	int x, y, z;
	for(int i = 1; i <= m; i++)
	{
		cin >> x >> y >> z;
		e[++cnt] = (edge){x, y, z};
	}
	sort(e + 1, e + cnt + 1);
	int t = 0;
	ll sum = 0;
	for(int i = 1; i <= n; i++) rt[i] = i;
	for(int i = 1; i <= m; i++)
	{
		int u = e[i].u, v = e[i].v, w = e[i].w;
		if(fd(u) == fd(v)) continue;
		t++; sum = sum + w;
		if(t == n - 1) break;
		rt[fd(v)] = fd(u);
	}
	if(k == 0) cout << sum;
	else cout << '0';
	return 0;
}