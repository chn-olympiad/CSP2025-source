#include <bits/stdc++.h>
using namespace std;

const int N = 100000;

int T, n, ans, tot;
int a[N + 10][3], id[N + 10];
int b[N + 10], cnt[3];

void init() {
	memset(a, 0, sizeof(a)); memset(id, 0, sizeof(id));
	memset(b, 0, sizeof(b)); memset(cnt, 0, sizeof(cnt));
	ans = 0; tot = 0;
}

bool cmp(int u, int v) {
	return u > v;
}

void work() {
	init(); cin >> n;
	for(int i = 1; i <= n; ++i) {
		int ma = 0;
		for(int j = 0; j < 3; ++j) {
			cin >> a[i][j]; ma = max(ma, a[i][j]);
		}
		ans += ma;
		for(int j = 0; j < 3; ++j) {
			if(a[i][j] == ma) {
				id[i] = j; ++cnt[j];
				break;
			}
		}
	}
	int sp = -1;
	for(int i = 0; i < 3; ++i) {
		if(cnt[i] > n / 2) {
			sp = i; break;
		}
	}
	if(sp == -1) {
		cout << ans << '\n'; return;
	}
	for(int i = 1; i <= n; ++i) {
		if(id[i] != sp) continue;
		int ma = 0;
		for(int j = 0; j < 3; ++j) {
			if(j == sp) continue;
			ma = max(ma, a[i][j]);
		}
		b[++tot] = ma - a[i][sp];
	}
	sort(b + 1, b + tot + 1, cmp);
	int req = cnt[sp] - n / 2;
	for(int i = 1; i <= req; ++i) ans += b[i];
	cout << ans << '\n';
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--) {
		work();
	}
	return 0;
}
