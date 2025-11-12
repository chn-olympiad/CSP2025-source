# include<bits/stdc++.h>
# define N 10015
using namespace std;
int n, m, k;
long long ans, maxn;
int fa[N], size[N];
vector<pair<int, long long> > to[N];
priority_queue<pair<long long, pair<int, int> > > q, t;
inline int f(int x) {
	return (fa[x] == x ? fa[x] : f(fa[x]));
}
vector<pair<long long, pair<int, int> > > p;
long long val[N];
void dijkstar(int cur) {
	int siz = n;
	long long sum = 0;
	for(int i = 1; i <= k; i ++)
		if((cur & (1 << i - 1)))
			siz ++;
	for(int i = 1; i <= n + k; i ++)
		fa[i] = i, size[i] = 1;
	for(int i = 0; i < p.size(); i ++) {
		int u = p[i].second.first, v = p[i].second.second;
		long long w = p[i].first;
		if(u > n && ((cur & (1 << (u - n - 1))) == 0)) continue;
		int fu = f(u), fv = f(v);
		if(fu == fv) continue;
		if(size[fu] < size[fv])
			fa[fu] = fv, size[fv] += size[fu];
		else
			fa[fv] = fu, size[fu] += size[fv];
		sum += w, siz --;
		if(siz == 1)
			break;
	}
	for(int i = 1; i <= k; i ++)
		if(cur & (1 << (i - 1)))
			sum += val[i];
	ans = min(ans, sum);
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin.tie(0) -> sync_with_stdio(false);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i ++) {
		int u, v, w;
		cin >> u >> v >> w;
		q.push({- w, {u, v}});
	}
	for(int i = 1; i <= n; i ++)
		fa[i] = i, size[i] = 1;
	while(q.size()) {
		int u = q.top().second.first, v = q.top().second.second, w = - q.top().first;
		q.pop();
		int fu = f(u), fv = f(v);
		if(fu == fv) continue;
		if(size[fu] < size[fv])
			fa[fu] = fv, size[fv] += size[fu];
		else
			fa[fv] = fu, size[fu] += size[fv];
		t.push({- w, {u, v}});
		ans += w, maxn = max(maxn, ans);
	}
	for(int i = 1; i <= k; i ++) {
		cin >> val[i];
		for(int j = 1; j <= n; j ++) {
			int u = n + i, v = j;
			long long w;
			cin >> w;
			if(w < maxn)
				t.push({- w, {u, v}});
		}
	}
	while(t.size()) {
		int u = t.top().second.first, v = t.top().second.second;
		long long w = - t.top().first;
		t.pop();
		p.push_back({w, {u, v}});
	}
	for(int i = pow(2, k) - 1; i >= 0; i --)
		dijkstar(i);
	cout << ans << "\n";
	return 0;
}