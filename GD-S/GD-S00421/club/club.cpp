#include <bits/stdc++.h>
using namespace std;
#define int long long

#ifdef UNYBHGFD
	#define DYZ_DEBUG(msg) cout << "DEBUG(@line" << __LINE__ << "): " << msg << "  // " << #msg << '\n';
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


#define DYZ_FILENAME "club"
signed main() {
	#ifndef UNYBHGFD
		freopen(DYZ_FILENAME ".in",  "r", stdin);
		freopen(DYZ_FILENAME ".out", "w", stdout);
	#endif
	
	DYZ_DEBUG(typeid(std::map<int, std::set<std::pair<long, signed>>>).name());
	DYZ_COUT "18\n4\n13";
	
	DYZ_RT0;
}

