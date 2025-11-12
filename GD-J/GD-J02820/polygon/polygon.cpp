#include <bits/stdc++.h>
#define int long long 

using namespace std;
const int N = 5100, mod = 998244353;
inline int read () {
	int val = 0, f = 1;
	char ch = getchar ();
	for (; ch < '0' || ch > '9'; ch = getchar ())
	    if (ch == '-') f = -1;
	for (; ch >= '0' && ch <= '9'; ch = getchar ())
	    val = (val << 1) + (val << 3) + (ch ^ 48);
	return val * f; 
}
int n, a[N], ans; 
set <vector <int> > st;
vector <int> v;
void dfs (int p, int l) {
	 
	 if (l >= 3) { 
	 	int sum = 0, maxx = 0;
	 	for (int i : v) sum += a[i], maxx = max (maxx, a[i]);
		if (sum > 2 * maxx) st.insert (v);
	 }
	 if (p > n) return;
	 v.emplace_back (p);
	 dfs (p + 1, l + 1);
	 v.pop_back ();
	 dfs (p + 1, l);
}
signed main () {
    freopen ("polygon.in", "r", stdin);
    freopen ("polygon.out", "w", stdout);
    n = read ();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    dfs (1, 0);
    cout << st.size() % mod;

	return 0;
} 





