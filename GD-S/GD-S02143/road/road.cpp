#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6 + 20;
ll n, m, k;
ll a[20][N];
ll c[N], ans = 0, in[N], num = 0, cal[N];
ll fa[N], val[N];
bool vis[N];
struct node{
	ll val, u, v, flag;
	bool friend operator < (node a, node b) {if(a.val == b.val) return a.flag > b.flag; else return a.val > b.val;}
};
priority_queue<node> q;
ll find(ll x) {return fa[x] == x? x : fa[x] = find(fa[x]);}
void add(ll i) {
	for(int j = 1; j <= n; j++) {
//		if(in[i] == 1) {
//			q.push((node){a[i][j+k]+cal[i], i, j+k, -1});
//			q.push((node){a[i][j+k]+cal[i], j+k, i, -1});
//		}
//		else {
			q.push((node){a[i][j+k], i, j+k, 0});
			q.push((node){a[i][j+k], j+k, i, 0});
//		}
	}
}
void Prim() {
	while(!q.empty()) {
		node now = q.top();
		q.pop();
		if(find(now.u) == find(now.v)) continue;
		
		if(now.u > now.v) swap(now.u, now.v);
//		if(now.flag == -1 && in[now.u] > 1) continue;
		ll x = find(now.u), y = find(now.v);
		fa[y] = x;
//		val[x] += val[y];
//		if(now.flag == -1) ans += now.val-cal[now.u];
//		else 
		ans += now.val;
		if(now.u <= k) {
//			if(now.flag == -1) cal[now.u] += now.val-cal[now.u];
//			else 
			cal[now.u] += now.val;
			in[now.u] ++;
//			add(now.u);
			if(in[now.u] == 1) add(now.u);
//			if(in[now.u] == 2) add(now.u);
		}
//		if(val[x] >= n) break;
	}
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%lld%lld%lld", &n, &m, &k);
	for(int i = 1; i <= n+k; i++) {
		fa[i] = i;
		in[i] = 0;
		if(i > k) val[i] = 1;
	}
	for(int i = 1; i <= m; i++) {
		ll u, v, w;
		scanf("%lld%lld%lld", &u, &v, &w);
		q.push((node){w, u+k, v+k, 1});
		q.push((node){w, v+k, u+k, 1});
	}
	for(int i = 1; i <= k; i++) {
		scanf("%lld", &c[i]);
		for(int j = 1; j <= n; j++) {
			scanf("%lld", &a[i][j+k]);
			q.push((node){c[i]+a[i][j+k], i, j+k, 0});
			q.push((node){c[i]+a[i][j+k], j+k, i, 0});
		}
	}
	Prim();
	for(int i = 1; i <= k; i++) {
		if(in[i] == 1) ans -= cal[i];
	}
	printf("%lld", ans);
	return 0;
} 
/*
3 0 2
1 1 1 1
1 1 1 1
*/
