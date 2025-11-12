#include <bits/stdc++.h>
using namespace std;

#define problem_id "xor"
#define int int64_t
#define pii pair<int64_t, int64_t>
#define vec(ty) vector<ty>
#define arr(ty, siz) array<ty, siz>
#define map(tk, tv) map<tk, tv>	

int n, k;
arr(int32_t, 500005) a, px;

int res;
// map(pii, int) dp;
// arr(arr(int32_t, 500005), 500005) dp;
// int dfs(int l, int r) {
// 	if (l == r) {
// 		// cout << "[equal] " << l << " " << r << " " << (int)(a.at(l) == k) << endl;
// 		return (int)(a.at(l) == k);
// 	}

// 	if (dp[(pii){l, r}]) {
// 		// cout << "[saved] " << l << " " << r << " " << dp.at((pii){l, r}) << endl;
// 		return dp.at((pii){l, r});
// 	}

// 	for (int kk=l; kk<=r-1; kk++) {
// 		int lr = dfs(l, kk) + dfs(kk+1, r);
// 		if (lr == 0) {
// 			dp[(pii){l, r}] = max(dp[(pii){l, r}], (int)((px.at(r) ^ px.at(l-1)) == k));
// 		}
// 		else {
// 			dp[(pii){l, r}] = max(dp[(pii){l, r}], lr);
// 		}
// 	}

// 	// cout << "[newed] " << l << " " << r << " " << dp.at((pii){l, r}) << endl;
// 	return dp.at((pii){l, r});
// }

arr(int32_t, 500005) pl;
arr(bool, 500005) used;


// fstream fin, fout;
signed main() {
	// fin.open(problem_id".in");
	// fout.open(problem_id".out");
	// #define cin fin
	// #define cout fout

	freopen(problem_id".in", "r", stdin);
	freopen(problem_id".out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);


	cin >> n >> k;
	for (int i=1; i<=n; i++) {
		cin >> a.at(i);
		px.at(i) = px.at(i-1) ^ a.at(i);
		pl.at(i) = i;
		used.at(i) = false;
	}

	// cout << dfs(1, n);

	for (int j=1; j<=n; j++) {
		for (int i=1; i<=n-j+1; i++) {
			// if (j == 1) {
			// 	dp[{i, j}] = (int)(a.at(i) == k);
			// }
			// else {
			// 	for (int d=1; d<=j; d++) {
			// 		dp[{i, j}] = max(dp[{i, j}], dp[{i, d}]+dp[{i+d, j-d}]);
			// 	}
			// 	dp[{i, j}] = max(dp[{i, j}], (int)((px.at(i+j-1)^px.at(i-1))==k));
			// }
			// // cout << i << " " << j << " " << dp[{i, j}] << endl;
			if (
				(px.at(i+j-1)^px.at(i-1)) == k &&
				([=]() {
					for (int ii=i, ij=1; ij<=j; ii++, ij++) {
						if (used.at(ii)) {
							return false;
						}
					}
					return true;
				})()
			) {
				// cout << i << " " << i+j-1 << " " << (px.at(i+j-1)^px.at(i-1)) << endl;
				res++;
				for (int ii = i, ij=1; ij<=j; ii++, ij++) {
					used.at(ii) = true;
				}
				// for (int i=1; i<=n; i++) {
				// 	cout << used.at(i) << " ";
				// }
				// cout << endl;
			}
		}
	}
	// cout << dp[{1, n}];

	// for (int i=1; i<=n; i++) {
	// 	for (int j=i; j<=n; j++) {
	// 		if (
	// 			(px.at(j)^px.at(i-1)) == k &&
	// 			all_of(next(cbegin(pl), i), next(cbegin(pl), j), [](int n) { return !used.at(n); })
	// 		) {
	// 			cout << i << " " << j << endl;
	// 			res++;
	// 			fill(next(begin(used), i), next(begin(used), j), true);
	// 		}
	// 	}
	// }

	cout << res;




	// #undef cin
	// #undef cout
	return 0;
}
// #undef int

/*

CSP-J RP++
CSP-J RP++
CSP-J RP++

Nina Iseri保佑我

*/