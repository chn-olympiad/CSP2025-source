// CSP 2025 RP++
/* \gcx ls/ \gcx ls/*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pii pair<int, int> 
#define pb push_back
#define N 5010
#define MODN 998244353

int n, dp[5010], a[5010];
struct node {
	int i, j;
};

vector<node> v[N];

bool check(int x, node p) {
	if ((p.j + x) > (2 * max(p.i, x))) {
		return true;
	}
	return false;
}

int main() {
	cin.tie(0);
	cout.tie(0);
	
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	
	if (n < 3) {
		cout << 0 << endl;
		return 0;
	}
	
	int sum = 0;
	
	// 3 之前先暴力处理。 
	// dp[N]+a[n][pii] 代表的是 N 个以前的方案数，pii记录一个最大值和一个总值。 
	// 设每次 dp 前的状态都处理好了
	// 那么状态转移方程应该是 dp[i] = dp[i - 1] + 判断方案数是否成立 
	
	// 暴力处理 3. 
	ll tmp = 0;
	
	
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			for (int k = 1; k <= n; k++) {
				if (j == k || i == k) continue;
				
				if ((a[i] + a[j] + a[k]) > 2 * max(a[i], max(a[j], a[k]))) {
//					cerr << a[i] << ' ' << a[j] << ' ' << a[k] << endl; 
					tmp++;
					v[3].pb( (node){(a[i] + a[j] + a[k]), (int)max(a[i], max(a[j], a[k]))} );
				}
			}
		}
	}
	
	dp[3] = tmp / 6; 
	
	// 初始化 v. 
	
	for (int m = 4; m <= n; m++) {
//		dp[m] = dp[m - 1];
//		v[m] = v[m - 1];
		for (node i : v[m - 1]) {
			for (int j = 1; j <= n; j++) {
				bool result = check(m, i);
				if (result) {
//					i.i = (2 * max(i.i, a[j])), i.j = (i.j + a[j]);
					v[m].pb( (node){(i.j + a[j]), (int)max(i.i, a[j])} );
				} 
				dp[m] += (int)result;
			}
		}
		
		dp[m] += dp[m - 1];
	}
	
	cout << dp[n] % MODN << endl;
}
