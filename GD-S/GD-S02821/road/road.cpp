#include <bits/stdc++.h>
using namespace std;
struct node{
	long long fr, to, w;
}ed[1000010];
long long n, m, k, fa[10020], c[20], a[20][10010], ans;
vector<pair<long long, long long> > v[10010];
bool cmp(node x, node y){return x.w < y.w;}
long long find(long long now){return fa[now] == now ? now : fa[now] = find(fa[now]);}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i ++)cin >> ed[i].fr >> ed[i].to >> ed[i].w;
	sort(ed + 1, ed + m + 1, cmp);
	for (int i = 1; i <= n; i ++)fa[i] = i;
	for (int i = 1; i <= m; i ++){
		if (find(ed[i].fr) != find(ed[i].to))
			fa[find(ed[i].fr)] = find(ed[i].to), v[ed[i].fr].push_back({ed[i].to, ed[i].w}),
			v[ed[i].to].push_back({ed[i].fr, ed[i].w}), ans += ed[i].w;
	}
	for (int i = 1; i <= k && cin >> c[i]; i ++)
		for (int j = 1; j <= n; j ++)cin >> a[i][j];
	for (long long i = 0, now = 0, cnt = 0; i < (1 << k); ans = min(ans, now), now = cnt = 0, i ++){
		for (int j = 1; j <= n + k; fa[j] = j, j ++)
			for (auto u : v[j])ed[++ cnt] = {j, u.first, u.second};
		for (int j = 1; j <= k; j ++)
			if ((1 << j - 1) & i){
				for (int l = 1; l <= n; l ++)ed[++ cnt] = {j + n, l, a[j][l]};
				now += c[j];
				if (now >= ans)break;
			}
		if (now >= ans)continue;
		sort(ed + 1, ed + cnt + 1, cmp);
		for (int j = 1; j <= cnt; j ++){
			if (find(ed[j].fr) != find(ed[j].to))
				fa[find(ed[j].fr)] = find(ed[j].to), now += ed[j].w;
			if (now >= ans)break;
		}
	}
	cout << ans;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
