#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, m, k;
vector<int> p(10100,0);

int find(int u) {
	return (p[u] == u ? u : p[u] = find(p[u]));
}

void dsu(int u, int v) {
	u = find(u), v = find(v);
	p[u] = v;
	return;
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
    	cin >> n >> m >> k;
	ll ans = 1e18;
	vector<pair<ll,pair<int,int>>> st;
	for (int i = 1; i <= m; i++) {
		int u, v, w; cin >> u >> v >> w;
		st.push_back({w,{u,v}});
	}
	bool fl = 1;
	vector<vector<int>> v(k+5,vector<int>(n+5,0));
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= n+1; j++) {
			cin >> v[i][j-1];
		}
		if (v[i][0] != 0) fl = 0;
	}
	if (fl) {
		for (int i = 1; i <= n+k+5; i++) p[i] = i;
		vector<pair<ll,pair<int,int>>> a;
		for (size_t i = 0; i < st.size(); i++) {
			ll c = st[i].first;
			int u = st[i].second.first, v = st[i].second.second;
			a.push_back({c,{u,v}});
			a.push_back({c,{v,u}});
		}
		ll temp = 0;
		for (int i = 0; i < k; i++) {
			temp += v[i+1][0];
			for (int x = 1; x <= n; x++) {
				a.push_back({v[i+1][x],{n+i+1,x}});
				a.push_back({v[i+1][x],{x,n+i+1}});
			}
		}
		sort(a.begin(),a.end());
		for (size_t i = 1; i < a.size(); i++) {
			ll c = a[i].first;
			int u = a[i].second.first, v = a[i].second.second;
			if (find(u) != find(v)) temp += c, dsu(u,v);
		}
		ans = min(ans,temp);
		a.clear();
		cout << ans << '\n';
		return 0;
	}
	for (int j = 0; j <= (1<<k)-1; j++) {
		for (int i = 1; i <= n+k+5; i++) p[i] = i;
		vector<pair<ll,pair<int,int>>> a;
		for (size_t i = 0; i < st.size(); i++) {
			ll c = st[i].first;
			int u = st[i].second.first, v = st[i].second.second;
			a.push_back({c,{u,v}});
			a.push_back({c,{v,u}});
		}
		ll temp = 0;
		for (int i = 0; i < k; i++) {
			if (j & (1 << i)) {
				temp += v[i+1][0];
				for (int x = 1; x <= n; x++) {
					a.push_back({v[i+1][x],{n+i+1,x}});
					a.push_back({v[i+1][x],{x,n+i+1}});
				}
			}
		}
		sort(a.begin(),a.end());
		for (size_t i = 1; i < a.size(); i++) {
			ll c = a[i].first;
			int u = a[i].second.first, v = a[i].second.second;
			if (find(u) != find(v)) temp += c, dsu(u,v);
		}
		ans = min(ans,temp);
		a.clear();
	}
	cout << ans << '\n';
	return 0;
}
