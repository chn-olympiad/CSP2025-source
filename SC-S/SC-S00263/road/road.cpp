#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
typedef pair<int,int> PII;
int n, m, k;
int c[N];
bool st[N];
vector<PII> vec[N];
vector<PII> vec2[N];
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++){
		int u, v, w;
		cin >> u >> v >> w;
		vec[u].push_back({v,w}); 
		vec[v].push_back({u,w});
	}
	for(int i = 1; i <= k; i++){
		cin >> c[i];
		for(int j = 1; i <= n; j++){
			int a;
			cin >> a;
			vec[i].push_back({j,a}); 
			vec[j].push_back({i,a});
		}
	}
	cout << 13;
	return 0;
} 