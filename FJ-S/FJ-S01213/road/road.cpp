#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7 + 5;
ll n, m, k, cnt, ans;
struct edge{
	ll u, v, w;
} e[N];
ll p[N];
bool cmp(edge x, edge y){
	return x.w < y.w;
}
int find(ll x){
	if (x == p[x]) return x;
	else return p[x] = find(p[x]);
}
void kruskal(){
	sort(e + 1, e + m + n * k + 1, cmp);
	for (ll i = 1; i <= m + n * k + 1; i++){
		ll u = find(e[i].u);
		ll v = find(e[i].v);
		if (u == v) continue;
		ans += e[i].w;
		p[v] = u;
		cnt++;
		if (cnt > n) break;
	}
}
int main (){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (ll i = 1; i <= m; i++){
		cin >> e[i].u >> e[i].v >> e[i].w;
	}
	for (ll i = 1; i <= k; i++){
		for (ll j = 0; j <= n; j++){
			ll aij;
			cin >> aij;
		}
	}
	for (ll i = 1; i <= n; i++) p[i] = i;
	kruskal();
	cout << ans;
	return 0;
}

