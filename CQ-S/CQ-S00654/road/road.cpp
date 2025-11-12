#include<bits/stdc++.h>
using namespace std;
typedef long long ll, i64;
typedef double db;
const int N = 1e4 + 5;

ll max(ll a, ll b) {
	if (a > b) return a;
	return b;
}

ll min(ll a, ll b) {
	if (a < b) return a;
	return b;
}

ll cmp_d(ll a, ll b) {
	return a > b;
}

ll n, m, k, c[15];
ll a[15][N];// k -> n
vector<ll> mp[N];
vector<ll> w[N];



int main() {
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	cin >> n >> m >> k;//³Ç Â· ´å 
	for (int i = 1; i <= m; i++) {
		ll inp1, inp2, inp3;
		cin >> inp1 >> inp2 >> inp3;
		mp[inp1].push_back(inp2);
		mp[inp2].push_back(inp1);
		w[inp1].push_back(inp3);
		w[inp2].push_back(inp1);
	}
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	
	if (k == 0) {
		
	}
	
	return 0;
}
