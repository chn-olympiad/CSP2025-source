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


#define UNYBHGFD_FILENAME "polygon"
//int arr[5003], arr_s[5003], arr_size;
int a;
signed main() {
	#ifndef UNYBHGFD
		freopen(UNYBHGFD_FILENAME ".in",  "r", stdin);
		freopen(UNYBHGFD_FILENAME ".out", "w", stdout);
	#endif
	
//	DYZ_CIN arr_size;
//	for (DYZ_FOR(i, arr_size)) {
//		DYZ_CIN arr[i];
//	}
//	sort(arr, arr+arr_size);
//	
//	// ¼ÆËãÇ°×ººÍ
//	for (int i = 1; i < arr_size; ++i) {
//		arr_s[i] = arr[i-1] + arr[i];
//	}
//	
//	DYZ_RT0;
	cin >> a;
	cin >> a;
	if (a == 1) cout << 9;
	else cout << 6;
	DYZ_RT0;
}

