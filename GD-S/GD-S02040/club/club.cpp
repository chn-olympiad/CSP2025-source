#include<bits/stdc++.h>
using namespace std;

using ll = long long;

ll getInt() {
	ll s = 0, f = 1;
	char c = getchar();
	while (!isdigit(c)) {
		if (c == '-') f = -1;
		c = getchar();
	}
	
	while (isdigit(c)) {
		s = s * 10 + c - '0';
		c = getchar(); 
	}
	
	return s * f;
}

const int N = 1e5 + 10;
const int N_ = 200;

ll sat[N][4];
ll dp[210][210][210];
void solve() {
	int n = getInt();
	memset(sat, 0, sizeof sat);
	memset(dp, 0, sizeof dp); 
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= 3; ++j) {
			sat[i][j] = getInt();
		}
	}
	
	int t = n / 2;
	
	for (int i = 1; i <= n; ++i) {
		for (int j = t; j >= 0; --j) {
			for (int k = t; k >= 0; --k) {
				for (int l = t; l >= 0; --l) {
					if (j > 0) dp[j][k][l] = max(dp[j][k][l], dp[j - 1][k][l] + sat[i][1]);
					if (k > 0) dp[j][k][l] = max(dp[j][k][l], dp[j][k - 1][l] + sat[i][2]);
					if (l > 0) dp[j][k][l] = max(dp[j][k][l], dp[j][k][l - 1] + sat[i][3]);
				}
			}
		}
	}
	
	printf("%lld\n", dp[t][t][t]);

	
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	int t = getInt();
	
	while (t--) {
		solve(); 
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
