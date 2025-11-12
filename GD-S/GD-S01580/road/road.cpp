/*
*	特殊性质 A：对于所有 1 ≤ j ≤ k，均有 c_j = 0 且均存在 1 ≤ i ≤ n 满足 a_{j,i} = 0
*/

#include <iostream>
#include <vector>

using namespace std;

struct node {
	int to_city, value;
};

const int N = 1e4 + 10;
long long ans = 1e9;
int n, m, k;

vector<node> g[N];
int vis[N];
int ct[20];


void dfs(int x, int cnt, long long sum) {
	if (cnt == n) {
		ans = min(ans, sum);
		return ;
	}
	
//	if (sum > ans) return ;
	
	for (const node& p : g[x]) {
		int c = p.to_city;
		
		if (!vis[c] && c <= n) {
			vis[c]++;
			if (c <= n) {
				dfs(c, cnt + 1, sum + p.value);
			} else {
				int flag = ct[c-n];
				ct[c-n] = 0;
				dfs(c, cnt, sum + p.value + flag);
				ct[c-n] = flag;
			}
			vis[c]--;
			
		} 
		
	}
	
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> k;
	
	for (int i = 1; i <= m; i++) {
		int a, b, v;
		cin >> a >> b >> v;
		g[a].push_back({b, v});
		g[b].push_back({a, v});
	}
	
	for (int i = 1; i <= k; i++) {
		int t = n + i;
		cin >> ct[i];
		for (int j = 1; j <= n; j++) {
			int v;
			cin >> v;
			g[t].push_back({j, v});
			g[j].push_back({t, v});
		}
	}
	
	vis[1] = 1;
	
	dfs(1, 1, 0);
	
	cout << ans;
	
	return 0;
} 


