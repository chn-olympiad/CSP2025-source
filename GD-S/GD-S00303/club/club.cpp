#include <bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); i++)
#define R(i, j, k) for(int i = (j); i >= (k); i--)
#define ll long long
#define vi vetor<int>
#define sz(a) ((int)a.size())
#define mp make_pair
#define pb emplace_back
#define pii pair<int, int>
using namespace std;
const int N = 1e5 + 10;
int n, d[N][4]; 
struct node {
	int w, p, id;
	bool operator> (const node &T) const {
		if(w == T.w) {
			if(p == T.p) {
				return id > T.id; 
			}
			else return p > T.p; 
		}
		return w > T.w; 
	}
};
void solve() {
	cin >> n;
	priority_queue<node, vector<node>, greater<node>> q[4];
	ll ans = 0;
	L(i, 1, n) {
		priority_queue<pii> t;
		L(j, 1, 3)  {
			cin >> d[i][j];
			t.push({d[i][j], j});
		}
		int x = t.top().second; t.pop();
		int y = t.top().second; t.pop();
		int z = t.top().second; t.pop();
		q[x].push({d[i][x] - d[i][y], y, i});
		ans += d[i][x];
//		cout << i << " " << x << " " << y << " " << z << '\n'; 
	}
	int cnt = 10;
	while(q[1].size() > n / 2 || q[2].size() > n / 2 || q[3].size() > n / 2) {
		while(q[1].size() > n / 2) {
			auto it = q[1].top(); q[1].pop();
			int w = it.w, v = it.p, u = it.id;
			ans -= w;
//			cout << "a " << w << " " << v << " " << u << '\n'; 
			q[v].push({d[u][v] - d[u][6 - 1 - v], 6 - 1 - v, 0});
		}
		while(q[2].size() > n / 2) {
			auto it = q[2].top(); q[2].pop();
			int w = it.w, v = it.p, u = it.id;
			ans -= w;
//			cout << "b " << w << " " << v << " " << u << '\n'; 
			q[v].push({d[u][v] - d[u][6 - 2 - v], 6 - 2 - v, 0});
		}
		while(q[3].size() > n / 2) {
			auto it = q[3].top(); q[3].pop();
			int w = it.w, v = it.p, u = it.id;
			ans -= w;
//			cout << "c " << w << " " << v << " " << u << '\n'; 
			q[v].push({d[u][v] - d[u][6 - 3 - v], 6 - 3 - v, 0});
		}
	} 
	cout << ans << '\n'; 
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	int t;
	cin >> t;
	while(t--) solve(); 
	return 0;
} 
