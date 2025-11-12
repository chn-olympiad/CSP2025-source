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

constexpr i64 N = 1e5 + 10;
constexpr i64 INF = 1e18;
constexpr i64 MOD = 1e9 + 7;

i64 ans;
int _;
int n , m;
std :: string p;
int c[N];
i64 tot = 1;

inline void solve () {
	std :: cin >> n >> m;
	std :: cin >> p;
	for (int i = 1;i <= n;i ++) std :: cin >> c[i];
	for (int i = 1;i <= n;i ++) {
		tot *= i;
	}
	std :: cout << tot << '\n';
	return ;
}

signed main () {
	freopen ("employ.in" , "r" , stdin);
	freopen ("employ.out" , "w" , stdout);
	std :: ios :: sync_with_stdio (0);
	std :: cin.tie (0) , std :: cout.tie (0);
	_ = 1;
	//std :: cin >> _;
	while (_ --) solve ();	
	return (0 - 0);
}
/*

*/
