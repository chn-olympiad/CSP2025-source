#include <bits/stdc++.h>
#define int long long//???
#define fi first
#define se second
#define fo(i, a, b) for(int i = a; i <= b; i ++)

using namespace std;

const int N = 1e5 + 5, inf = 1e13;

int n;

pair<int, int> a[N][4];

priority_queue<int> h[4];

struct edge {
	int u, v, w;
} e[N];

inline int cmp(edge A, edge B) {
	return A.w < B.w;
}

int tot, deg[N];

void MST() {
	int m = tot;
	sort(e + 1, e + m + 1, cmp);
	int ans = 0;
	fo(i, 1, m) {
		int u = e[i].u, v = e[i].v, w = e[i].w;
		if(v <= n && deg[v] < 3) {
			deg[u] ++;
			deg[v] ++;
			ans += w;
//			cout << u << " " << v << "\n";
			continue;
		}
		if(v > n && deg[u] < 3 && deg[v] < n / 2) {
			deg[u] ++;
			deg[v] ++;
			ans += w;
//			cout << u << " " << v << "\n";
			continue;
		}
	}
//	cout << ans - n * inf << "\n";
}

void solve() {
	cin >> n;
	fo(i, 1, 3)
	h[i] = h[0];
	int res = 0;
	fo(i, 1, n) {
		fo(j, 1, 3) {
			cin >> a[i][j].fi;
			a[i][j].se = j;
//			add(i, n + j, a[i][j]);
		}
		sort(a[i] + 1, a[i] + 3 + 1);
		h[a[i][3].se].push(a[i][2].fi - a[i][3].fi);
		a[i][1].fi = 0;
		a[i][1].se = 0; 
//		if(i > 1)
//			add(i - 1, i, inf);
		res += a[i][3].fi;
//		h[a[i][j].se].push(___)
	}
	int mid = n / 2;
	fo(i, 1, 3)  {
		while(h[i].size() > mid) {
			res += h[i].top();
			h[i].pop();
		}
	}
	cout << res << "\n";
}

signed main() {

	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int T = 1;
	cin >> T;

	while(T --) {
		solve();
	}

	return 0;
}
