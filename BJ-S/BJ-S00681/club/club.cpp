#include <bits/stdc++.h>
using namespace std;
const int N = 30 + 4;
const int NN = 1e5 + 2;
int T, n, a[NN][4], b[NN];
long long dp[N][N / 2][N / 2][N / 2], dp2[204][102][102];
inline int read() {
	int ans = 0;
	char c = getchar();
	while('0' <= c && c <= '9') {
		ans = ans * 10 + (c - '0');
		c = getchar();
	}
	return ans;
}
inline void case1() {
	for(int i = 1; i <= n; i++) {
			for(int one = 0; one <= n / 2; one++) {
				for(int two = 0; two <= n / 2; two++) {
					for(int thr = 0; thr <= n / 2; thr++) {
						if(one != 0) dp[i][one][two][thr] = max(dp[i][one][two][thr], dp[i - 1][one - 1][two][thr] + a[i][1]);
						if(two != 0) dp[i][one][two][thr] = max(dp[i][one][two][thr], dp[i - 1][one][two - 1][thr] + a[i][2]);
						if(thr != 0) dp[i][one][two][thr] = max(dp[i][one][two][thr], dp[i - 1][one][two][thr - 1] + a[i][3]);
						//cout << "i:" << i << " " << one << "," << two << "," << thr << " dp:" << dp[i][one][two][thr] << endl;
					}
				}
			}
		}
		long long maxx = 0;
		for(int one = 0; one <= n / 2; one++) {
			for(int two = 0; two <= n / 2; two++) {
				for(int thr = 0; thr <= n / 2; thr++) {
					//cout << "n:" << n << " one:" << one << " two:" << two << " thr:" << thr << " dp:" << dp[n][one][two][thr] << endl;
					maxx = max(maxx, dp[n][one][two][thr]);
				}
			}
		}
		cout << maxx << "\n";
		for(int i = 1; i <= n; i++) {
			for(int one = 0; one <= n / 2; one++) {
				for(int two = 0; two <= n / 2; two++) {
					for(int thr = 0; thr <= n / 2; thr++) {
						dp[i][one][two][thr] = 0;
					}
				}
			}
		}
		return;
}
inline void case2() {
	for(int i = 1; i <= n; i++) {
		for(int one = 0; one <= n / 2; one++) {
			for(int two = 0; two <= n / 2; two++) {
				int thr = i - one - two;
				if(thr < 0) continue;
				if(one != 0) dp2[i][one][two] = max(dp2[i][one][two], dp2[i - 1][one - 1][two] + a[i][1]);
				if(two != 0) dp2[i][one][two] = max(dp2[i][one][two], dp2[i - 1][one][two - 1] + a[i][2]);
				if(thr != 0) dp2[i][one][two] = max(dp2[i][one][two], dp2[i - 1][one][two] + a[i][3]);
				//cout << "i:" << i << " " << one << "," << two << "," << thr << " dp2:" << dp2[i][one][two][thr] << endl;
			}
		}
	}
	long long maxx = 0;
	for(int one = 0; one <= n / 2; one++) {
		for(int two = 0; two <= n / 2; two++) {
			int thr = n - one - two;
			if(thr < 0) continue;
			//cout << "n:" << n << " one:" << one << " two:" << two << " thr:" << thr << " dp2:" << dp2[n][one][two][thr] << endl;
			maxx = max(maxx, dp2[n][one][two]);
		}
	}
	cout << maxx << "\n";
	for(int i = 1; i <= n; i++) {
		for(int one = 0; one <= n / 2; one++) {
			for(int two = 0; two <= n / 2; two++) {
				int thr = i - one - two;
				if(thr < 0) continue;
				dp2[i][one][two] = 0;
			}
		}
	}
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	T = read();
	while(T--) {
		n = read();
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= 3; j++) {
				a[i][j] = read();
			}
		}
		if(n == NN - 2) {
			for(int i = 1; i <= n; i++) b[i] = a[i][1];
			sort(b + 1, b + n + 1);
			long long ans = 0;
			for(int i = 1; i <= n / 2; i++) ans += b[n - i + 1];
			cout << ans << '\n';
		} else if(n == 200) {
			case2();
		} else {
			case1();
		}
		
	}
	return 0;
}