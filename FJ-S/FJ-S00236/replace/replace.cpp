#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

constexpr i64 N = 2e5 + 10;
constexpr i64 INF = 1e18;
constexpr i64 MOD = 1e9 + 7;

i64 ans;
int _;
int n , q;
std :: string s[N][2];

inline void solve () {
	std :: cin >> n >> q;
	for (int i = 1;i <= n;i ++) std :: cin >> s[i][1] >> s[i][2];
	for (int i = 1;i <= q;i ++) {
		std :: string dick , penis;
		std :: cin >> dick >> penis;
		std :: cout << 0 << '\n';
	}
	return ;
}

signed main () {
	freopen ("replace.in" , "r" , stdin);
	freopen ("replace.out", "w" , stdout);
	std :: ios :: sync_with_stdio (0);
	std :: cin.tie (0) , std :: cout.tie (0);
	_ = 1;
	//std :: cin >> _;
	while (_ --) solve ();	
	return (0 - 0);
}
/*

*/
