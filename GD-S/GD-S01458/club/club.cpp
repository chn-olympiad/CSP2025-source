#include<bits/stdc++.h>
#define int long long
using namespace std;

struct T {
	int inner[4];
	int minn;
	int maxn;
	bool equal;
	
	int operator[](int idx) const {
		return inner[idx];
	}
};

T pep[100010];
int n;
int idx[4]; 
int ans;

// dp[i][j][k]:  安排了前i个人，选择1部门的有j个，2的有k
int dp[210][110][110];

// part 1
void dfs(int now, int now_ans) {
//	cerr << now << ' ' << n << endl;
	if(now == n + 1) {
		ans = max(ans, now_ans);
		return;
	}
	for(int i = 1; i <= 3; ++i) {
		if(idx[i] == n / 2) {
			continue;
		}
		idx[i]++;
//		cerr << now << ' ' << i;
		dfs(now + 1, now_ans + pep[now][i]);
		idx[i]--;
	}
}

// part 2
void dp_solve() {
	for(int i = 1; i <= n; ++i) {
		for(int j = 0; j <= min(n/2, i); ++j) {
			for(int k = 0; k <= min(n/2, i - j); ++k) {
				int l = i - j - k;
				if(l > n / 2) {
					continue;
				}
				dp[i][j][k] = 0;
				if(j != 0) {
					dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k] + pep[i][1]);
				}
				if(k != 0) {
					dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k - 1] + pep[i][2]);
				}
				if(l != 0) {
					dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k] + pep[i][3]);
				}
				ans = max(ans, dp[i][j][k]);
			}
		}
	} 
}

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	scanf("%lld", &t);
	while(t--) {
		scanf("%lld", &n);
		bool spe_a = true;
		bool spe_b = true;
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= 3; ++j) {
				scanf("%lld", &pep[i].inner[j]);
				if(pep[i][j] != 0 && j >= 2) {
					spe_a = false;
					if(j == 3) {
						spe_b = false;
					}
				}
			}
		}
		memset(idx, 0, sizeof(idx));
		ans = 0;
		// stupid dfs, commented
//		if(n <= 10) {
//			dfs(1, 0);
//			printf("%d\n", ans);
//		} else 
		if(n <= 200) {
			// try stupid dp, win 55 pts
			memset(dp, 0, sizeof(dp));
			dp_solve();
			printf("%lld\n", ans);
		} else if(spe_a) {
			// special feature A, 5 pts
			sort(pep + 1, pep + 1 + n, [](const T&a, const T&b) {
				return a[1] > b[1];
			});
			for(int i = 1; i <= n / 2; ++i) {
				ans += pep[i][1];
			}
			printf("%lld\n", ans);
		} else if(spe_b) {
			// special feature B, 10 pts
			for(int i = 1; i <= n; ++i) {
				pep[i].maxn = max(pep[i][1], pep[i][2]);
				pep[i].minn = min(pep[i][1], pep[i][2]);
				if(pep[i][1] == pep[i][2]) {
					pep[i].equal = true;
				}
			}
			sort(pep + 1, pep + 1 + n, [](const T&a, const T&b) {
					if(a.minn == b.minn) {
						return a.maxn > b.maxn;
					}
					return a.minn < b.minn;	
				});
			for(int i = 1; i <= n; ++i) {
				if(pep[i].equal) {
					continue;
				}
				if(pep[i][1] > pep[i][2]) {
					if(idx[1] < n / 2) {
						idx[1]++;
						ans += pep[i][1];
					} else {
						idx[2]++;
						ans += pep[i][2];
					}
				}
			}
		}
	}
	return 0;
} 
