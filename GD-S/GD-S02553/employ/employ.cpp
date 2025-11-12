#include <bits/stdc++.h>
#define int long long

using namespace std;
const int N = 1e4 + 10, mod = 998244353;
int n, m, a[N], p[N], ans;
string s;
int fact (int x) {
	int ans = 1;
	for (int i = 1; i <= x; i++)
	    ans *= i;
	return ans;
}
bool check () {
	 int ly = 0;
	 for (int i = 1; i <= n; i++) {
	 	 if (s[i - 1] == '0' || ly >= a[i]) ly++; 
	 } 
	 return ((n - ly) >= m ? 1 : 0);
} 
inline int read () {
	int val = 0, f = 1;
	char ch = getchar ();
	for (; !isdigit (ch); ch = getchar ())
	    if (ch == '-') f = -1;
	for (; isdigit (ch); ch = getchar ())
	    val = (val << 1) + (val << 3) + (ch ^ 48);
	return val * f; 
}
signed main () {
    freopen ("employ.in", "r", stdin);
    freopen ("employ.out", "w", stdout);
    n = read(), m = read();
    cin >> s;
    for (int i = 1; i <= n; i++)
	    a[i] = read(); 
	if (n <= 18) {
       stable_sort (a + 1, a + 1 + n);
       for (int i = 1; i <= fact (n); i++) {
    	  if (check ()) ans++, ans %= mod;
      	  next_permutation (a + 1, a + 1 + n);
	   }
	   cout << ans % mod;
	}
    else cout << 0;
    return 0;	
} 






