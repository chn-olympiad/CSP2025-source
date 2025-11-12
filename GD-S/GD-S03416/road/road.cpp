#include<bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define F first
#define S second
#define vc vector
#define vci vc<int>
#define psb push_back
using namespace std;
inline int read(){
	char c;
	int ans = 0, cnt = 1;
	while(1){
		c = getchar();
		if((c >= '0' && c <= '9') || c == '-') break;
	}
	if(c == '-') cnt = -1;
	else ans = (int)(c - '0');
	while(1){
		c = getchar();
		if(!(c >= '0' && c <= '9')) break;
		ans *= 10;
		ans += (int)(c - '0');
	}
	return ans * cnt;
}
struct Edge{
	int u, v, w;
};
int n, m, k, c[15];
int p[10005];
vc<Edge> hv[1025], g[15];
Edge e[1000005];
ll ans[2005], res;
bool cmp(Edge a, Edge b){
	return a.w < b.w;
}
int find(int u){
	if(p[u] == u) return u;
	return p[u] = find(p[u]);
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 1, a, b, c; i <= m; i++){
		a = read(), b = read(), c = read();
		e[i] = (Edge){a, b, c};
	}
	sort(e + 1, e + m + 1, cmp);
	for(int i = 1; i <= n; i++) p[i] = i;
	for(int i = 1; i <= m; i++){
		int u = find(e[i].u), v = find(e[i].v), w = e[i].w;
		if(u == v) continue;
		p[u] = v;
		ans[0] += w;
		hv[0].psb(e[i]);
	}
	res = ans[0];
	for(int i = 0; i < k; i++){
		cin >> c[i];
		for(int j = 1, a; j <= n; j++) a = read(), g[i].psb((Edge){n + i + 1, j, a});
		sort(g[i].begin(), g[i].end(), cmp);
	}
	for(int i = 1; i < (1 << k); i++){
		int cnt = 0;
		for(int j = 0; j < k; j++)
			if((i >> j) & 1) ans[i] += c[j], cnt++;
		for(int j = 1; j <= n + k; j++) p[j] = j;
		for(int j = 0; j < k; j++)
			if((i >> j) & 1){
				int stm = i - (1 << j);
				int id1 = 0, id2 = 0;
				while(id1 < hv[stm].size() && id2 < g[j].size()){
					if(hv[stm][id1].w < g[j][id2].w){
						int u = find(hv[stm][id1].u), v = find(hv[stm][id1].v), w = hv[stm][id1].w;
						id1++;
						if(u == v) continue;
						p[u] = v;
						ans[i] += w;
						hv[i].psb(hv[stm][id1 - 1]);
					}
					else{
						int u = find(g[j][id2].u), v = find(g[j][id2].v), w = g[j][id2].w;
						id2++;
						if(u == v) continue;
						p[u] = v;
						ans[i] += w;
						hv[i].psb(g[j][id2 - 1]);
					}
					if(hv[i].size() == n + cnt - 1) break;
				}
				while(id1 < hv[stm].size()){
					int u = find(hv[stm][id1].u), v = find(hv[stm][id1].v), w = hv[stm][id1].w;
					id1++;
					if(u == v) continue;
					p[u] = v;
					ans[i] += w;
					hv[i].psb(hv[stm][id1 - 1]);
					if(hv[i].size() == n + cnt - 1) break;
				}
				while(id2 < g[j].size()){
					int u = find(g[j][id2].u), v = find(g[j][id2].v), w = g[j][id2].w;
					id2++;
					if(u == v) continue;
					p[u] = v;
					ans[i] += w;
					hv[i].psb(g[j][id2 - 1]);
					if(hv[i].size() == n + cnt - 1) break;
				}
				break;
			}
		res = min(res, ans[i]);
	}
	cout << res;
	return 0;
}
