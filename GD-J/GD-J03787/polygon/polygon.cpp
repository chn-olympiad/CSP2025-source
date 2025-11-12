#include <bits/stdc++.h>
#define mod 998244353
using namespace std;
int n, a[5010];
long long ans;
vector <int> null;
void dfs (int id, int qsum, vector <int> v) {
	if (id > n) return ;	
	dfs (id + 1, qsum, v);
	v.push_back (id);
	qsum += a[id];	
	int mx = 0;
	for (int i = 0; i < v.size (); i ++) mx = max (mx, a[v[i]]);
	if (qsum > 2 * mx && v.size () >= 3) {
		ans ++;
		ans %= mod;
//		return ;
	}
	dfs (id + 1, qsum, v);
}
int main () {
    freopen ("polygon.in", "r", stdin);
    freopen ("polygon.out", "w", stdout);
    ios::sync_with_stdio (0);
    cin.tie (0), cout.tie (0);
    cin >> n;
    for (int i = 1; i <= n; i ++) 
    	cin >> a[i];    
    dfs (1, 0, null);
    cout << ans % mod;
    return 0;
}

