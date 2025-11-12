#include <iostream>
#include <algorithm>

const int N = 507;

int n, m, s[N], c[N], w[N];

inline int calc() {
	int died = 0, cnt = 0;
	for(int i = 1; i <= n; ++i) {
		if(died >= c[w[i]]) ++died;
		else {
			if(s[i]) ++cnt;
			else ++died;
		}
	}
	return cnt;
}

int main() {
	 freopen("employ.in", "r", stdin);
	 freopen("employ.out", "w", stdout);
	
	std::cin >> n >> m;
	for(int i = 1; i <= n; ++i) {
		char c; std::cin >> c; s[i] = c == '1';
	}

	for(int i = 1; i <= n; ++i) {
		std::cin >> c[i];
		w[i] = i;
	}

	int ans = 0;
	do {
		ans += calc() >= m;
	} while(std::next_permutation(w + 1, w + n + 1));

	std::cout << ans << "\n";
}
