#include <bits/stdc++.h>
#define int long long

using namespace std;
const int N = 1e6 + 10;
int n, m, k, v[N], minn[N], tot, ans, dis[N], fa[N];
bool f[N];
inline int read () {
	int val = 0, f = 1;
	char ch = getchar ();
	for (; !isdigit (ch); ch = getchar ())
	    if (ch == '-') f = -1;
	for (; isdigit (ch); ch = getchar ())
	    val = (val << 1) + (val << 3) + (ch ^ 48);
	return val * f; 
}
int find (int x) {
	return (fa[x] == x ? x : fa[x] = find (fa[x]));
}
void merge (int x, int y){
	fa[find(x)] = find (y);
}
struct Node {
	int val, u, v;
	bool operator < (const Node & b) const {
		return val < b.val;
	}
} a[N];
signed main () {
    freopen ("road.in", "r", stdin);
    freopen ("road.out", "w", stdout);
    
    n = read(), m = read(), k = read();
    fill (minn + 1, minn + 1 + n, INT_MAX);
    for (int i = 1; i <= m; i++) {
    	a[i].u = read(), a[i].v = read(), a[i].val = read();
    	minn[a[i].u] = min (minn[a[i].u], a[i].val);
    	minn[a[i].v] = min (minn[a[i].v], a[i].val);
	}
	bool fenzhi = 1; 
	for (int i = 1, c; i <= k; i++) {
		c = read();
		if (c != 0) fenzhi = 0;
		int res = 0;
		for (int j = 1; j <= n; j++)
		    v[j] = read(), res += (minn[j] - v[j]), fenzhi = (v[j] == 0 ? 1 : 0);
		if (res > c) {
		   tot++;
		   for (int j = 1; j <= n; j++)
		       a[++m].val = v[j], a[m].u = tot, a[m].v = j, minn[j] = min (minn[j], v[j]);
		   ans += c;
		}
	}
	if (fenzhi) cout << 0;
	else {
	    for (int i = 1; i <= 1000001; i++) fa[i] = i;
		stable_sort (a + 1, a + 1 + m); 
		for (int i = 1; i <= m; i++) {
			int fx = find (a[i].u), fy = find (a[i].v);
			if (fx != fy) {
			   merge (a[i].u, a[i].v);
			   ans += a[i].val;
			}
		}
	    cout << ans; 
	}


    return 0;	
} 


