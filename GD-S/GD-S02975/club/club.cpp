#include <bits/stdc++.h>
using namespace std;


int n, t;
int sum[4];
long long ans = 0;
int x[210], y[210], z[210];
int dp[101][101][101];
struct p {
	int f[4];
	short id[4]{0, 1, 2, 3};
	void update() {
		for (int i = 1; i <= 3; i++) {
			for (int j = i + 1; j <= 3; j++) {
				if (f[i] < f[j]) swap(f[i], f[j]), swap(id[i], id[j]);
			}
		}
	} 
};
p a[100010];
bool cmp(p a, p b) {
	if (a.f[1] != b.f[1]) return a.f[1] > b.f[1];
	else if (a.f[2] != b.f[2]) return a.f[2] > b.f[2];
	else return a.f[3] > b.f[3];
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		cin >> n;
		if (n <= 200) {
//			printf("n <= 200\n");
			/*
			
			for (int i = 1; i <= n; i++) {
				for (int w1 = 0; w1 <= n / 2; w1++) {
					for (int w2 = 0; w2 <= n / 2; w2++) {
						for (int w3 = 0; w3 <= n / 2 && w1 + w2 + w3 <= n; w3++) {
							dp[w1][w2][w3] = max({
								dp[w1 - 1][w2][w3] + x[i], 
								dp[w1][w2 - 1][w3] + y[i], 
								dp[w1][w2][w3 - 1] + z[i]
							});
							ans = max(ans, (long long)dp[w1][w2][w3]);
						}
					}
				}
			}
			*/
			for (int i = 1; i <= n; i++) {
				cin >> x[i] >> y[i] >> z[i];
			} 
			for (int i = 1; i <= n; i++) {
				for (int w1 = n / 2; w1 >= 0; w1--) {
					for (int w2 = n / 2; w2 >= 0; w2--) {
						for (int w3 = n / 2; w3 >= 0; w3--) {
							if (w1 + w2 + w3 <= n) {
								if (w1 >= 1) dp[w1][w2][w3] = max(dp[w1][w2][w3], dp[w1 - 1][w2][w3] + x[i]);
								if (w2 >= 1) dp[w1][w2][w3] = max(dp[w1][w2][w3], dp[w1][w2 - 1][w3] + y[i]);
								if (w3 >= 1) dp[w1][w2][w3] = max(dp[w1][w2][w3], dp[w1][w2][w3 - 1] + z[i]);
								ans = max(ans, (long long)dp[w1][w2][w3]);
//								printf("i:%d	dp[%d][%d][%d] = %d\t\t%d\t%d\t%d\n", i, w1, w2, w3, dp[w1][w2][w3], dp[w1 - 1][w2][w3] + x[i], dp[w1][w2 - 1][w3] + y[i], dp[w1][w2][w3], dp[w1][w2][w3 - 1] + z[i]);
							}
						}
					}
				}
			}
			cout << ans << endl;
			ans = 0;
			memset(dp, 0, sizeof(dp)); 
		} else {
			for (int i = 1; i <= n; i++) {
				cin >> a[i].f[1] >> a[i].f[2] >> a[i].f[3];
				a[i].update();
			} 
			sort(a + 1, a + n + 1, cmp);
			for (int i = 1; i <= n; i++) {
				if (a[i].f[1] == a[i].f[3]) {
					if (sum[1] <= sum[2] && sum[1] <= sum[3]) {
						sum[1]++;
						ans += a[i].f[1];
	//					printf("1\n");
					} else if (sum[2] <= sum[1] && sum[2] <= sum[3]) {
						sum[2]++;
						ans += a[i].f[2]; 
	//					printf("2\n");
					} else {
						sum[3]++;
						ans += a[i].f[3];
	//					printf("3\n");
					}
				} else if (a[i].f[1] == a[i].f[2]) {
					if (sum[a[i].id[1]] <= sum[a[i].id[2]] && sum[a[i].id[1]] < n / 2) {
						sum[a[i].id[1]]++;
						ans += a[i].f[1];
	//					printf("%d\n", a[i].id[1]);
					} else if (sum[a[i].id[2]] < n / 2){
						sum[a[i].id[2]]++;
						ans += a[i].f[2]; 
	//					printf("%d\n", a[i].id[2]);
					} else {
						sum[a[i].id[3]]++;
						ans += a[i].f[3]; 
	//					printf("%d\n", a[i].id[3]);
					}	
				} else {
					if (sum[a[i].id[1]] < n / 2) {
						sum[a[i].id[1]]++;
						ans += a[i].f[1];
	//					printf("%d\n", a[i].id[1]);
					} else if (a[i].f[2] == a[i].f[3] || sum[a[i].id[2]] < n / 2) {
						if (sum[a[i].id[2]] <= sum[a[i].id[3]] && sum[a[i].id[2]] < n / 2) {
							sum[a[i].id[2]]++;
							ans += a[i].f[2];
	//						printf("%d\n", a[i].id[2]);
						} else {
							sum[a[i].id[3]]++;
							ans += a[i].f[3]; 
	//						printf("%d\n", a[i].id[3]);
						}
					} else {
						sum[a[i].id[2]]++;
						ans += a[i].f[2];
	//					printf("%d\n", a[i].id[2]);
					}
				}
			}
			cout << ans << endl;
			ans = 0;
			sum[1] = sum[2] = sum[3] = 0;
		}
	}
	return 0;
} 


















