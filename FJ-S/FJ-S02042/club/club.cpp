#include <bits/stdc++.h>
#define pb emplace_back
using namespace std;

const int N = 1e5 + 5;

int T, n, ans;
int a[N][3], p[N], cnt[3], vis[N];
struct node {
	int v, id;
};
vector<node> c;

bool cmp(node a, node b) {
	return a.v < b.v;
}

void solve() {
	cin >> n;
	cnt[0] = cnt[1] = cnt[2] = ans = 0;
	memset(vis, 0, sizeof(vis));
	c.clear();
	for (int i = 1; i <= n; ++i) {
		cin >> a[i][0] >> a[i][1] >> a[i][2];
		int id = 0, mx = a[i][0];
		for (int j = 1; j < 3; ++j)
			if (a[i][j] > mx) {
				mx = a[i][j];
				id = j;
			}
		p[i] = id;
		ans += mx;
		cnt[id]++;
	}
	int id = -1;
	for (int i = 0; i < 3; ++i) {
		if (cnt[i] > n / 2)
			id = i;
	}
//	cout << ans << '\n';
	if (id == -1) {
		cout << ans << '\n';
		return;
	}
	for (int i = 1; i <= n; ++i) {
		if (p[i] == id) {
			c.pb((node){a[i][p[i]] - a[i][(p[i] + 1) % 3], i});
			c.pb((node){a[i][p[i]] - a[i][(p[i] + 2) % 3], i});
		}
	}
	sort(c.begin(), c.end(), cmp);
	for (int i = 0; i < c.size(); ++i) {
		if (!vis[c[i].id]) {
			vis[c[i].id] = 1;
			ans -= c[i].v;
			if (--cnt[id] <= n / 2) 
				break;
		}
	}
	cout << ans << '\n';
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> T;
	while (T--) solve();
	
	return 0;
}


