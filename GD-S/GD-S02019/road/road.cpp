#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define vi vector<int>
#define pii pair<int,int>
#define pb push_back
#define mkp make_pair
#define rep(i, l, n) for (int i = (l); i <= (n); ++i)
#define per(i, n, l) for (int i = (n); i >= (l); --i)
#define debug(x) cout << #x << " " << x << "\n";
#define pi3 array<int,3> 
#define ll long long

int rd() {
	int x = 0, f = 1;
	char ch = getchar();
	while (!('0' <= ch && ch <= '9')) {
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while ('0' <= ch && ch <= '9') {
		x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar();
	} 
	return x * f; 
}

bool MemoryST;

const int M1 = 12;
const int M = 33;
const int K = 1e6 + 10; 
const int N = 1e4 + 10; 
const ll inf = 1e15 + 10;

int f[N];
int n, m, k;
ll ss1[M], ss2[M];
pi3 ed[K], e[6 * N];

pi3 ed1[M][N];
pi3 ed2[M][N];

int c[M1], id[M1], a[M1][N]; 

int find(int x) {
	if (f[x] == x) return x;
	return f[x] = find(f[x]); 
}

void init() {
	rep(i, 1, n)
		f[i] = i;
	sort(ed + 1, ed + m + 1);
	int c = 0;
	rep(i, 1, m) {
		int u = ed[i][1],v = ed[i][2];
		u = find(u); v = find(v);
		if (u != v)
			f[u] = v, ed[++c] = ed[i]; 
		if (c == n - 1) break ;
	}
}

ll solve(int x, int y) {
	int i = 1, j = 1, c = 0;
	ll s = 0;
	for (int i = 1; i <= n; ++i)
		f[i] = i; 
	int u, v;
	while (c < n - 1) {
		if (ed1[x][i][0] < ed2[y][j][0]) {
			u = find(ed1[x][i][1]); v = find(ed1[x][i][2]);
			if (u != v) f[u] = v, s += ed1[x][i][0], ++c; ++i; 
		} else {
			u = find(ed2[y][j][1]); v = find(ed2[y][j][2]);
			if (u != v) f[u] = v, s += ed2[y][j][0], ++c; ++j;
		}
	}
	return s;
}

void Mainsolve() {
	n = rd(); m = rd(); k = rd();
	int B = min(k, 5);
	rep(i, 1, m) {
		ed[i][1] = rd();
		ed[i][2] = rd();
		ed[i][0] = rd();
	}
	init();
	rep(i, 1, k) {
		c[i] = rd();
		rep(j, 1, n)
			a[i][j] = rd();
		id[i] = 1;
		rep(j, 1, n)
			if (a[i][id[i]] > a[i][j]) id[i] = j;
	} 
	rep(s, 0, (1 << B) - 1) {
		m = 0;
		rep(i, 1, n - 1)
			e[++m] = ed[i];
		for (int i = 0; i < B; ++i)
			if ((s >> i) & 1) {
				int j = i + 1;
				ss1[s] += c[j] + a[j][id[j]]; 
				rep(k, 1, n)
					if (k != id[j])
						e[++m] = (pi3){ a[j][k], id[j], k };
			}
		sort(e + 1, e + m + 1);
		rep(i, 1, n)
			f[i] = i;
		int c = 0;
		rep(i, 1, m) {
			int u = e[i][1],v = e[i][2];
			u = find(u); v = find(v);
			if (u != v)
				f[u] = v, ed1[s][++c] = e[i];
			if (c == n - 1) break ;
		}
//		rep(i, 1, n- 1)
//			cout << ed1[s][i][0] << " " << ed1[s][i][1] <<" " << ed1[s][i][2] << "\n";
	}
	
	rep(s, 0, (1 << (k - B)) - 1) {
		m = 0;
		rep(i, 1, n - 1)
			e[++m] = ed[i];
		for (int i = 0; i < k - B; ++i)
			if ((s >> i) & 1) {
				int j = i + B;
				ss2[s] += c[j] + a[j][id[j]];
				rep(k, 1, n)
					if (k != id[j])
						e[++m] = (pi3){  a[j][k], id[j], k };
			}
		sort(e + 1, e + m + 1);
		rep(i, 1, n)
			f[i] = i;
		int c = 0;
		rep(i, 1, m) {
			int u = e[i][1],v = e[i][2];
			u = find(u); v = find(v);
			if (u != v)
				f[u] = v, ed2[s][++c] = e[i];
			if (c == n - 1) break ;
		}
	}
	
	ll ans = inf;
	rep(s1, 0, (1 << B) - 1) {
		rep(s2, 0, (1 << (k - B)) - 1) {
			ll s = ss1[s1] + ss2[s2];
			ans = min(ans, (ll)s + solve(s1, s2));
//			cout << s1 << " " << s2 << " " << s + solve(s1, s2) << "\n";
		}
	}
	cout << ans << "\n";
}

bool MemoryED;
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cerr << fixed << setprecision(6) << (&MemoryST-&MemoryED) / 1024.0/ 1024.0 << "MB\n";

	int T = 1; //cin >> T;
	while (T--) Mainsolve();

	cerr << 1e3 * clock() / CLOCKS_PER_SEC << "ms\n";

//	system("fc .out .out") ;
	return 0;
}

