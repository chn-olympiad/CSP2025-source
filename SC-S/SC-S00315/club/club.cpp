#include <bits/stdc++.h>
//#pragma GCC optimize(2)
#define int long long
#define endl "\n"

using namespace std;

const int N = 1e5 + 9;

struct P {
	int value;
	int id;
}a[N], b[N], c[N];

int vis[N];

int ans;
int f;
int n;
int T;

bool cmp(P x, P y) {
	if(x.value != y.value) {
		return x.value > y.value;
	}else {
		return x.id < y.id;
	}
}

void clean(int n) {
	ans = 0;
	f = 0;
	for(int i = 1; i <= n; i++) {
		vis[i] = 0;
		a[i].value = 0;
		a[i].id = 0;
		b[i].value = 0;
		b[i].id = 0;
		c[i].value = 0;
		c[i].id = 0;
	}
}

void dfs(int id, int n, int value) {
	if(id == n + 1) {
		ans = max(ans, value);
		return ;
	}
	if(vis[1] < n / 2) {
		vis[1]++;
		dfs(id + 1, n, value + a[id].value);
		vis[1]--;
	}
	if(vis[2] < n / 2) {
		vis[2]++;
		dfs(id + 1, n, value + b[id].value);
		vis[2]--;
	}
	if(vis[3] < n / 2) {
		vis[3]++;
		dfs(id + 1, n, value + c[id].value);
		vis[3]--;
	}
}

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	cin >> T;
	while(T--) {
		cin >> n;
		for(int i = 1; i <= n; i++) {
			cin >> a[i].value >> b[i].value >> c[i].value;
			a[i].id = i;
			b[i].id = i;
			c[i].id = i;
			if(b[i].value != 0 || c[i].value != 0) {
				f = 1;
			}
		}
		if(n <= 10) {
			dfs(1, n, 0);
			cout << ans << endl;
			clean(n);
			continue;
		}
		sort(a + 1, a + n + 1, cmp);
		sort(b + 1, b + n + 1, cmp);
		sort(c + 1, c + n + 1, cmp);
		if(f == 0) {
			for(int i = 1; i <= n / 2; i++) {
				ans += a[i].value;
			}
			cout << ans << endl;
			clean(n);
			continue;
		}
		int x = 0, y = 0, z = 0;
		for(int i = 1, j = 1, k = 1; i <= n / 2 || j <= n / 2 || k <= n / 2; ) {
			while(vis[a[i].id] == 1) i++;
			while(vis[b[j].id] == 1) j++;
			while(vis[c[k].id] == 1) k++;
			if(x > n / 2) {
				a[i].value = -1;
			}
			if(y > n / 2) {
				b[j].value = -1;
			}
			if(z > n / 2) {
				c[k].value = -1;
			}
			if(a[i].value == max(a[i].value, max(b[j].value, c[k].value))) {
				ans += a[i].value;
				vis[a[i].id] = 1;
				x++;
			}else if(b[j].value == max(a[i].value, max(b[j].value, c[k].value))) {
//				cout << "2 " << b[j].value << " " << j << endl;
				ans += b[j].value;
				vis[b[j].id] = 1;
				y++;
			}else if(c[k].value == max(a[i].value, max(b[j].value, c[k].value))) {
				ans += c[k].value;
				vis[c[k].id] = 1;
				z++;
			}
//			for(int t = 1; t <= n; t++) {
//				cout << vis[t];
//			}
//			cout << endl;
		}
		cout << ans << endl;
		clean(n);
	}
	return 0;
}
