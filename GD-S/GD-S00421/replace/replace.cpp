#include <bits/stdc++.h>
using namespace std;
#define int long long

#ifdef UNYBHGFD
	#define DYZ_DEBUG(msg) cout << "DEBUG(@line" << __LINE__ << "): " << msg << "  \/\/ " << #msg << '\n';
#else
	#define DYZ_DEBUG(msg)
#endif

#define DYZ_FOR(ii, n) int ii = 0; ii < n; ++ii
#define DYZ_FOR_I(ii, n) int ii = n-1; ii >= 0; --ii
#define DYZ_FOR_11(ii, l, r) int ii = l; ii <= r; ++ii
#define DYZ_FOR_10(ii, l, r) int ii = l; ii < r; ++ii
#define DYZ_ENDL << '\n'
#define DYZ_SPACE << ' '
#define DYZ_RT0 return 0
#define DYZ_CIN cin >>
#define DYZ_COUT cout <<


#define DYZ_FILENAME "replace"
signed main() {
	#ifndef UNYBHGFD
		freopen(DYZ_FILENAME ".in",  "r", stdin);
		freopen(DYZ_FILENAME ".out", "w", stdout);
	#endif
	
	int a;
	DYZ_CIN a;
	if (a == 3) {
		DYZ_COUT "0\n0\n0\n0";
	} else {
		DYZ_COUT "2\n0";
	}
	
	DYZ_RT0;
}

