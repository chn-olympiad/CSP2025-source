#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)



const int mod = 998244353;
const int N = 3 + 5000;

mt19937 rnd(time(NULL));


int n, k;
int a[N];
int dp[N * 2];

int pow2[N];

void add(int &x, int y) {
	x += y;
	if (x >= mod) {
		x -= mod;
	}
}

int main() {
//	freopen("D:\\work\\polygon\\polygon5.in", "r", stdin);
//	freopen("D:\\work\\polygon\\polygon5.out", "w", stdout);	
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);	
	
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	
	pow2[0] = 1;
	for (int i = 1; i <= n; ++i) {
		pow2[i] = pow2[i - 1] * 2 % mod;
	}
	
	sort(a + 1, a + n + 1);
	
	int maxa = a[n];
	
	int ans = 0;
	
	for (int i = 1; i <= n; ++i) {
		for (int j = a[i] + 1; j <= maxa + 1; ++j) {
			add(ans, dp[j]);
		}
		
		for (int j = maxa + 1; j >= 1; --j) {
			add(dp[min(maxa + 1, j + a[i])], dp[j]);
		}
		
		for (int j = 1; j < i; ++j) {
			add(dp[min(a[i] + a[j], maxa + 1)], 1);
		}
	}
	
	cout << ans % mod;
	
	return 0;
} 