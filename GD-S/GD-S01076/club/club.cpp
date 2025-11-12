#include <iostream>
#include <cstdio>
#include <array>
#include <cmath>

std::array <std::array <int, 3>, 100010> a;
std::array <int, 3> vis;
int n;
int ans=0;
void dfs (int t, int sum) {
	if (t > n) {
		ans = std::max (ans, sum);
		return;
	}
	for (int i=0; i<3; i++) {
		if (vis[i] >= n/2)
			continue;
		vis[i] ++;
		dfs (t+1, sum+a[t][i]);
		vis[i] --;
	}
}
int main () {
	freopen ("club.in", "r", stdin);
	freopen ("club.out","w", stdout);
	
	int t;
	std::cin >> t;
	while (t--) {
		std::cin >> n;
		for (int i=1; i<=n; i++) {
			std::cin >> a[i][0] >> a[i][1] >> a[i][2]; 
		}
		dfs(1, 0);
		std::cout << ans << std::endl;
		ans = 0;
		vis.fill(0);
	}
}

