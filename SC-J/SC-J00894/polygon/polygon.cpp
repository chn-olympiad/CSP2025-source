#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define x first
#define y second
#define vec vector
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define MAXN 5005

#define mod 998244353

template <typename T> void read (T &x) {
	x = 0; T f = 1; char ch = getchar ();
	while (!isdigit (ch)) { if (ch == '-') f = -1; ch = getchar (); }
	while (isdigit (ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar ();
	x *= f;
}

template <typename T, typename ...Arp> void read (T &x, Arp & ...arp) {
	read (x), read (arp...);
}

int n;
int a[MAXN];
ll dp[MAXN], pw[MAXN];  

signed main () {
	freopen ("polygon.in", "r", stdin);
	freopen ("polygon.out", "w", stdout);
	read (n);
	for (int i = 1; i <= n; ++i) 
		read (a[i]);
	
	sort (a + 1, a + n + 1);
	
	pw[0] = 1;
	for (int i = 1; i <= n; ++i) 
		pw[i] = (pw[i - 1] * 2) % mod;
		
	ll ans = 0; dp[0] = 1;
	for (int i = 1; i <= n; ++i) { // 枚举最长木棍
		if (i >= 3) {
			ll sum = 0;
			for (int j = 0; j <= a[i]; ++j) 
				(sum += dp[j]) %= mod;
			(ans += (((pw[i - 1] - sum) % mod + mod) % mod)) %= mod;
		}
		
		for (int j = 5000; j >= a[i]; --j) {
			(dp[j] += dp[j - a[i]]) %= mod;
		}
	}
	
	printf ("%lld\n", ans);
	return 0;
}

/*
设 sum 为除了最长木棍的和
设 max 为最长木棍的长度 

要满足 sum > max 
*/

/*
5
2 2 3 8 10
6

5 
1 2 3 4 5
9
*/