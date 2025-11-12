#include <bits/stdc++.h>
using namespace std;
#define int long long

int T,n,a[114514][5],b[114514];

struct qwe {
	int id,num;
	friend bool operator < (qwe x,qwe y) {
		return x.num < y.num;
	}
};

struct qwe2 {
	int id,num;
	friend bool operator < (qwe2 x,qwe2 y) {
		return x.num > y.num;
	}
};

signed main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin >> T;
	while (T--) {
		cin >> n;
		int res = 0;
		priority_queue <qwe2> q;
		int c[5] = {0,0,0,0,0};
		for (int i = 1; i <= n; i++) {
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			int mx = max(a[i][1],max(a[i][2],a[i][3]));
			for (int j = 1; j <= 3; j++) {
				if (a[i][j] == mx) {
					res += mx;
					b[i] = j;
					c[j]++;
					break;
				}
			}
		}
		int sp_os = 0;
		for (int i = 1; i <= 3; i++) {
			if (c[i] > n / 2) sp_os = i;
		}
		if (sp_os == 1) {
			for (int i = 1; i <= n; i++) {
				if (b[i] != 1) continue;
				q.push({i,a[i][1] - max(a[i][2],a[i][3])});
			}
			while (!q.empty() && c[1] > n / 2) {
				qwe2 now = q.top();
				q.pop();
				res -= now.num;
				c[1]--;
			}
			cout << res << "\n";
		} else if (sp_os == 2) {
			for (int i = 1; i <= n; i++) {
				if (b[i] != 2) continue;
				q.push({i,a[i][2] - max(a[i][1],a[i][3])});
			}
			while (!q.empty() && c[2] > n / 2) {
				qwe2 now = q.top();
				q.pop();
				res -= now.num;
				c[2]--;
			}
			cout << res << "\n";
		} else if (sp_os == 3) {
			for (int i = 1; i <= n; i++) {
				if (b[i] != 3) continue;
				q.push({i,a[i][3] - max(a[i][1],a[i][2])});
			}
			while (!q.empty() && c[3] > n / 2) {
				qwe2 now = q.top();
				q.pop();
				res -= now.num;
				c[3]--;
			}
			cout << res << "\n";
		} else {
			cout << res << "\n";
		}
	}
	return 0;
}
