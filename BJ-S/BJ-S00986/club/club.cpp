#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <utility>

#define PROBLEM_NAME "club"
#define MULTIPLE_TEST 1

struct Solver {
	struct In {
		int n, a[100010][4];
		In() {
			std::cin >> n;
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= 3; j++)
					std::cin >> a[i][j];
		}
	} in;
	struct Out {
		int ans;
		~Out() { std::cout << ans << '\n'; }
	} out;
	int ord[100010][4], res[100010], cnt[4];
	std::priority_queue<std::pair<int, int>> pq[4];
	Solver() {}
	inline void push(int i) {
		if (res[i] == 3) return;
		int cur = ord[i][res[i]];
		pq[cur].push({in.a[i][ord[i][res[i] + 1]] - in.a[i][cur], i});
	}
	inline void Work() {
		for (int i = 1; i <= in.n; i++) {
			for (int j = 1; j <= 3; j++)
				ord[i][j] = j;
			std::sort(ord[i] + 1, ord[i] + 4, [&](int x, int y) -> bool {
				return in.a[i][x] > in.a[i][y];
			});
			cnt[ord[i][res[i] = 1]]++;
			push(i);
		}
		bool flag;
		do {
			flag = false;
			for (int i = 1; i <= 3; i++) {
				while (cnt[i] * 2 > in.n) {
					flag = true;
					auto [_, p] = pq[i].top();
					pq[i].pop(), cnt[i]--;
					cnt[ord[p][++res[p]]]++;
					push(p);
				}
			}
		} while(flag);
		for (int i = 1; i <= in.n; i++)
			out.ans += in.a[i][ord[i][res[i]]];
	}
};

int main() {
	static uint8_t space[sizeof(Solver)];
	freopen(PROBLEM_NAME ".in", "r", stdin);
	freopen(PROBLEM_NAME ".out", "w", stdout);
	// Overriding stdin/stdout, evil but working...
	std::ios::sync_with_stdio(false);
	std::cin.tie(0), std::cout.tie(0);
	int T;
#if MULTIPLE_TEST == 1
	std::cin >> T;
#else
	T = 1;
#endif
	while (T--) {
		Solver *solver = new (space) Solver();
	       	solver -> Work();
		solver -> ~Solver();
		if (T) memset(space, 0, sizeof(space));
	}
	return 0;
}
#undef PROBLEM_NAME
#undef MULTIPLE_TEST