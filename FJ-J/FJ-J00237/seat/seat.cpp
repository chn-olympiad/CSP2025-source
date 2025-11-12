
/*
now is 9 : 05

it's time to sleep

zzzzzzzzzz

I have 200pts now /ll /ll /ll /ll /ll

zzzzzzzzzzzzzzzzzzzzz

But maybe it's my last time to join the CSP

byebye OI

Byebye Csp

it's time to sleep

My UID : 1034295

Byebye
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

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

//constexpr i64 N = 1e6 + 10;
constexpr i64 N = 1e3 + 10;
constexpr i64 MOD = 1e9 + 7;
constexpr i64 INF = 1e18;

i64 ans;

i64 n , m;
i64 nm;
i64 a[N];
i64 R;
i64 X , Y;

inline bool cmp (i64 a , i64 b) {
	return a > b;
}

int id;

inline void solve () {
	std :: cin >> n >> m;
	nm = n * m;
	for (int i = 1;i <= nm;i ++) {
		std :: cin >> a[i];		
	}
	R = a[1];
	std :: sort (a + 1 , a + 1 + n * m , cmp);
//	for (int i = 1;i <= nm;i ++ ) std :: cout << a[i] << ' ';
//	std :: cout << '\n';

	for (int i = 1;i <= nm;i ++)
		if (a[i] == R)
			id = i;
//	std :: cout << id << '\n';
	if (id <= n) {
		std :: cout << 1 << ' ' << id << '\n';
		return ;
	}
	X = id / n;
	Y = id - X * n; 
//	std :: cout << X << '\n';
	if (id > X * n) X ++;
	if (! (X & 1)) {
		Y = n - Y + 1;
	}
	std :: cout << X << ' ' << Y << '\n';
	return ;
}

signed main () {
	freopen ("seat.in", "r" , stdin);
	freopen ("seat.out" , "w" , stdout);
	std :: ios :: sync_with_stdio (0);
	std :: cin.tie (0) , std :: cout.tie (0);
	int _;
	_ = 1;
	//std :: cin >> _;
	while (_ --) solve ();
	return (0 - 0);
}

/*

seat

2 2
99 100 97 98

2 2
98 99 100 97

3 3
94 95 96 97 98 99 100 93 92


oh
man
fsadfsdfsad;jklfsadjklfsad;jklfsad;jklfsad;jklfsad
fckfckfckfckfckfck

*/
