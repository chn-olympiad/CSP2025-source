#include<bits/stdc++.h>
using namespace std;
#define F(i,j,k) for(int i=j;i<=k;i++)
#define D(i,j,k) for(int i=j;i>=k;i--)



const int N = 1e4+100;


int fa[N];

int find(int x) {
	if (fa[x] == x)return x;
	else return fa[x] = find(fa[x]);
}
void merge(int x, int y) {
	fa[find(x)] = find(y);
}
inline bool query(int x, int y) {
	return find(x) == find(y);
}
inline void refresh(int x) {
	for (int i = 1; i <= x; i++) {
		fa[i] = i;
	}
}

inline bool G(int mask, int x) {
	return (mask >> (x - 1ll)) & 1ll;
}

signed main() {
	srand(time(0));
	int TLE = 0;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	vector<pair<int, pair<int, int>>>e;
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		e.push_back({w, {u, v}});
	}
	
	vector<vector<int>>C(k + 1, vector<int>(n + 1));
	for (int i = 1; i <= k; i++) {
		cin >> C[i][0];
		for (int j = 1; j <= n; j++) {
			cin >> C[i][j];
			e.push_back({C[i][j], {j, i + n}});
		}
	}
	sort(e.begin(), e.end());
	long long ans = 1e14;
	vector<int>masks;
	for (int mask = 0; mask < (1ll << k); mask++) {
		masks.push_back(mask);
	}
	
	random_shuffle(masks.begin(), masks.end());
	
	for (int i = 0; i < masks.size(); i++) {
		if (TLE >= 2e8 && k>=6) {
			break;
		}
		refresh(n + 10);
		int mask = masks[i];
		long long cur = 0;
		for (auto x : e) {
			TLE++;
			if (x.second.second > n) {
				if (!G(mask, x.second.second - n))continue;
			}
			if (x.second.first > n) {
				if (!G(mask, x.second.first - n))continue;
			}
			if (!query(x.second.first, x.second.second)) {
				cur += x.first;
				merge(x.second.first, x.second.second);
			}
		}
		for (int j = 1; j <= k; j++) {
			if (G(mask, j))cur += C[j][0];
		}
		ans = min(ans, cur);
		
		
	}
	cout << ans << endl;
}