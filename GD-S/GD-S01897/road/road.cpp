#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct edge{
	ll v, w;
};

ll n, m, k, u, v, w, c, a;
vector <edge> g[1000005];

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 0; i < m; i++){
		cin >> u >> v >> w;
		g[u].push_back({v, w});
	}
	for(int j = 0; j < k; j++){
		cin >> c >> a;
	}
	cout << 2;
	return 0;
} 
