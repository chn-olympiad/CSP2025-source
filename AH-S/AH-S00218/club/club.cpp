#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10, M = 5;
const int order[10][4] = {
	{0, 0, 0, 0}, 
	{0, 1, 2, 3},
	{0, 1, 3, 2},
	{0, 2, 1, 3},
	{0, 2, 3, 1},
	{0, 3, 1, 2},
	{0, 3, 2, 1},
};

struct Node{
	int val[4], mmin;
	int ord[4];
	
	bool operator < (const Node& rhs) const {
		return max(val[3] - val[1], val[2] - val[1]) > max(rhs.val[3] - rhs.val[1], rhs.val[2] - rhs.val[1]);
	}
}a[N];

int n, cnt[4], belong[N];
int ans;

bool cmp(const Node& x, const Node& y) {
	return x.mmin < y.mmin;
}

void calc() {
	cin >> n;
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> a[i].val[j];
		}
		belong[i] = 1;
		ans += a[i].val[1];
	}
	sort(a + 1, a + n + 1);
	
	for (int i = 1; i <= n / 2; i++) {
		if (a[i].val[3] > a[i].val[2]) {
			ans += a[i].val[3] - a[i].val[1];
			belong[i] = 3;
			cnt[3]++;
		}
		else {
			ans += a[i].val[2] - a[i].val[1];
			belong[i] = 2;
			cnt[2]++;
		}
	}
	
	for (int i = 1; i <= n; i++) {
		if (cnt[2] == n / 2 && cnt[3] == n / 2) break;
		if (belong[i] == 1) {
			if (a[i].val[3] > a[i].val[1] && a[i].val[2] > a[i].val[1]) {
				if (a[i].val[3] > a[i].val[2] && cnt[3] < n / 2) {
					ans += a[i].val[3] - a[i].val[1];
					belong[i] = 3;
					cnt[3]++;
				}
				else {
					ans += a[i].val[2] - a[i].val[1];
					belong[i] = 2;
					cnt[2]++;
				}
			}
			else if (a[i].val[3] > a[i].val[1]) {
				if (cnt[3] < n / 2) {
					ans += a[i].val[3] - a[i].val[1];
					belong[i] = 3;
					cnt[3]++;
				}
			}
			else {
				if (cnt[2] < n / 2) {
					ans += a[i].val[2] - a[i].val[1];
					belong[i] = 2;
					cnt[2]++;
				}
			}
		}
	}
	
	printf("%lld", ans);
}

void solve(int i, int o) {
	for (int k = 1; k <= 3; k++) {
		a[i].ord[k] = order[o][k];
	}
}

void fast_read() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

void wrong() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> a[i].val[j];
		}
		
		a[i].mmin = min({a[i].val[1], a[i].val[2], a[i].val[3]});
		
		if (a[i].val[1] <= a[i].val[2] && a[i].val[2] <= a[i].val[3]) {
			solve(i, 1);
		}
		else if (a[i].val[1] <= a[i].val[3] && a[i].val[3] <= a[i].val[2]) {
			solve(i, 2);
		}
		else if (a[i].val[2] <= a[i].val[1] && a[i].val[1] <= a[i].val[3]) {
			solve(i, 3);
		}
		else if (a[i].val[2] <= a[i].val[3] && a[i].val[3] <= a[i].val[1]) {
			solve(i, 4);
		}
		else if (a[i].val[3] <= a[i].val[1] && a[i].val[1] <= a[i].val[2]) {
			solve(i, 5);
		}
		else if (a[i].val[3] <= a[i].val[2] && a[i].val[2] <= a[i].val[1]) {
			solve(i, 6);
		}
	}
	
	sort(a + 1, a + n + 1, cmp);
	
	long long ans = 0; // [0, 2e9], int is ok
	for (int i = 1; i <= n; i++) {
		bool in = false;
		for (int j = 3; j >= 1; j--) {
			if (in) break;
			int id = a[i].ord[j];
			if (cnt[id] >= n / 2) continue;
			cnt[id]++;
			ans += a[i].val[id];
			in = true;
			/*
			cout << i << ' ' << id << "\n";
			cout << cnt[1] << ' ' << cnt[2] << ' ' << cnt[3] << "\n";
			*/
		}
	}
	cout << ans << "\n";
	
	cnt[1] = cnt[2] = cnt[3] = 0;
}

void dfs1(int x, int tot) {
	if (x > n) {
		ans = max(ans, tot);
		return;
	}
	for(int j = 1; j <= 3; j++) {
		if (cnt[j] == n / 2) continue;
		cnt[j]++;
		dfs1(x + 1, tot + a[x].val[j]);
		cnt[j]--;
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	fast_read();
	
	int T;
	cin >> T;
	while (T--) {
		if (n <= 10) {
			cin >> n;
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= 3; j++) {
					cin >> a[i].val[j];
				}
			}
			dfs1(1, 0);
			cout << ans << "\n";
			ans = 0;
		}
		else {
			wrong();
			//calc();
		}
	}
	return 0;
}
