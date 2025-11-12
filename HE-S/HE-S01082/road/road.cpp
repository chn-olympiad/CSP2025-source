#include<bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int N = 4e6 + 66;
ll n, m, k, cnt[N], ans, c[N], tot, fa[N], cntt;
struct oll{
	ll x, y, v;
	friend bool operator < (oll p, oll k){return p.v < k.v;}
}b[N * 2];
ll find(ll x){return x == fa[x] ? fa[x] : fa[x] = find(fa[x]);}
void merge(ll x, ll y, ll v)
{
	ll fx = find(x), fy = find(y);
	if(fx == fy) return ;
	if(x > n) cnt[x] ++;if(y > n) cnt[y] ++;
	fa[fy] = fx;
	cntt -= (fy <= n);
	ans += v;
}
void kruskal()
{
	sort(b + 1, b + 1 + tot);
	for(int i = 1;i <= tot;i ++) 
	{
		if(cntt == 1) break;
		merge(b[i].x, b[i].y, b[i].v);
	}
}
int main()
{
	ios::sync_with_stdio(false);cin.tie(0), cout.tie(0);
	freopen("road.in", "r", stdin);freopen("road.out", "w", stdout);
	cin >> n >> m >> k;cntt = n;
	for(int i = 1;i <= n + k;i ++) fa[i] = i;
	for(int i = 1;i <= m; i ++)
	{
		ll x, y, v;cin >> x >> y >> v;
		b[++ tot] = {x, y, v};
	}
	for(int i = 1;i <= k;i ++)
	{
		cin >> c[i];
		for(int j = 1;j <= n;j ++)
		{
			ll w;cin >> w;
			b[++ tot] = {j, n + i, c[i] + w};
		}
	}
	kruskal();
	for(int i = n + 1;i <= n + k;i ++) if(cnt[i] > 1) ans -= (cnt[i] - 1) * c[i - n];
	cout << ans << '\n';
	return 0;
}



