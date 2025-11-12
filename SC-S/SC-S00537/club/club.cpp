#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 1e5 + 10;
int T, n;
ll ans; bool vis[5];
struct node{int w, p;} a[maxn][5];
vector<int> q[5];

void init() {
	ans = 0;
	for(int i = 1; i <= 3; i++) vector<int>().swap(q[i]);
}

void solve() {
	cin >> n; init();
	for(int i = 1; i <= n; i++) {
		memset(vis, 0, sizeof vis);
		for(int j = 1; j <= 3; j++) cin >> a[i][j].w;
		vector<int> tmp; for(int j = 1; j <= 3; j++) tmp.push_back(a[i][j].w);
		sort(tmp.begin(), tmp.end());
		for(int j = 1; j <= 3; j++) {
			for(int k = 0; k < 3; k++) {
				if(a[i][j].w == tmp[k] && !vis[k]) {
					a[i][j].p = 3 - k, vis[k] = true;
					break;
				}
			}
		}
		for(int j = 1; j <= 3; j++) if(a[i][j].p == 1) {
			for(int k = 1; k <= 3; k++) if(a[i][k].p == 2) q[j].push_back(a[i][j].w - a[i][k].w);
		}
		ans += tmp[2];
	}
	
	for(int i = 1; i <= 3; i++) {
		sort(q[i].begin(), q[i].end());
		if((int)q[i].size() > n / 2) {
			int cnt = (int)q[i].size();
			for(int j = 0; j < cnt - n / 2; j++) ans -= q[i][j];
			break;
		}
	} cout << ans << "\n";
}

int main() {
	ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	cin >> T; while(T--) solve();
	
	return 0;
} 