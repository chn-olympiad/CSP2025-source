#include <cstdio>
#include <queue>
#include <algorithm>
const int N = 100005, M = 10;
typedef long long ll;
using std::max;
ll a[N][M];
struct Node {
	int id;
	ll val;
	bool operator < (const Node &rhs) const {
		return val > rhs.val;
	}
};
std::priority_queue < Node > g[M];
ll ans;
int cnt[M];
int n;
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while(T--) {
		while(!g[1].empty()) g[1].pop();
		while(!g[2].empty()) g[2].pop();
		while(!g[3].empty()) g[3].pop();
		cnt[1] = cnt[2] = cnt[3] = 0;
		ans = 0;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) {
			scanf("%lld%lld%lld", &a[i][1], &a[i][2], &a[i][3]);
			ll tmax = max(max(a[i][1], a[i][2]), a[i][3]);
			ans += tmax;
			if(tmax == a[i][1]) {
				cnt[1]++;
				g[1].push({i, tmax - max(a[i][2], a[i][3])});
			} else if(tmax == a[i][2]) {
				cnt[2]++;
				g[2].push({i, tmax - max(a[i][1], a[i][3])});
			} else {
				cnt[3]++;
				g[3].push({i, tmax - max(a[i][1], a[i][2])});
			}
		}
		while(cnt[1] > n / 2) {
			Node top = g[1].top();
			g[1].pop();
			cnt[1]--;
			ans -= top.val;
		}
		while(cnt[2] > n / 2) {
			Node top = g[2].top();
			g[2].pop();
			cnt[2]--;
			ans -= top.val;
		}
		while(cnt[3] > n / 2) {
			Node top = g[3].top();
			g[3].pop();
			cnt[3]--;
			ans -= top.val;
		}
		printf("%lld\n", ans);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}