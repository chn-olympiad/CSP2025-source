#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

const int N = 1e5 + 7;
using namespace std;

int T;
int n;
int mem[N];
int pll[N][4], dp[N][4];
int cl1, cl2, cl3;
int cl[4];

inline int read() {
	int x = 0, k = 1;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-') k = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		x = (x << 3) + (x << 1) + (c ^ 48);
		c = getchar();
	}
	return x*k;
}

void insert() {
	n = read();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 3; j++) {
			pll[i][j] = read();
		}
	}
}

void work() {
	T = read();
	while (T--) {
		memset(mem, -1, sizeof(mem));
		for (int i = 0; i <= N; i++) {
			for (int j = 0; j <= 4; j++) {
				pll[i][j] = 0;
			}
		}
		insert();
		int largest;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++) {
				int maxx = 0;
				for(int k = 1; k <= 3; k++) {
					if (cl[k] + 1 <= (n / 2)) {
						cl[k]++;
						dp[i][k] = dp[i-1][j] + pll[i][k];
						maxx = max(maxx, dp[i][k]);
						cl[k]--;
					}
				}
				dp[i][j] = maxx;
			}
		}
		int maxx;
		for (int i = 1; i <= 3; i++) {
			maxx = max(maxx, dp[n][i]);
		}
		cout << maxx << endl;
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	work();
	return 0;
} 
