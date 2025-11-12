#include <bits/stdc++.h>
#define int long long
#define r(x) for (int i = 1; i <= x; i++)
#define rep(i, a, b) for (int i = a; i <= b; i++)
using namespace std;

const int N = 2e4 + 50, M = 2e6 + 50;
int n, m, k, fa[N], c[N], cnt, flag[N];
struct node{
	int u, v, w, tg;
} a[M], p[M];

int find(int x)
{
	if (x == fa[x]) return x;
	return fa[x] = find(fa[x]);
}
void merge(int u, int v)
{
	int r1 = find(u), r2 = find(v);
	return fa[r1] = r2, void();
}

signed main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m >> k;
	r(N - 10) fa[i] = i;
	r(m) cin >> a[i].u >> a[i].v >> a[i].w;
	sort(a + 1, a + m + 1, [](node x, node y){
		return x.w < y.w;
	});
	r(k)
	{
		cin >> c[i];
		rep(j, 1, n)
		{
			int x; cin >> x;
			p[++cnt] = {j, n + i, x, i};
		}
	}
	int ans = 0;
	r(m) if (find(a[i].u) != find(a[i].v))
	{
		merge(a[i].u, a[i].v), ans += a[i].w;
		p[++cnt] = {a[i].u, a[i].v, a[i].w, 0};
	}
	sort(p + 1, p + cnt + 1, [](node x, node y){
		return x.w < y.w;
	});
	rep(i, 1, (1 << k) - 1)
	{
		memset(flag, 0, sizeof flag);
		int now = 0, num = n; flag[0] = 1;
		rep(j, 1, k)
		{
			if (!((i >> (j - 1)) & 1))
				continue;
			flag[j] = 1, now += c[j];
			num++;
		}
		rep(j, 1, n + k) fa[j] = j;
		rep(j, 1, cnt)
		{
			if (flag[p[j].tg] == 0) continue;
			if (find(p[j].u) != find(p[j].v))
				merge(p[j].u, p[j].v), now += p[j].w, num--;
		}
		if (num == 1) ans = min(ans, now);
	}
	cout << ans << "\n";
	return 0;
}
