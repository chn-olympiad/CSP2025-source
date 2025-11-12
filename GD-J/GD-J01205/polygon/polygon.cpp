#include <bits/stdc++.h>
using namespace std;

const int N = 25;
const int mod = 998244353; 

int n, ans, a[N];

void dfs(int x, int sum, int Max) {
	if (x == n + 1) {
		if (sum > 2 * Max) ans++;
		return ;
	}
	
	dfs(x + 1, sum + a[x], max(Max, a[x]));
	dfs(x + 1, sum, Max);
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
		
	cin >> n;
	
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	
	dfs(1, 0, 0);
	
	cout << ans << endl;
	return 0;
}
