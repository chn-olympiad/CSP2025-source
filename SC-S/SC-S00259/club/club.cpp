#include<bits/stdc++.h>
using namespace std;
const int N = 1e3;
long long n, t, ans;
long long a[N][4] = {0}, l[4] = {0};
void dfs(int x, long long sum) {
	if (x > n) {
		ans = max(ans, sum);
		return ;
	}
	for (int i = 1; i <= 3; i++) {
		if (l[i] <= n / 2 - 1) {
			l[i]++;
			dfs(x + 1, sum + a[x][i]);
			l[i]--;
		}
	}
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%lld", &t);
	while (t--) {
		scanf("%lld", &n);
		for (long long i = 1; i <= n; i++) {

			ans = 0;
			scanf("%lld%lld%lld", &a[i][1], &a[i][2], &a[i][3]);
//			cout<<a[i][1]<<' '<<a[i][2]<<' '<<a[i][3]<<endl;
			dfs(1, 0);
		}
		cout << ans << endl;
	}

	return 0;
}