#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <int, int> PII;
#define pb push_back
#define vi vector <int>
#define R(i, l, r) for (int i = (l); i <= (r); ++i)
#define debug cout << "-------------------------------\n"
#define int ll
const int N = 3e5 + 5, P = 998244353;
int n, m;
string s;
int c[N];
int dp[20][20][1 << 19];
signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
    // ios :: sync_with_stdio(0); cin.tie(0), cout.tie(0);
	cin >> n >> m;
	cin >> s;
	s = ' ' + s;
//	R(i, 1, n) {
//		
//	}
	R(i, 1, n) {
		cin >> c[i];
	}
	dp[0][0][0] = 1;
	int T = (1 << n) - 1;
	R(i, 0, n) {
		R(j, 0, i) {
			R(st, 0, T) {
				if (!dp[i][j][st]) continue;
				R(k, 1, n) {
					if (st >> (k - 1) & 1) continue;
					if (c[k] <= j || s[i + 1] == '0') {
						dp[i + 1][j + 1][st | (1 << (k - 1))] += dp[i][j][st];
						dp[i + 1][j + 1][st | (1 << (k - 1))] %= P;
					} else {
						dp[i + 1][j][st | (1 << (k - 1))] += dp[i][j][st];
						dp[i + 1][j][st | (1 << (k - 1))] %= P;
					}
				}
			}
		}
	}
	int ans = 0;
	R(j, 0, n - m) {
		R(st, 0, T) {
			ans += dp[n][j][st];
			ans %= P;
		}
	}
	cout << ans << '\n';
    return 0;
}

