#include <bits/stdc++.h>
using namespace std;
#define int long long
#define el cout << '\n'
#define AC return
void main_();
signed main() {
	ios :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int t = 1;
//	cin >> t;
	while(t--) main_();
	return 0;
}
const int maxn = 1e4 * 2;

int n, m, k, tot = n, ans, in[maxn];
bool vis[maxn], out[maxn];
vector <pair <int, int> > vec[maxn];
#define pii pair <int, int> 
struct node {
	int w, to, from;
};
bool operator <(node a, node b) {
	return a.w > b.w;
}
priority_queue <node> pq;

bool cmp(pii a, pii b) {
	return a.second < b.second;
}

void main_() {
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		vec[u].push_back({v, w});
		vec[v].push_back({u, w});
	}
	for(int i = 1; i <= k; i++) {
		int c;
		cin >> c;
		int u = i + n;
		for(int v = 1; v <= n; v++) {
			int w;
			cin >> w;
			vec[v].push_back({u, w + c});
			vec[u].push_back({v, w});
		}
	}
	for(int i = 1; i <= n + k; i++) sort(vec[i].begin(), vec[i].end(), cmp);
	node a;
	a.from = 0, a.to = 1, a.w = 0;
	pq.push(a);
	while(!pq.empty()) {
		int x = pq.top().to, w = pq.top().w, from = pq.top().from; pq.pop(); 
		if(vis[x] == 1) continue;
		out[from] = 1;
		vis[x] = 1;
		ans += w;
//		cout << w << ' ' << x; el;
		if(x <= n) tot++;
		else in[x] = w; 
 		if(tot == n) break;
 		for(pii tmp : vec[x]) {
 			int ww = tmp.second, to = tmp.first;
 			if(vis[to]) continue;
 			node a;
 			a.w = ww, a.to = to, a.from = x;
 			pq.push(a);
		}
	}
	for(int i = n + 1; i <= n + k; i++) if(out[i] == 0) {
		ans -= in[i];
//		cout << i << ' ';
	}
	cout << ans; el;
}
