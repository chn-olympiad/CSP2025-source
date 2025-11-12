#include<bits/stdc++.h>
using namespace std;

int n, m, k, fa[10005], rk[10005];
struct node{
	long long u, v, w;
};
vector<node> orign, vil;
long long c[15], p[15][10005];

int find(int x){
	if(fa[x] != x) return fa[x] = find(fa[x]);
	else return x;
}

bool unin(int x, int y) {
	int fx = find(x), fy = find(y);
	if(fx == fy) return false;
	if(rk[fx] < rk[fy]) fa[fx] = fy;
	if(rk[fx] > rk[fy]) fa[fy] = fx;
	if(rk[fx] == rk[fy]) fa[fx] = fy, rk[fy]++; 
	return true;
}

bool cmp(node x, node y) {
	return x.w < y.w;
}

void solve() {
	long long now = n, ans = 0;
	for(int i = 0; i < orign.size(); i++) {
		if(unin(orign[i].u, orign[i].v)) now--, ans += orign[i].w;
		if(now == 0) break; 
	}
	cout << ans;
}

int main() {
	
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++)
		fa[i] = i, rk[i] = 1;
	for(int i = 1; i <= m; i++) {
		node in;
		cin >> in.u >> in.v >> in.w;
		orign.emplace_back(in); 
	}
	sort(a.begin(), a.end(), cmp);
	for(int i = 1; i <= k; i++) {
		cin >> c[i];
		for(int j = 1; j <= n; j++) {
			cin >> p[i][j]; 
		} 
	}
	if(k == 0) solve();
	
	return 0;
} 
