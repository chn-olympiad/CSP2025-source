/*The code is from @luogu-koukilee*/ 
#include <bits/stdc++.h>

typedef long long i64;
typedef int i32;
typedef unsigned long long ui64;

const i64 MAXN = 1010100, INF = 992009100720100812;
const ui64 p = 1311;

inline void read (i64& x) {scanf ("%lld", &x);}
inline void print (i64 x) {printf ("%lld", x);}
inline void put (i64 x) {print (x), putchar ('\n');} 

i64 n, q, L;
ui64 ppow[MAXN * 5];
std::string s[MAXN][2];
std::vector <ui64> has[MAXN][2];

int main () {
	freopen ("replace.in", "r", stdin);
	freopen ("replace.out", "w", stdout);
	read (n), read (q);
	
	for (i32 i = 1; i <= n; i++) {
		std::cin >> s[i][0]; L = std::max (L, (i64)s[i][0].size ());
		ui64 las = 0;
		for (i32 j = 0; j < (i64)s[i][0].size (); j++) {
			las = las * p + (ui64)(s[i][0][j] - 'a' + 1);
			has[i][0].push_back (las);
		} 
		std::cin >> s[i][1];
		las = 0;
		for (i32 j = 0; j < (i64)s[i][1].size (); j++) {
			las = las * p + (ui64)(s[i][1][j] - 'a' + 1);
			has[i][1].push_back (las);
		}
	}
	
	ppow[0] = 1;
	for (i32 i = 1; i <= L; i++)
		ppow[i] = ppow[i - 1] * p; 
	
	while (q--) {
		std::string t, e; i64 ans = 0; std::cin >> t >> e;
		std::vector <ui64> ha, hb; ui64 las = 0;
		for (i32 j = 0; j < (i64)t.size (); j++) {
			las = las * p + (ui64)(t[j] - 'a' + 1);
			ha.push_back (las);
		}
		las = 0;
		for (i32 j = 0; j < (i64)e.size (); j++) {
			las = las * p + (ui64)(e[j] - 'a' + 1);
			hb.push_back (las);
		}
		
		for (i32 i = 0; i < (i64)t.size (); i++) {
			for (i32 j = 1; j <= n; j++) {
				if (i + s[j][0].size () - 1 < t.size ()) {
					i64 l = i, r = i + s[j][0].size () - 1;
					if (ha[r] - (!l ? 0 : ha[l - 1] * ppow[r - l + 1]) == has[j][0].back () &&
						hb[r] - (!l ? 0 : hb[l - 1] * ppow[r - l + 1]) == has[j][1].back () &&
						(!l || (ha[l - 1] == hb[l - 1])) &&
						(ha[(i64)t.size () - 1] - ha[r] * ppow[(i64)t.size () - 1 - r] ==
						hb[(i64)t.size () - 1] - hb[r] * ppow[(i64)t.size () - 1 - r]))
							ans++;
				} 
			}
		}
		
		put (ans);
	}
	return 0;
}
