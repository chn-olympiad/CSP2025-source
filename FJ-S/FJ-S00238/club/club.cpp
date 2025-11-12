#include <bits/stdc++.h>
#define int long long 
using namespace std;
const int N = 1e5 + 10;
int s1[N], s2[N], s3[N];
int ans = -1, n;
int a1 = 0, a2 = 0, a3 = 0;
inline void f(int site, int sum) {
	if(site > n) {
		ans = max(ans, sum);
		return;
	}
	f(site + 1, sum);
	if(a1 + 1 <= n / 2) a1 += 1, f(site + 1, sum + s1[site]), a1 -= 1;
	if(a2 + 1 <= n / 2) a2 += 1, f(site + 1, sum + s2[site]), a2 -= 1;
	if(a3 + 1 <= n / 2) a3 += 1, f(site + 1, sum + s3[site]), a3 -= 1;
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	cin >> T;
	while(T--) {
		ans = -1;
		bool vis[N];
		memset(vis, false, sizeof(vis));
		cin >> n;
		for(int i = 1; i <= n; i++) cin >> s1[i] >> s2[i] >> s3[i];
		f(1, 0);
		cout << ans << '\n';
	}
	return 0;
} 
