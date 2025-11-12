#include<bits/stdc++.h>
using namespace std;
int n, m, k, c[16], a[16][10005];
struct edge{
	int u, v, w;
} e[1000005];
bool del[1000005];
int fa[11451];
long long ans = 9e18;
set<pair<int, int> > st[16];
set<pair<int, int> >::iterator it[16];
int find(int x){
	return (fa[x] == x)? x : (fa[x] = find(fa[x]));
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= m; i++) scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
	for(int j = 1; j <= k; j++){
		scanf("%d", &c[j]);
		for(int i = 1; i <= n; i++) scanf("%d", &a[j][i]), st[j].insert({a[j][i], i});
		for(int i = 1; i <= m; i++) if(0ll + a[j][e[i].u] + a[j][e[i].v] + c[j] <= e[i].w) del[i] = 1;
	}
	for(int i = 1; i <= m; i++) if(del[i]) swap(e[i], e[m--]);
	sort(e + 1, e + m + 1, [](edge x, edge y){
		return x.w < y.w;
	});
	for(int s = 0; s < (1 << k); s++){
		int pos = 1, cnt = 0; long long sum = 0;
		for(int i = 1; i <= k; i++) it[i] = st[i].begin();
		int tn = __builtin_popcount(s) + n;
		for(int i = 1; i <= n + k; i++) fa[i] = i;
		for(int i = 1; i <= k; i++) if(s & (1 << (i - 1))) sum += c[i];
		while(cnt < tn - 1){
			int now = 1; while(now <= k && (it[now] == st[now].end() || !(s & (1 << (now - 1))))) now++;
			for(int i = now + 1; i <= k; i++) if(it[i] != st[i].end() && (s & (1 << (i - 1)))) if(it[i]->first < it[now]->first) now = i;
			if(now > k || !(s & (1 << (now - 1))) || it[now] == st[now].end() || it[now]->first > e[pos].w){
				if(find(e[pos].u) == find(e[pos].v)){
					pos++; continue;
				}
				sum += e[pos].w; fa[find(e[pos].u)] = find(e[pos].v); cnt++; pos++;
			}else{
				int v = (it[now]->second), w = (it[now]->first);
				if(find(n + now) == find(v)){
					++it[now]; continue;
				}
				sum += w; fa[find(n + now)] = find(v); cnt++; ++it[now];
			}
			if(sum >= ans) goto end;
		}
		ans = min(sum, ans);
		end:;
	}
	printf("%lld", ans);
	return 0;
}

