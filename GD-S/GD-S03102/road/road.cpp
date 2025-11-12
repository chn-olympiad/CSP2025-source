#include<bits/stdc++.h>
#define pii pair<int, int>
#define fi first
#define se second
#define int long long
using namespace std;
constexpr int MAXN = 1e4 + 9;
int n, m, k, mxc = -1, ans, sumans = 0x3f3f3f3f3f3f3f3f, c[19], a[19][MAXN];
bool vis[MAXN];
vector<pii> G[MAXN], nG[MAXN];
priority_queue<pii, vector<pii>, greater<pii>> q;
void solve1() {
	q.push({0, 1});
	while(!q.empty()) {
		auto x = q.top();
		q.pop();
		int u = x.se, val = x.fi;
		if(vis[u]) continue;
		vis[u] = 1;
		ans += val;
		for(auto i : G[u]) {
			int v = i.fi, nval = i.se;
			if(vis[v]) continue;
			q.push({nval, v});
		}
	}
	cout << ans;
}
void solve2() {
	ans = 0;
	for(int i = 0; i < (1 << k); i++) {
		ans = 0;
		for(int i = 1; i <= n; i++) vis[i] = 0;
		for(int j = 0; j < k; j++) {
			if(1 & (i >> j)) {
				ans += c[j];
			}
		}
		q.push({0, 1});
		while(!q.empty()) {
			auto x = q.top();
			q.pop();
			int u = x.se, val = x.fi;
			if(vis[u]) continue;
			vis[u] = 1;
			ans += val;
			for(auto j : G[u]) {
				int v = j.fi, nval = j.se;
				if(vis[v] || (v > n && !(1 & (i >> (v - n - 1))))) continue;
				q.push({nval, v});
			}
		}
		sumans = min(sumans, ans);
	}
	cout << sumans;
}
signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%lld %lld %lld", &n, &m, &k);
	for(int i = 0; i < m; i++) {
		int u, v, w;
		scanf("%lld %lld %lld", &u, &v, &w);
		G[u].push_back({v, w});
		G[v].push_back({u, w});
	}
	for(int i = 0; i < k; i++) {
		scanf("%lld", &c[i]);
		mxc = max(mxc, c[i]);
		for(int j = 1; j <= n; j++) {
			scanf("%lld", &a[i][j]);
			G[n + i + 1].push_back({j, a[i][j]});
			G[j].push_back({n + i + 1, a[i][j]});
		}
	}
	if(mxc == 0) solve1();
	else solve2();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
