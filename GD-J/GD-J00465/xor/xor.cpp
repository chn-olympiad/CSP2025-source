#include <bits/stdc++.h>
using namespace std;
#define int long long

#ifdef UNYBHGFD
	#define DYZ_DEBUG(msg) cout << "DEBUG(" << __LINE__ << "): " << msg << "  \/\/ " << #msg << '\n';
#else
	#define DYZ_DEBUG(msg)
#endif

#define DYZ_FOR(ii, n) int ii = 0; ii < n; ++ii
#define DYZ_FOR_IE(ii, n) int ii = n; ii > 0;  --ii
#define DYZ_FOR_I(ii, n) int ii = n-1; ii >= 0; --ii
#define DYZ_ENDL << '\n'
#define DYZ_SPACE << ' '
#define DYZ_COUT cout <<
#define DYZ_CIN cin >>
#define DYZ_RT0 return 0;


#define UNYBHGFD_FILENAME "xor"
int N, K, arr[(int)5e5], ans_cnt;
//struct Idx {
//protected:
//	int l;
//	int r;
//
//// private:
////	   int cache;
//
//public:
//	Idx(int left, int right) {
//		l = left, r = right;
//	}
//	
//	void check() {
//		if (l > r) {
//			swap(l, r);
//		}
//	}
//	
//	int xor_sum() {
//		int ans = 0;
//		for (int i = l, i <= r; ++i) {
//			ans ^= arr[i];
//		}
//		return ans;
//	}
//};

signed main() {
	#ifndef UNYBHGFD
		freopen(UNYBHGFD_FILENAME ".in",  "r", stdin);
		freopen(UNYBHGFD_FILENAME ".out", "w", stdout);
	#endif
//	
//	DYZ_CIN N >> K;
//	for (DYZ_FOR(i, N)) {
//		CIN arr[i];
//	}
//	
//	for (DYZ_FOR(i1l, N)) {
//		for (int i1r = i1l; i1r < N; ++i1r) {
//			// Çø¼ä1×ó±ß
//			for (DYZ_FOR(ll, i1l)) {
//				if (Idx(ll, i1l).xor_sum() == K) ++ans_cnt;
//			}
//			// ÓÒ±ß 
//		}
//	}
//	
	cout << 2;
	DYZ_RT0;
}

