/*盼君勿忘*/
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define x first
#define y second
#define vec vector
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define MAXN 500005

template <typename T> void read (T &x) {
	x = 0; T f = 1; char ch = getchar ();
	while (!isdigit (ch)) { if (ch == '-') f = -1; ch = getchar (); }
	while (isdigit (ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar ();
	x *= f;
}

template <typename T, typename ...Arp> void read (T &x, Arp & ...arp) {
	read (x), read (arp...);
}

int n, k, a[MAXN], b[MAXN], dp[MAXN], dpmx[MAXN];
map <int, int> to;

signed main () {
	freopen ("xor.in", "r", stdin);
	freopen ("xor.out", "w", stdout);
	read (n, k);
	
	for (int i = 1; i <= n; ++i) {
		read (a[i]), b[i] = b[i - 1] ^ a[i];
	}
	
	
	to.insert ({0, 0});
	
	for (int i = 1; i <= n; ++i) {
		if (to.find (b[i] ^ k) != to.end ()) 
			dp[i] = dpmx[to[b[i] ^ k]] + 1;

		to[b[i]] = i;
		dpmx[i] = max (dpmx[i - 1], dp[i]);
	}
	
	printf ("%d\n", *max_element (dp + 1, dp + n + 1));
	return 0;
}

/*
4 2
2 1 0 3
2

4 3
2 1 0 3
2

4 0
2 1 0 3
1
*/
