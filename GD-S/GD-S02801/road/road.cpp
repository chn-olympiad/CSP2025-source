#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define debug(x) cerr << #x << " = " << x << "\n"

const int maxn = 1e4 + 10;
const int maxm = 1e6 + 10;

vector<pair<int, int>> G[maxn];

pair<int, int> C[11];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k, u, v, w, c, a;
	cin >> n >> m >> k;
	bool f = 1;
	for(int i = 1; i <= m; ++i){
		cin >> u >> v >> w;
		G[u].push_back(make_pair(v, w));
		G[v].push_back(make_pair(u, w));
	}
	for(int i = 1; i <= k; ++i){
		cin >> c >> a;
		if(c || a){
			f = 0;
		}
		C[i].make_pair(c, a);
	}
	if(f){
		cout << 0;
	}
	return 0;
}

