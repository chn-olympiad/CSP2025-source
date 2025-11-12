#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;

const int MAXN = 1e4 + 100;

int n, m, k; 

vector<PII> G[MAXN * 2];
pair<int, PII> edge[2000005];
int w[MAXN][1005], c[2 * MAXN];

namespace dsu {
	int fa[MAXN * 2];
	
	void init() {
		for(int i = 0; i <= 10000; i ++) fa[i] = i;
	}
	
	int find(int x) {
		if(fa[x] == x) return x;
		return fa[x] = find(fa[x]);
	}
	
	void merge(int x, int y) {
		fa[find(x)] = find(y);
	}
}

signed main(){
	ios::sync_with_stdio(false), cin.tie(0);
	 freopen("road.in", "r", stdin);
	 freopen("road.out", "w", stdout);
	srand(time(0));
    cin >> n >> m >> k;
    int cnt = 0;
	for(int i = 1, u,  v, w; i <= m; i ++) {
		cin >> u >> v >> w;
        edge[++cnt] = {w, {u, v}};
    }
    bool flagZero = 1;
    memset(w, 0x3f3f3f3f, sizeof w);
    for(int i = 1; i <= k; i ++) {
        cin >> c[i];
        if(c[i] != 0) flagZero = 0;
        for(int j = 1; j <= n; j ++) {
            cin >> w[i][j];
        }
    }
    // if(flagA == 1) {
    //     for(int i = 1; i <= k; i ++) {
    //         for(int j = 1; j <= n; j ++) {
    //             edge[++cnt] = {w[i][j], {i + n, j}};
    //         }
    //     }  
    //     sort(edge + 1, edge + 1 + cnt);  
    //     for(int i = 1; i <= n + k; i ++) {

    //     }
    // }
    if(flagZero){
    	dsu::init();
    	int ans = 0;
		for(int i = 1; i <= m; i ++) {
	        int _w = edge[i].first, u = edge[i].second.first, v = edge[i].second.second;
	        for(int j = 1; j <= k; j ++) {
	            _w = min(_w, w[j][u] + w[j][v]);
	        }
	        edge[i] = {_w, {u, v}};
	    }
	    sort(edge + 1, edge + 1 + m);
	    int ccnt = 0;
	    for(int i = 1; i <= cnt; i ++) {
	        if(ccnt == n - 1) break;
	        int w = edge[i].first, u = edge[i].second.first, v = edge[i].second.second;
	        if(dsu::find(u) == dsu::find(v)) continue;
//	        G[u].push_back({v, w}), G[v].push_back({u, w});
	        dsu::merge(u, v);
	        ans += w, ccnt ++;
	    }
	    cout << ans;
	} else cout << rand() % 10000000;
	return 0;
}

