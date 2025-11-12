#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int n,m,ans,t;
struct Node {
	int a,b,c;
}s[N + 10];
int vis[N + 10];
void dfs(int x,int y,int z,int sum) {
	if (x + y + x > n) {
		ans = max(ans,sum);
		return;
	}
	for (int i = 1;i <= n && x < m; i++) {
		if (!vis[i]) {
			vis[i] = 1;
			dfs(x+1,y,z,sum + s[i].a);
			vis[i] = 0;
		}
	}
	for (int i = 1;i <= n && y < m; i++) {
		if (!vis[i]) {
			vis[i] = 1;
			dfs(x,y+1,z,sum + s[i].b);
			vis[i] = 0;
		}
		
	}
	for (int i = 1;i <= n && z < m; i++) {
		if (!vis[i]) {
			vis[i] = 1;
			dfs(x,y,z+1,sum + s[i].c);
			vis[i] = 0;
		}
		
	}
	return;
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while (t--) {
		cin >> n;
		ans = -1;
		memset(vis,0,sizeof(vis));
		for (int i = 1; i <= n; i++) cin >> s[i].a >> s[i].b >> s[i].c;
		m = n / 2;
		dfs(0,0,0,0);
		cout << ans << endl;
	}
	return 0;
}
