bool ST;
#include <bits/stdc++.h>
#define ll long long
#define fo(i, a, b) for(register int i = a; i <= b; i ++)

using namespace std;

const int N = 1e4 + 5, M = 1e6 + 5, K = 11;

const ll inf = 1e18;

int n, m, k;


struct edge {
	int u, v, w;
} e[N * K + M];

inline int cmp(edge A, edge B) {
	return A.w < B.w;
}

int deg[N];

void MST() {
	sort(e + 1, e + m + 1, cmp);

	int ans = 0;
	fo(i, 1, m) {
		int u = e[i].u, v = e[i].v, w = e[i].w;
		if(v <= n && deg[v] < 3) {
			deg[u] ++;
			deg[v] ++;
			ans += w;
			cout << u << " " << v << "\n";
			continue;
		}
		if(v > n && deg[u] < 3 && deg[v] < n / 2) {
			deg[u] ++;
			deg[v] ++;
			ans += w;
			cout << u << " " << v << "\n";
			continue;
		}
	}
	cout << ans - n * inf << "\n";
}

vector<int> from[K];

struct U {
	int fa[N + K], siz[N + K];
	ll res;

	inline void init(int n) {
		res = 0;
		fo(i, 1, n)
		fa[i] = i;
		return;
	}

	inline int find(int x)  {
		return fa[x] == x ? x : fa[x] = find(fa[x]);
	}

	inline void merge(int x, int y, int z) {
		x = find(x), y = find(y);
		if(x == y)
			return;
		res += z;
		if(siz[x] > siz[y])
			x = x ^ y, y = y ^ x, x = x ^ y;
		fa[x] = y;
		siz[y] += siz[x];
		return;
	}

} kF[1 << K], F[K];

inline void read(int &x) {
	static char ch = getchar();
	x = 0;
	while(ch > '9' || ch < '0')
		ch = getchar();
	while(ch >= '0' && ch <= '9')
		x = (x << 1) + (x << 3) + (ch ^ '0'), ch = getchar();
}

bool ED;

signed main() {

	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout); 
	
//	ios::sync_with_stdio(0);
//	cin.tie(0), cout.tie(0);

	read(n), read(m), read(k);

	fo(c, 0, (1 << k) - 1) {
		kF[c].init(n + k);
		fo(i, 1, k) {
			if((c & (1 << (k - 1))))
				from[i].push_back(c);
		}
	}
	fo(i, 0, k)
	F[i].init(n);

	int u, v, w;
	fo(i, 1, m) {
		read(u), read(v), read(w);
		e[i] = {u, v, w};
//		e[u].push_back({v, w});
//		e[v].push_back({u, w});
	}
	int x;
	fo(i, 1, k) {
		read(x);
		fo(c, 0, (1 << k) - 1) {
			if((c & (1 << (i - 1))))
				kF[c].res += x;
		}
		fo(j, 1, n) {
			cin >> x;
			e[++ m] = {i + n, j, x};
		}
	}

	sort(e + 1, e + m + 1, cmp);
	fo(i, 1, m) {
		u = e[i].u, v = e[i].v, w = e[i].w;
//		cout << u << " " << v << " " << w << "\n";
		if(u <= n) {
			if(F[0].find(u) == F[0].find(v))
				continue;
			fo(c, 0, (1 << k) - 1)
			kF[c].merge(u, v, w);
			fo(j, 1, k)
			F[j].merge(u, v, w);
		} else {
			u -= n;
			if(F[u].find(u + n) == F[u].find(v))
				continue;
			for(int c : from[u]) {//
				if(!(c & (1 << (u - 1))))
					continue;
				kF[c].merge(u + n, v, w);
			}
		}
	}

	ll ans = inf;
	fo(c, 0, (1 << k) - 1)
	ans = min(ans, kF[c].res);

	cout << ans << "\n";

//	cout << (ll)(&ST - &ED) / 1024 / 1024 << "MB";
	return 0;
}
