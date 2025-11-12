#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define out() cout << "sb\n"

const int N = 1e5 + 5;

int T, n, pos[N], a[N][3], cnt[3];
ll ans;

//struct node {
//	int f, s, t, id; //1¡¢2¡¢3 
//}a[N];

struct Dat {
	int val, id;
	bool operator < (const Dat x) const {
		return val < x.val;
	}
};
priority_queue<Dat> q[4];

void dfs(int u, ll now) {
	if (u > n) {
		ans = max(ans, now);
		return;
	}
	for (int j = 0; j < 3; j++) if (cnt[j] < n / 2){
		cnt[j]++;
		dfs(u + 1, now + a[u][j]);
		cnt[j]--;
	}
}

int main() {
//	system("fc club.out club.ans");
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	IOS;
	cin >> T;
	while (T--) {
		cin >> n;
		if (n <= 20) {
			for (int i = 1; i <= n; i++)
			for (int j = 0; j < 3; j++)
				cin >> a[i][j];
			ans = 0, cnt[0] = cnt[1] = cnt[2] = 0;
			dfs(1, 0);
			cout << ans << "\n";
			continue;
		}
		for (int i = 1; i <= n; i++) {
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			q[2].push({a[i][2] - a[i][1], i});
//			ans += a[i][1]; //È«²¿ÔÚf 
			pos[i] = 1;
		}
		int cnt = 0, lim = n / 2;
		while (cnt < lim) {
			Dat u = q[2].top();
//			cout << u.val << ' ' << u.id << ' '<< cnt << "\n";
			q[2].pop();
			int now = -u.val, ppos = u.id;
			q[1].push({now, ppos});
//			ans += u.val;
			pos[u.id] = 2;
			cnt++;
//			cout << val.val << ' ' << val.id << "\n";
		}
//		for (int i = 1; i <= n; i++) cout << pos[i] << " \n"[i == n];
		int maxx[6] = {0, 0, 0, 0, q[2].top().val, q[1].top().val};
//		cout << maxx[1] << ' ' << maxx[2] << "\n";
		for (int i = 1; i <= n; i++) {
			if (pos[i] == 1) q[3].push({a[i][3] - a[i][1] + maxx[1], i});
			else q[3].push({a[i][3] - a[i][2] + maxx[2], i});
		}
		cnt = 0;
		while (cnt < lim && q[3].size()) {
			Dat u = q[3].top();
//			cout << u.val << ' ' << u.id << ' ' << pos[u.id] << ' ' << cnt << "\n";
			int v = u.val - maxx[pos[u.id]];
			Dat x;
			if (q[pos[u.id]].empty()) x = {0, 0};
			else {
				x = q[pos[u.id]].top();
				q[pos[u.id]].pop();	
			}
//			cout << x.val << ' ' << x.id << '\n';
			if (pos[x.id] == 3) continue;
			q[3].pop(); 
			v = max(v, v + x.val);
//			cout << v << "\n";
			if (v <= 0) {
				continue;
			}
//			out();
			cnt++;
			if (x.val > 0) {
//				cout << x.id << ' ' << pos[u.id] << "\n";
				int now = a[x.id][3] - a[x.id][pos[u.id]], ppos = x.id;
//				cout << now; 
				q[pos[x.id]].push({now + maxx[pos[x.id]], ppos});
				pos[x.id] = pos[u.id];
//				cout << pos[x.id]<< "\n";
			}
			pos[u.id] = 3;
//			for (int i = 1; i <= n; i++) cout << pos[i] << " \n"[i == n];
		}
		for (int i = 1; i <= n; i++) {
			if (pos[i] == 1) ans += a[i][1];
			else if (pos[i] == 2) ans += a[i][2];
			else ans += a[i][3]; 
//			cout << pos[i] << ' ';
		}
		cout << ans << "\n";
		while (!q[1].empty()) q[1].pop();
		while (!q[2].empty()) q[2].pop();
		while (!q[3].empty()) q[3].pop();
		ans = 0;
	}
	return 0;
}
//2710832
