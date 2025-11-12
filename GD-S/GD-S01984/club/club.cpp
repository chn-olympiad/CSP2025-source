#include <bits/stdc++.h>
#define pb push_back
//#define int long long
using namespace std;
const int maxn = 2e5 + 5, mod = 1e9 + 7;
struct nd{
	int op, w, id;
	bool operator < (const nd &tmp) const{
		return tmp.w < w;
	}
};
priority_queue<nd> q;
bool vis[maxn];
int T, n, cnt[4], d[maxn][4];
void solve(){
	cin >> n; int ans = 0; while(!q.empty()) q.pop();
	for (int i = 1, x, y, z; i <= n; i++){
		cin >> d[i][1] >> d[i][2] >> d[i][3]; x = d[i][1], y = d[i][2], z = d[i][3];
		if (x == max({x, y, z})) q.push({1, x - max(y, z), i}), cnt[1]++, ans += x;
		else if (y == max({x, y, z})) q.push({2, y - max(x, z), i}), cnt[2]++, ans += y;
		else if (z == max({x, y, z})) q.push({3, z - max(x, y), i}), cnt[3]++, ans += z;
	}if (cnt[1] <= n / 2 && cnt[2] <= n / 2 && cnt[3] <= n / 2) cout << ans << '\n';
	else {
		while(!q.empty()){
			nd u = q.top(); q.pop();
			if (cnt[u.op] <= n / 2) continue; int now = 0;
			ans -= u.w; cnt[u.op]--;
		}cout << ans << '\n';
	}for (int i = 1; i <= n; i++) vis[i] = 0; cnt[1] = cnt[2] = cnt[3] = 0;
}
main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> T; while(T--) solve();
}