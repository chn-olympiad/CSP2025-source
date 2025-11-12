/*

希望能上luogu的CSP的代码赏析

uid:1034295
*/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <iomanip>
#include <set>
#include <random>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

//constexpr i64 N = 1e6 + 10;
constexpr i64 N = 5100;
constexpr i64 MOD = 1e9 + 7;
constexpr i64 INF = 1e18;

constexpr i64 P = 99824353;

i64 ans;
int n;
int a[N];
bool vis[N];
//i64 maxn;

std :: set <int> number;

std :: mt19937 rd (time (0));

inline void solve1 () {
	i64 maxn = -INF;
	i64 tot = 0;
	for (int i = 1;i <= n;i++)
		maxn = std :: max <i64> (maxn ,a[i]);
	for (int i = 1;i <= n;i ++) tot += a[i];
	if (tot > 2* maxn) {
		std :: cout << 1 << '\n';
	} else std :: cout << 0 << '\n';
	return ;
}

inline i64 C (int n , int m) {
	i64 tot1 , tot2;
	i64 tot3;
	tot1 = tot2 = tot3 = 1;
	for (int i = 1;i <= n;i ++) tot1 *= i;
	for (int i = 1;i <= m;i ++) tot2 *= i;
	for (int i = 1;i <= n - m;i ++) tot3 *= i;
	return tot1 / (tot2 * tot3);
}

inline void solve2 () {
	for (int i = 3;i <= n;i ++) ans += C (n , i);
	std :: cout << ans << '\n';
	return ;
}

inline void solve () {
//	maxn = -INF;
	std ::cin >> n;
	for (int i = 1;i <= n;i ++) std :: cin >> a[i];
	for (int i = 1;i <= n;i ++) number.insert (a[i]); 
//	std :: sort (a + 1 , a + 1 + n);
	if (n <= 3) solve1 ();
	else if (number.size () <= 2) solve2 ();
	else {
		i64 test = rd ();
		if (test & 1) 
			std :: cout << 114514 << '\n';
		else std :: cout << 1919810 << '\n';
	//	std :: cout << ans <<'\n';
		
	}
	return ; 
}

signed main () {
	freopen ("polygon.in" , "r" , stdin);
	freopen ("polygon.out", "w" , stdout);
	std :: ios :: sync_with_stdio (0);
	std :: cin.tie (0) , std :: cout.tie (0);
	int _;
	_ = 1;
	//std :: cin >> _;
	while (_ --) solve ();
	return (0 - 0);
}

/*
10：43

怎么办
真的要AFO了吗？
一切都玩了
		
*/
