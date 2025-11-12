#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 10010;
int n, m, k, lf;
bool b[N];
bool seg[N];
ll dist[N * 2], l[N * 2];
vector<pair<int, int>> e[N * 2];
ll ans = 0;
void Dijkstra(int s){
	memset(dist, 127, sizeof(dist));
	dist[s] = 0;
	while(true){
		int x = 0;
		for(int i = 1; i <= n + n; i++)
			if(dist[i] < dist[x] && !b[i])
				x = i;
		if(!x)
			break;
		b[x] = true;
		int cnt = 0;
		for(auto p : e[x]){
			int y = p.first;
			ll z = p.second;
			if(dist[y] > dist[x] + z){
				dist[y] = dist[x] + z;
				l[y] = z;
				++cnt;
			}
		}
		if(!cnt)
			break;
	}
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= m; i++){
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		e[x].push_back({y, z});
		e[y].push_back({x, z});
	}
	for(int i = 1; i <= k; i++){
		int c;
		scanf("%d", &c);
		e[i].push_back({i + n, c});
		for(int j = 1; j <= n; j++){
			int v;
			scanf("%d", &v);
			e[i + n].push_back({j, v});
		}
	}
	Dijkstra(1);
	for(int i = 1; i <= n; i++)
        ans += l[i];
	printf("%lld\n", ans);
}
