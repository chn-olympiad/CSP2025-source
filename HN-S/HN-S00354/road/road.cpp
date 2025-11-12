#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
int n, m, k;

int f[300005], sz[300005];
int Find(int x) {
	if (f[x] == x) {
		return f[x];
	}
	return f[x] = Find(f[x]);
}
void Merge(int x, int y) {
	x = Find(f[x]);
	y = Find(f[y]);
	if (x == y) {
		return ;
	}
	if (sz[x] > sz[y]) {
		swap(x, y);
	}
	f[x] = y;
	sz[y] += sz[x];
	return ;
}


struct EDGE {
	int u, v;
	long long w;
	bool operator <(const EDGE & b) const {
		return w < b.w;
	}
} e[3500005];
struct VILIAGE {
	int c;
	long long w[50005];
	int op;
} vil[15]; 
bool cmp_edge(EDGE x, EDGE y) {
	return x.w < y.w;
}
bool xinzhiA = 1;

long long ans;
void solve_xinzhiA() {
	for (int i = 1; i <= k; i++) {
		int op = vil[i].op;
		for (int j = 1; j <= n; j++) {
			if (j == op) {
				continue ;
			}
			++m;
			e[m].u = op;
			e[m].v = j;
			e[m].w = vil[i].w[j];
		}
	}
	stable_sort(e + 1, e + 1 + m, cmp_edge);
	for (int i = 1; i <= m; i++) {
		int u = e[i].u, v = e[i].v, w = e[i].w;
		if (Find(f[u]) == Find(f[v])) {
			continue ;
		} else {
			Merge(u, v);
			ans += (long long)w;
		}
	}
	cout << ans << "\n";
	return ;
}

tree<EDGE, null_type, less<EDGE>, rb_tree_tag, tree_order_statistics_node_update> T;
void solve() {
	ans = 10000000000000000LL;
	stable_sort(e + 1, e + 1 + m, cmp_edge);
	for (int st = 0; st <= (1 << k) - 1; st++) {
		long long sum = 0;
		T = tree<EDGE, null_type, less<EDGE>, rb_tree_tag, tree_order_statistics_node_update>();
		T.clear();
		for (int i = 1; i <= m; i++) {
			T.insert(e[i]);
		}
		for (int i = 1; i <= k; i++) {
			if ((1 << (i - 1)) & st) {
				sum += vil[i].c;
				for (int j = 1; j <= n; j++) {
					T.insert((EDGE){i + n, j, vil[i].w[j]});
				}
			}
		}
		for (int i = 0; i <= 2 * n; i++) {
			f[i] = i;
			sz[i] = 1;
		}
		for (tree<EDGE, null_type, less<EDGE>, rb_tree_tag, tree_order_statistics_node_update> :: iterator i = T.begin(); i != T.end(); i++) {
			int u = i -> u, v = i -> v;
			long long w = i -> w;
			//cout << w << "\n";
			if (Find(f[u]) == Find(f[v])) {
				continue ;
			}
			sum += (long long)w;
			Merge(u, v);
		}
		ans = min(ans, sum);
	}
	cout << ans << "\n";
	return ;
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	
	cin >> n >> m >> k;
	
	for (int i = 1; i <= n; i++) {
		f[i] = i;
		sz[i] = 1;
	}
	for (int i = 1; i <= m; i++) {
		cin >> e[i].u >> e[i].v >> e[i].w;
	}
	//cout << m << "done\n";;//////////////////////////////
	for (int i = 1; i <= k; i++) {
		cin >> vil[i].c;
		if (vil[i].c != 0) {
			xinzhiA = 0;
		}
		for (int j = 1; j <= n; j++) {
			cin >> vil[i].w[j];
			if (vil[i].w[j] == 0) {
				vil[i].op = j;
			}
		}
	}
	if (xinzhiA) {
		solve_xinzhiA();
	} else {
		solve();
	}
	return 0;
}
