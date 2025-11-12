#include<bits/stdc++.h>
using namespace std;
const int N = 1e4+5, M = 1e6+5;
int n, m, k;
vector<pair<int,int> >a[N+10];//w,v
int fa[N], cnt, ans;
int fin(int x) {
	if (fa[x] != x) fa[x] = fin(fa[x]);
	return fa[x];
}
void un(int x, int y) {
	x = fin(x);
	y = fin(y);
	fa[x] = y;
}
bool ju (int x, int y) {
	return fin(x) == fin(y);
}
priority_queue<pair<pair<int,int>,int>, vector<pair<pair<int,int>,int> >, greater<pair<pair<int,int>,int> > > q;//w,v,u
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1,u,v,w; i <= m; i++) {
		cin >> u >> v >> w;
		a[u].push_back(make_pair(w,v));
		a[v].push_back(make_pair(w,u));
	}
	for (int i = 1; i <= n+k; i++) {
		fa[i] = i;
	}
	for (int i = 1,c,w; i <= k; i++) {
		cin >> c;
		for (int j = 1; j <= n; j++) {
			cin >> w;
			a[j].push_back(make_pair(w+c,n+i));
			a[n+i].push_back(make_pair(w+c,j));
		}
	}
	cnt++;
	if (k == 0) {
		for (int i = 0; i < a[1].size(); i++) {
			pair<int,int> x = a[1][i];
			q.push(make_pair(x,1));
		}
	}
	else {
		for (int i = 0; i < a[n+1].size(); i++) {
			pair<int,int> x = a[n+1][i];
			q.push(make_pair(x,n+1));
		}
	}
	while (cnt < n) {
		pair<pair<int,int>,int> x = q.top();
		q.pop();
		int w = x.first.first, v = x.first.second, u = x.second;
		if (ju(u,v)) continue;
		un(u,v);
		if (v <= n) cnt++;
		ans += w;
		for (int i = 0; i < a[v].size(); i++) {
			pair<int,int> xx = a[v][i];
			q.push(make_pair(xx,v));
		}
	}
	cout << ans;
	return 0;
}
