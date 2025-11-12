#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
struct Node{
	int val[4], s, f;
}b[MAXN];
int cnt[4], ord[4];
bool vis[MAXN];
bool cmp1(int x, int y){
	return cnt[x] > cnt[y];
}
bool cmp2(Node x, Node y){
	return x.val[x.f] - x.val[x.s] < y.val[y.f] - y.val[y.s];
}
void solve(){
	int n;
	cin >> n;
	memset(b, 0, sizeof(b));
	memset(cnt, 0, sizeof(cnt));
	memset(ord, 0, sizeof(ord));
	memset(vis, false, sizeof(vis));
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= 3; j++){
			cin >> b[i].val[j];
		}
	}
	for (int i = 1; i <= n; i++){
		int x = b[i].val[1], y = b[i].val[2], z = b[i].val[3];
		int maxn = max({x, y, z});
		int minn = min({x, y, z});
		int mid = x + y + z - minn - maxn;
		for (int j = 1; j <= 3; j++){
			if (b[i].val[j] == maxn && !b[i].f){
				b[i].f = j;
			}
			if (b[i].val[j] == mid && !b[i].s){
				b[i].s = j;
			}
		}
	}
	for (int i = 1; i <= 3; i++){
		ord[i] = i;
	}
	for (int i = 1; i <= n; i++){
		cnt[b[i].f]++;
	}
	sort(ord + 1, ord + 4, cmp1);
	sort(b + 1, b + n + 1, cmp2);
	int u = ord[1];
	int m = max(0, cnt[u] - n / 2);
	for (int i = 1; i <= n && m; i++){
		if (b[i].f != u){
			continue;
		}
		vis[i] = true;
		m--;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++){
		if (!vis[i]){
			ans += b[i].val[b[i].f];
		}
		else{
			ans += b[i].val[b[i].s];
		}
	}
	cout << ans << endl;
	return;
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--){
		solve();
	}
	return 0;
}