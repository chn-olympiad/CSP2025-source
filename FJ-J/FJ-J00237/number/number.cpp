#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <iomanip>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

constexpr i64 N = 1e6 + 10;
constexpr i64 MOD = 1e9 + 7;
constexpr i64 INF = 1e18;

i64 ans;
std :: string s;
//std :: vector <i64> v;
i64 cnt = 0;
i64 a[N];

inline bool cmp (i64 a , i64 b) {
	return a > b;
}

inline void solve () {
	std :: cin >> s;
	for (int i = 0;i < (int)s.size ();i ++) {
		int ch = s[i] - '0';
		if (ch >= 0 && ch <= 9) {
			cnt ++;
			a[cnt] = ch;
		} 
	}
//	for (int i = 1;i <= cnt;i ++) std :: cout << a[i] << ' ';
//	std :: cout << '\n';
	std :: sort (a + 1 , a + 1 + cnt , cmp);
	for (int i = 1;i <= cnt;i ++) std :: cout << a[i];
	return ;
}

signed main () {
	freopen ("number.in" , "r" , stdin);
	freopen ("number.out" , "w" , stdout);
	std :: ios :: sync_with_stdio (0);
	std :: cin.tie (0) , std :: cout.tie (0);
	int _;
	_ = 1;
	//std :: cin >> _;
	while (_ --) solve ();
	return (0 - 0);
}

/*
number
290es1q0
*/
