#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 10;
struct node {
	int d, cnt;
	bool operator < (const node &W) const { return d < W.d; }
} v[N];
int a[N][4], t[4];
int n, res;
void calc(int p) {
    // cout << t[p] << ' ' << p << '\n';
    sort(v + 1, v + n + 1);
	int cnt = 0;
	for(int i = 1; i <= n; i ++ ) {
		if(cnt == t[p] - n / 2) return ;
		if(v[i].cnt != p) continue;
		// cout << i << '\n';
		cnt ++ ; res -= v[i].d;
	}
	return ;
}
void solve() {
	for(int i = 1; i < 4; i ++ ) t[i] = 0;
	cin >> n; res = 0;
	for(int i = 1; i <= n; i ++ ) {
        cin >> a[i][1] >> a[i][2] >> a[i][3];
		int mx1 = max({a[i][1], a[i][2], a[i][3]}), mx2;
        // cout << i << '\n';
		if(mx1 == a[i][1]) {
			if(a[i][2] > a[i][3]) mx2 = a[i][2];
			else mx2 = a[i][3]; t[1] ++ ; v[i].cnt = 1;
		}
		else if(mx1 == a[i][2]) {
			if(a[i][1] > a[i][3]) mx2 = a[i][1];
			else mx2 = a[i][3]; t[2] ++ ; v[i].cnt = 2;
		}
		else {
			if(a[i][1] > a[i][2]) mx2 = a[i][1];
			else mx2 = a[i][2]; t[3] ++ ; v[i].cnt = 3;
		}
		v[i].d = mx1 - mx2; res += mx1;
	}
	for(int i = 1; i < 4; i ++ ) if(t[i] > n / 2) { calc(i); break; }
	cout << res << '\n';
}
signed main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
	ios :: sync_with_stdio(false); cin.tie(0), cout.tie(0);
	int T; cin >> T; while(T -- ) solve(); return 0;
}
