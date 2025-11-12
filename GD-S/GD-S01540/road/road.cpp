#include <bits/stdc++.h>
#define int long long

using namespace std;

const int M = 4e6 + 10;
const int N = 2e4 + 10;

struct Node {
	int sta, ed, val;
} e[M], e2[M];
int a[15][N];
int n, m, k;
int fa[N], cnt;
int ans = 2e17;
int b[N];
vector <int> ve[N];

inline int find (int x) {
	return x == fa[x] ? x : fa[x] = find (fa[x]);
}

inline void read (int &x) {
	x = 0;
	char c = getchar ();
	while (c < '0' || c > '9') {
		c = getchar ();
	}
	while (c >= '0' && c <= '9') {
		x = (x << 3) + (x << 1) + (c ^ 48);
		c = getchar ();
	} 
}

inline bool kp (Node x, Node y) {
	return x.val < y.val;
}

inline void Func () {
	for (int i = 1; i <= n + k; i ++) fa[i] = i;
	for (int i = 1; i <= m; i ++) {
		e2[i] = e[i];
	}
	int res = 0, t = 0;
	cnt = m;
	for (int i = 1; i <= k; i ++) {
		if (b[i]) {
			t ++;
			res += a[i][0];
			for (int j = 1; j <= n; j ++) {
				e2[++ cnt] = {j, n + i, a[i][j]};
			}
		}
	}
	sort (e2 + 1, e2 + 1 + cnt, kp);
	int sm = 0;
	for (int i = 1; i <= cnt; i ++) {
		int u = e2[i].sta, v = e2[i].ed, w = e2[i].val;
		int fu = find (u), fv = find (v);
		if (fu != fv) {
			fa[fu] = fv;
			sm ++;
			res += w;
			if (res > ans) return ;
			if (sm == n + t - 1) {
//				cout << res << '\n';
				ans = min (ans, res);
				return ;
			}
		}
	}
}

inline void dfs (int id) {
	if (id == k + 1) {
		Func ();
		return ;
	}
	b[id] = 1;
	dfs (id + 1);
	b[id] = 0;
	dfs (id + 1);
}

signed main () {
	freopen ("road.in", "r", stdin);
	freopen ("road.out", "w", stdout);
	read (n); read (m); read (k);
	for (int i = 1; i <= m; i ++) {
		read (e[++ cnt].sta);
		read (e[cnt].ed);
		read (e[cnt].val);
	}
	int r = 0;
	for (int i = 1; i <= k; i ++) {
		read (a[i][0]);
		r += a[i][0];
		for (int j = 1; j <= n; j ++) {
			read (a[i][j]);
		}
	}
	if (!r) {
		for (int i = 1; i <= n + k; i ++) fa[i] = i;
		for (int i = 1; i <= m; i ++) {
			e2[i] = e[i];
		}
		int res = 0, t = 0;
		cnt = m;
		for (int i = 1; i <= k; i ++) {
			for (int j = 1; j <= n; j ++) {
				e2[++ cnt] = {j, n + i, a[i][j]};
			}
		}
		sort (e2 + 1, e2 + 1 + cnt, kp);
		int sm = 0;
		for (int i = 1; i <= cnt; i ++) {
			int u = e2[i].sta, v = e2[i].ed, w = e2[i].val;
			int fu = find (u), fv = find (v);
			if (fu != fv) {
				fa[fu] = fv;
				sm ++;
				res += w;
				if (sm == n + k - 1) {
					break;
				}
			}
		}
		cout << res;
		return 0;
	}
	dfs (1);
	cout << ans;
	return 0;
} 

/*
fen ceng tu?
Oh,it is wrong
k is so small,I will try baoli
It is to difficult for me to make the baoli true
I can!
Make 2^k's kruskal,
maybe I can get 32 pts,,emm 64pt2?
Oh,it is so crazy
I can ohly have 16 to 32pts
but add the special A's 24pts,I will have 56pts the most highly!!
Ok I will have 48~56pts,it is good.
*/
