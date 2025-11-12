#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n;
int a[N][5];
long long ans = 0;
void dfs(int k, int x, int y, int z, long long sum) {
	if(x > n/2 || y > n/2 || z > n/2) {
		return;
    }
    if(k == n+1) {
        ans = max(ans, sum);
        return ;
    }
    dfs(k+1, x+1, y, z, sum + a[k][1]);
    dfs(k+1, x, y+1, z, sum + a[k][2]);
    dfs(k+1, x, y, z+1, sum + a[k][3]);
    return;
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) {
		cin >> n;
		ans = 0;
		for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= 3; j++) {
                cin >> a[i][j];
            }
		}
		dfs(1, 0, 0, 0, 0);
		cout << ans << "\n";
	}

	return 0;
}
