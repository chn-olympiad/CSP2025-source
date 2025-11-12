#include<bits/stdc++.h>
#define int long long

using namespace std;

const int MAXN = 1e6 + 1;

int t, n, res, id, d[MAXN], cnt[4];
struct node {
	int x, y, z, id, max, min, mid;
}a[MAXN];
bool cmp(node a, node b) {
	if(d[a.id] != d[b.id]) {
		return (d[a.id] == id);
	}
	return a.max - a.mid < b.max - b.mid;
}

signed main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while(t--) {
		res = 0, id = 0;
		cnt[0] = cnt[1] = cnt[2] = 0;
		cin >> n;
		for(int i = 1; i <= n; i++) {
			cin >> a[i].x >> a[i].y >> a[i].z;
			a[i].id = i;
			a[i].max = max({a[i].x, a[i].y, a[i].z});
			a[i].min = min({a[i].x, a[i].y, a[i].z});
			a[i].mid = a[i].x + a[i].y + a[i].z - a[i].max - a[i].min;
		}
		for(int i = 1; i <= n; i++) {
			res += a[i].max;
			if(a[i].x == a[i].max) {
				d[i] = 0;
			}
			else if(a[i].y == a[i].max) {
				d[i] = 1;
			}
			else {
				d[i] = 2;
			}
			cnt[d[i]]++;
		}
		id = (cnt[0] > n / 2 ? 0 : (cnt[1] > n / 2 ? 1 : (cnt[2] > n / 2 ? 2 : -1)));
		if(id == -1) {
			cout << res << "\n";
			continue;
		}
		int sum = cnt[id] - n / 2;
		sort(a + 1, a + n + 1, cmp);
		for(int i = 1; i <= sum; i++) {
			res -= (a[i].max - a[i].mid);
		}
		cout << res << "\n";
	}
	return 0;
}
