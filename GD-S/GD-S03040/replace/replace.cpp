#include <bits/stdc++.h>

#define i64 std::int64_t
#define i32 std::int32_t

#define MAX_N (size_t)(1e4 + 10)

#define INF (1e9 + 7)

// using namespace std;

i32 n, q;

std::map<std::string ,std::string> rep;

i32 main(i32 argc, char* argv[]) {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);

	std::cin >> n >> q;

	for (i32 i = 1; i <= n; ++i) {
		std::string s1, s2;
		std::cin >> s1 >> s2;
		rep[s1] = s2;
	}
	
	for (i32 i = 1; i <= q; ++i) {
		i64 ans = 0;
		std::string t1, t2;
		std::cin >> t1 >> t2;
		for (i32 j = 0; j < t1.length(); ++j) {
			for (i32 k = 1; j + k <= t1.length(); ++k) {
				auto y = t1.substr(j, k); 
//				std::cerr << "Y:" <<y << "\n";
				if (rep.find(y) != rep.end()) {
					auto x = t1.substr(0, j);
//					std::cerr << "X:" << x << "\n";
					i32 zlen = t1.length() - j - k;
					if (zlen > 0) {
						auto z = t1.substr(j + k);
						auto newt = x + rep[y] + z;
//						std::cout << newt << " **\n";
						if (newt == t2) {
							++ans;
						}
					} else {
						auto newt = x + rep[y];
//						std::cout << newt << " **\n";
						if (newt == t2) {
							++ans;
						}
					}
				}
			}
		}
		std::cout << ans << "\n";
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}

