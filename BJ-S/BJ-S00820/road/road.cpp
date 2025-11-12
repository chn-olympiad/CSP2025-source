#include "bits/stdc++.h"
#define ll long long
#define P pair<int, int>
#define F first
#define S second
using namespace std;

ll n, m, k, p[1005][1005], bk[1005][1005], fa[10005], c[15], f[15][10005], cnt, ans;
struct X
{
	ll u, v, w;
	bool operator <(X z)
	{
		return w < z.w;
	}
}a[1000005];
ll find(ll x){return fa[x] = (fa[x] == x?x:find(fa[x]));}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1;i <= n;i++)
	{
		fa[i] = i;
	}
	if(k == 0)
	{
		for(int i = 1;i <= m;i++)
		{
			cin >> a[i].u >> a[i].v >> a[i].w;
		}
		sort(a + 1, a + n + 1);
		for(int i = 1;i <= m && cnt < n - 1;i++)
		{
			ll u = a[i].u, v = a[i].v, w = a[i].w;
			ll fu = find(u), fv = find(v);
			if(fu == fv)
			{
				continue;
			}
			ans += w;
			fa[fv] = fu, cnt++;
		}
	}
	cout << ans;
	return 0;
}
