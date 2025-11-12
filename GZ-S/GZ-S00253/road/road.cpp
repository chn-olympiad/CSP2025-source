//杜泽煊 GZ-S00253 贵阳市华麟学校
#include <bits/stdc++.h>
#define int long long
#define PII pair<int, int>
using namespace std;
const int MAXN = 1e6+5;
const int MAXT = 20;
const int MOD = 998244353;
int n, m, k;
vector<PII> G[MAXN];
vector<int> c(11);
vector<int> a(MAXN);
priority_queue<PII, vector<PII>, greater<PII> > q;
int d[MAXN];
int v[MAXN] = {0};
inline void prim() {
	memset(d, 1e9, sizeof(d));
	d[1] = 0;
	q.push((PII) {
		d[1],1
	});
	while(!q.empty()) {
		PII it = q.top();
		q.pop();
		int t = it.first;
		int now = it.second;
		if(v[now] == 1) {
			continue;
		}
		v[now] = 1;
		//cout<<G[now].size()<<"------------";
		for(size_t i = 1; i <= G[now].size() ; i ++) {
			int ndi = G[now][i].second;
			int ii = G[now][i].first;
			int kxuanz = a[i];
			if(!v[ii] && ndi + t <= d[now]) {
				if(ndi + t >= d[i] + kxuanz + c[i]) {
					d[i] += kxuanz;
					d[i] += c[i];
				}
				d[i] = ndi + t;
			}
			q.push((PII) {
				d[i], i
			});
			v[i] = 1;
		}
	}
}
signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	while(m --) {
		int u, v, w;
		cin >> u >> v >> w;
		G[u].push_back({v,w});
		G[v].push_back({u,w});
	}
	for(size_t i = 1; i <= k; i ++) {
		cin >> c[i];
		for(size_t j = 1; j <= n; j ++) {
			cin >> a[i];
		}
	}
	prim();
	int ans = 0;
	for(size_t i = 1; i <= n; i ++) {
		ans += d[i];
	}
	cout << ans;
	return 0;
}
//4 4 2 1 4 6 2 3 7 4 2 5 4 3 4 1 1 8 2 4 100 1 3 2 4
