#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1e5 + 5;

struct Node {
	int k[3];
	int mx1, mx2;
};

struct Cmp {
	bool operator () (const Node &a, const Node &b) const {
		return a.k[a.mx1] - a.k[a.mx2] > b.k[b.mx1] - b.k[b.mx2];
	}
};

int T, n, ans, cnt[3];
Node a[N];

void Clear() {
	ans = 0;
	cnt[0] = cnt[1] = cnt[2] = 0; 
	return ;
}

void Solve() {
	Clear();
	cin >> n;
	for (int i = 1, x, y, z; i <= n; i++) {
		cin >> a[i].k[0] >> a[i].k[1] >> a[i].k[2];
		a[i].mx1 = -1, a[i].mx2 = -1;
		for (int j : {0, 1, 2}) {
			if (a[i].mx1 == -1 || a[i].k[j] > a[i].k[a[i].mx1]) {
				a[i].mx2 = a[i].mx1;
				a[i].mx1 = j;
			} else if (a[i].mx2 == -1 || a[i].k[j] > a[i].k[a[i].mx2]){
				a[i].mx2 = j;
			}
		}
	}
	sort(a + 1, a + 1 + n, Cmp());
	for (int i = 1; i <= n; i++) {
//		cout << a[i].k[0] << ' ' << a[i].k[1] << ' ' << a[i].k[2] << '\n';
//		cout << a[i].mx1 << ' ' << a[i].mx2 << '\n';
		if (cnt[a[i].mx1] < n / 2) {
			cnt[a[i].mx1]++;
			ans += a[i].k[a[i].mx1];
		} else {
			cnt[a[i].mx2]++;
			ans += a[i].k[a[i].mx2];
		}
	}
	cout << ans << '\n';
	return ;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	for (cin >> T; T--; Solve()) ;
	return 0;
}
/**
*/
