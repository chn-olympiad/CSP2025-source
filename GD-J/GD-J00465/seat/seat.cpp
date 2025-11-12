#include <bits/stdc++.h>
using namespace std;
// #define int long long

#ifdef UNYBHGFD
	#define DYZ_DEBUG(msg) cout << "DEBUG(" << __LINE__ << "): " << msg << "  \/\/ " << #msg << '\n';
#else
	#define DYZ_DEBUG(msg)
#endif

#define DYZ_FOR(ii, n) int ii = 0; ii < n; ++ii
#define DYZ_FOR_IE(ii, n) int ii = n; ii > 0;  --ii
#define DYZ_FOR_E(ii, n) int ii = 0; ii <= n; ++ii
#define DYZ_FOR_I(ii, n) int ii = n-1; ii >= 0; --ii
#define DYZ_ENDL << '\n'
#define DYZ_SPACE << ' '
#define DYZ_COUT cout <<
#define DYZ_CIN cin >>
#define DYZ_RT0 return 0;


#define UNYBHGFD_FILENAME "seat"
int R_idx, M, N, inp, Rs, RN, RM;
signed main() {
	#ifndef UNYBHGFD
		freopen(UNYBHGFD_FILENAME ".in",  "r", stdin);
		freopen(UNYBHGFD_FILENAME ".out", "w", stdout);
	#endif
	DYZ_CIN N >> M >> Rs;
	DYZ_DEBUG(N DYZ_SPACE << M DYZ_SPACE << Rs);
	for(DYZ_FOR(i, N*M-1)) {
		DYZ_CIN inp;
		R_idx += (inp > Rs);
	}
	DYZ_DEBUG(R_idx);
	// 先确定列，从0开始 
	RM = R_idx / N;
	DYZ_DEBUG(RM);
	// 暂时的行数，从上往下，从0开始 
	RN = R_idx % N;
	DYZ_DEBUG(RN);
	// 若列索引是奇数则换成从下往上
	if (RM % 2 == 1) {
		RN = N - RN - 1;
		DYZ_DEBUG(RN);
	}
	DYZ_COUT RM+1 DYZ_SPACE << RN + 1;
	DYZ_RT0;
}
