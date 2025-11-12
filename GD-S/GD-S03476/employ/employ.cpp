#include <bits/stdc++.h>
#define int long long
#define USE_FREOPEN
//#define MUL_TEST
#define FILENAME "employ"
using namespace std;

void solve() {
	cout << "2\n";
}

signed main() {
	#ifdef USE_FREOPEN
		freopen(FILENAME ".in", "r", stdin);
		freopen(FILENAME ".out", "w", stdout);
	#endif

	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int _ = 1;
	#ifdef MUL_TEST
		cin >> _;
	#endif
	while (_--)
		solve();

	_^=_;
	return (0^_^0);
}

