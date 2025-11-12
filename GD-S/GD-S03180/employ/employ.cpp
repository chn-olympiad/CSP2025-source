/* TODO (#1#): Remove the debug macro */
#define DEBUG_AEQUILUM
#include <iostream>
#include <string>
#define int long long 
// pts 20 (6-8, 16-17)

namespace {
	constexpr int MAX_N = 500 + 5;
}

signed main() {
	std::ios::sync_with_stdio(false);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);
	
#ifndef DEBUG_AEQUILUM
	std::freopen("employ.in", "r", stdin);
	std::freopen("employ.out", "w", stdout);
#endif
	
	int n, m;
	std::cin >> n >> m;
	std::string s;
	std::cin >> s;

	std::cout.flush();
	return 0;
}
