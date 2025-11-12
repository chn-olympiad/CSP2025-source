//t2 road
#include<iostream>
#include<algorithm>
#include<queue>
#include<bitset>
#define rf(a, b, c) for(int b = (a); b <= (c); b++)
using namespace std;
int n, m, k, c[100], x, y, z, w;
bitset<1200> vis;
struct edge{
	int u, v, w;
	edge(int c, int a, int b){u = c, v = a, w = b;}
	bool operator < (const edge x) const{
		return w < x.w;
	}
};vector<edge> g[1100], ng[100];
int mgt(int s){
	int ans = 0;
	priority_queue<edge> q;
	for(edge v : g[s]) q.push(v);
	while(q.size()){
		edge p = q.top(); q.pop();
		vis.set(p.v);
		ans += p.w;
		for(edge r : g[p.v]) if(!vis[r.v]) q.push(r);
	}
	return ans;
}
bool check1(){
	rf(1, i, n) if(c[i]) return false;
	return true;
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	rf(1, i, m){
		cin >> x >> y >> z;
		g[x].emplace_back(x, y, z);
	}
	rf(1, i, n){
		cin >> c[i];
		rf(1, j, n){
			cin >> w;
			ng[n + i - 1].emplace_back(i, j, w);
		}
	}
	if(k == 0) cout << mgt(1);
	else if(check1()){
		rf(n + 1, i, n + k - 1) g[i] = ng[i];
		cout << mgt(1);
	}
	return 0;
}
