#include<bits/stdc++.h>
using namespace std;

const int N = 1e4 + 10, M = 1e6 + 10;
typedef pair<int, int> pii;

int n, m, k, e[M], ne[M], h[N], w[M], idx;
bool st[N];
priority_queue<pii, vector<pii>, greater<pii>> q;

int solve(){
	int res = 0, vispt = 0;
	q.push({0, 1});
	while(vispt < n){
		int worth = q.top().first, pt = q.top().second;
		q.pop();
		if(st[pt]) continue;
		st[pt] = true;
		vispt++;
		res += worth;
		for(int i = h[pt]; i != -1; i = ne[i]) q.push({w[i], e[i]});
	}
	return res;
}

void add(int a, int b, int c){
	e[idx] = b;
	w[idx] = c;
	ne[idx] = h[a];
	h[a] = idx++;
}

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	cin >> n >> m >> k;
	memset(h, -1, sizeof h);
	while(m--){
		int u, v, wt;
		cin >> u >> v >> wt;
		add(u, v, wt);
		add(v, u, wt);
	}
	if(k) cout << 0;
	else cout << solve();
	
	return 0;
}
