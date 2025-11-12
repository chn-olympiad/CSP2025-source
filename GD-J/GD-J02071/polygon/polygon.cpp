#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e3 + 9;
ll n, a[N], ans;

void dfs (int i, int k, ll sum){
	sum += a[i];
	if (k >= 3){
		if (sum > 2 * a[i]) ans++, ans %= 998224353;
	}
	for (int j = i + 1; j <= n; j++){
		dfs (j, k + 1, sum);
	}
}

int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort (a + 1, a + n + 1);
	for (int i = 1; i <= n - 2; i++) dfs(i, 1, 0);
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
