#include <bits/stdc++.h>

#define i64 std::int64_t
#define i32 std::int32_t

#define MAX_N (size_t)(1e5 + 10)

// using namespace std;

i32 t;

i32 n;

i64 a[MAX_N][3], id[MAX_N][3], max_a[MAX_N], div_a[MAX_N];

std::vector<size_t> sel[3];

i64 div_sum, sum;

void init() {
	div_sum = sum = 0;
	sel[0].clear();
	sel[1].clear();
	sel[2].clear();
}

void solve();

i32 main(i32 argc, char* argv[]) {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	std::cin >> t;

	while (t--) {
		init();
		solve();
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}

void solve() {
	std::cin >> n;
	for (i32 i = 1; i <= n; ++i) {
		std::cin >> a[i][0] >> a[i][1] >> a[i][2];
		id[i][0] = 0;
		id[i][1] = 1;
		id[i][2] = 2;
		std::sort(id[i], id[i] + 3, [i](const size_t lft, const size_t rgt) -> bool {
			return a[i][lft] > a[i][rgt];
		});
		max_a[i] = a[i][id[i][0]];
		div_a[i] = a[i][id[i][0]] - a[i][id[i][1]];
		sel[id[i][0]].push_back(i);
	}
	i64 max_sel, max_sel_p;
	if (sel[0].size() >= std::max(sel[1].size(), sel[2].size())) {
		max_sel = sel[0].size();
		max_sel_p = 0;
	} else if (sel[1].size() >= std::max(sel[0].size(), sel[2].size())) {
		max_sel = sel[1].size();
		max_sel_p = 1;
	} else if (sel[2].size() >= std::max(sel[1].size(), sel[0].size())) {
		max_sel = sel[2].size();
		max_sel_p = 2;
	}
	if (max_sel > n / 2) {
		std::sort(sel[max_sel_p].begin(), sel[max_sel_p].end(), [](const size_t lft, const size_t rgt) -> bool {
			return div_a[lft] < div_a[rgt];
		});
		for (i32 i = 0; i < max_sel - n / 2; ++i) {
			div_sum += div_a[sel[max_sel_p][i]];
		}
	}
	for (i32 i = 0; i < 3; ++i) {
		for (auto id: sel[i]) {
			sum += max_a[id];
		}		
	}

	std::cout << sum - div_sum << "\n";
	return;
}
