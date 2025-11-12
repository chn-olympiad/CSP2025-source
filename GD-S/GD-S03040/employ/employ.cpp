#include <bits/stdc++.h>

#define i64 std::int64_t
#define i32 std::int32_t

#define MAX_N (size_t)(510)

#define INF (1e9 + 7)

#define MOD 998244353LL

// using namespace std;

i32 n, m;

i64 c[MAX_N], p[MAX_N];

std::string s;

i32 main(i32 argc, char* argv[]) {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);

	std::cin >> n >> m;
	
	std::cin >> s;
	
	for (i32 i = 1; i <= n; ++i) {
		std::cin >> c[i];
		p[i] = i;
	}
	
	i64 ans = 0;
	
	do {
		i64 td = 0;
		for (i32 i = 1; i <= n; ++i) {
			if (c[p[i]] <= td) {
				++td;
				continue;
			}
			if (s[i - 1] == '0') {
				++td;
				continue;
			}
			if (n - td < m) {
				break;
			}
		}
		if (n - td >= m) {
			++ans;
		}
	}while(std::next_permutation(p + 1, p + n + 1)); 

	std::cout << ans << "\n";		

	fclose(stdin);
	fclose(stdout);
	return 0;
}

