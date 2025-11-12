#include <bits/stdc++.h>
#define LL long long
using namespace std;
LL a[5001], sj[5001][5001], pow2[5001];
LL sum = 0, n, maxAll = 0;
vector<LL> ans; 
const LL mod = 998244353;
void initPow() {
	pow2[0] = 1;
	for (int i = 1; i <= n; i++) {
		pow2[i] = (2 * pow2[i - 1]) % mod;
	}
}
void dfs(LL dep, LL tmp) {
	if (dep > n) {
		if (tmp <= 2) return ;
		LL cnt = 0, maxn = 0;
		for (int i = 0; i < tmp; i++) {
			cnt += ans[i];
			maxn = max(maxn, ans[i]);
		}
		if (cnt > 2 * maxn) sum = (sum + 1) % mod;
		return ;
	} 
	if (tmp + (n - dep + 1) <= 2) return ;
	LL cnt = 0;
	for (int i = 0; i < tmp; i++) {
		cnt += ans[i];
	}
	if (cnt > 2 * maxAll) {
		sum = (sum + pow2[n - dep]) % mod;
	} else {
		ans.push_back(a[dep]);
		tmp++;
		dfs(dep + 1, tmp);
		ans.pop_back();
		tmp--;
	}
	dfs(dep + 1, tmp);
} 
bool cmp(LL a, LL b) {
	return a > b; 
}
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	LL cnt = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		cnt += a[i];
		maxAll = max(maxAll, a[i]);
	}
	initPow();
	sort(a + 1, a + 1 + n, cmp);
	int flag = 0;
	for (int i = 2; i <= n; i++) {
		if (a[i] != a[i - 1]) flag = 1;
	}
	if (!flag) {
		sj[0][0] = 1;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				sj[i][j] = (sj[i - 1][j] + sj[i - 1][j - 1]) % mod;
			}
		}
		cout << pow2[n] - sj[n][0] - sj[n][1] - sj[n][2];
		return 0;
	}
	dfs(1, 0);
	return 0;
}
