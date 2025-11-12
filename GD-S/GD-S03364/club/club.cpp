#include <bits/stdc++.h>

using namespace std;
const int N = 1e5+3;

int n;
struct node {
	int x, id;
	bool operator < (const node &o) const {return x > o.x;}
};
struct Node {
	node d[3];
} a[N];
int cnt[3], ans;

void solve() {
	ans = 0;
	cnt[0] = cnt[1] = cnt[2] = 0;
	cin >> n;
	for(int i=1; i <= n; ++i) {
		for(int j=0; j < 3; ++j)
			scanf("%d", &a[i].d[j].x), a[i].d[j].id = j;
	}
	for(int i=1; i <= n; ++i)
		sort(a[i].d, a[i].d+3);
	for(int i=1; i <= n; ++i) cnt[a[i].d[0].id]++;
	for(int i=1; i <= n; ++i) ans += a[i].d[0].x;
//	assert(cnt[0] + cnt[1] + cnt[2] == n);
	if(cnt[0] <= n/2 && cnt[1] <= n/2 && cnt[2] <= n/2) ;//cerr << "OK" << endl;
	else {
		int p = -1, c = 0;
		for(int i=0; i < 3; ++i) if(cnt[i] > n/2) p = i;
//		assert(p != -1);
		vector <int> v;
		for(int i=1; i <= n; ++i) {
			if(a[i].d[0].id == p) v.push_back(a[i].d[0].x - a[i].d[1].x);
		}
		sort(v.begin(), v.end());
		for(int x : v) {
			ans -= x;
			if(cnt[p] - (++c) <= n/2) break;
		}
	}
	cout << ans << endl;
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);

	int T;
	cin >> T;
	while(T--) solve();
	return 0;
}

