#include <bits/stdc++.h>
using namespace std;
#define int long long

#ifdef UNYBHGFD
	#define DYZ_DEBUG(msg) cout << "DEBUG(" << __LINE__ << "): " << msg << '\n';
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


#define UNYBHGFD_FILENAME "number"
const int NMAX = 1e6;
char arr[NMAX], inp;
int arr_size;
signed main() {
	#ifndef UNYBHGFD
		freopen(UNYBHGFD_FILENAME ".in",  "r", stdin);
		freopen(UNYBHGFD_FILENAME ".out", "w", stdout);
	#endif
	while (cin >> inp) {
		if ('0' <= inp && inp <= '9') {
			arr[arr_size++] = inp;
		}
	}
	sort(arr, arr+arr_size);
	for (DYZ_FOR_I(i, arr_size)) {
		cout << arr[i];
	}
	DYZ_RT0;
}
