#include<bits/stdc++.h>
#define ll long long
#define inf INT_MAX
#define linf LLONG_MAX
using namespace std;
ll n, m, k, sz[10050], c[10], temp[10][10000], f[10050], ans;
struct edge{
	ll from, to, cost;
};
bool cmp(edge p, edge q){
	return p.cost < q.cost;
}
vector<edge> qwq, mst, bfmst;
bool flag;
ll find(ll q){
	return q == f[q] ? q : f[q] = find(f[q]);
}
int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 0; i < m; i++){
		ll u, v, w;
		cin >> u >> v >> w;
		u--;
		v--;
		sz[u]++;
		sz[v]++;
		qwq.push_back({u, v, w});
		qwq.push_back({v, u, w});
		mst.push_back({u, v, w});
		mst.push_back({v, u, w});
	}
	for(int i = 0; i < k; i++){
		cin >> c[i];
		if(c[i] != 0){
			flag = true;
		}
		for(int j = 0; j < n; j++){
			cin >> temp[i][j];
			sz[n + i]++;
			sz[j]++;
			mst.push_back({n + i, j, temp[i][j]});
			mst.push_back({j, n + i, temp[i][j]});
		}
	}
	if(flag){
		ans = linf;
		for(int bit = 0; bit < (1 << k); bit++){
			for(int i = 0; i < n + k; i++){
				f[i] = i;
			}
			bfmst.clear();
			ll res = 0;
			bfmst = qwq;
			for(int i = 0; i < k; i++){
				if((1 << i) & bit){
					for(int j = 0; j < n; j++){
						bfmst.push_back({n + i, k, temp[i][k]});
						bfmst.push_back({j, n + i, temp[i][j]});
					}
					res += c[i];
				}
			}
			ll len = bfmst.size();
			sort(bfmst.begin(), bfmst.end(), cmp);
			for(int i = 0; i < len; i++){
				ll x = bfmst[i].from, y = bfmst[i].to;
				if(find(x) != find(y)){
					res += bfmst[i].cost;
					f[find(x)] = find(y);
				}
			}
			ans = min(ans, res);
		}
		cout << ans << endl;
	}
	else{
		for(int i = 0; i < n + k; i++){
			f[i] = i;
		}
		ll len = mst.size();
		sort(mst.begin(), mst.end(), cmp);
		for(int i = 0; i < len; i++){
			ll x = mst[i].from, y = mst[i].to;
			if(find(x) != find(y)){
				ans += mst[i].cost;
				f[find(x)] = find(y);
			}
		}
		cout << ans << endl;
	}
	return (0 - 0);
}

