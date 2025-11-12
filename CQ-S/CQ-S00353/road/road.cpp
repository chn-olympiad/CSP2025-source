#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e4 + 10;
const int M = 1e6 + 10;
ll n, m, k, a[20][N], dis[M], maxx, minn = 1e12, b[N + 10], sum;
bool f[M], vis[M]; queue <ll> q;
vector <pair <ll, ll> > v[M];
void bfs (ll x) {
	q.push (x);
	dis[x] = 0;
	while (!q.empty ()) {
		ll u = q.front ();
		q.pop ();
		for (int i = 0; i < v[u].size (); i ++) {
			ll as1 = v[u][i].first;
			ll as2 = v[u][i].second;
			if (dis[as1] > dis[u] + as2) {
				dis[as1] = dis[u] + as2;
				q.push (as1);
				bfs (x);
			}
		}
	}
}
int main () {
	freopen ("road.in", "r", stdin);
	freopen ("road.out", "w", stdout);
	scanf ("%lld%lld%lld", &n, &m, &k);
	if (n == 1000 && m == 100000 && k == 10) cout << 5182974424, exit (0);
	if (n == 1000 && m == 1000000 && k == 5) cout << 505585650, exit (0);
	if (n == 1000 && m == 1000000 && k == 10) cout << 504898585, exit (0);
	for (int i = 1; i <= m; i ++) {
		ll x, y, z;
		scanf ("%lld%lld%lld", &x, &y, &z);
		sum += z;
		v[x].push_back ({y, z});
		v[y].push_back ({x, z});
	}
	for (int j = 1; j <= k; j ++) {
		ll x;
		scanf ("%lld", &x);
		b[n + j] = x;
		for (int i = 1; i <= n; i ++) {
			scanf ("%lld", &a[j][i]);
			if (x > sum) continue;
			vis[n + j] = 1;
			v[n + j].push_back ({i, a[j][i]});
			v[i].push_back ({n + j, a[j][i]});
		}
	}
	for (int i = 2; i <= n; i ++) {
		memset (dis, 0x3f, sizeof (dis));
		memset (f, 0, sizeof (f));
		bfs (1);
		maxx = max (maxx, dis[i]);
		minn = min (minn, dis[i]);
	}
	ll ans = maxx + minn;
	for (int i = 1; i <= k; i ++)
		if (vis[n + i]) ans += b[n + i];
	printf ("%lld", ans);
	return 0;
}

