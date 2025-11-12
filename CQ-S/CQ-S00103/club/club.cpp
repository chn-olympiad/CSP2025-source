#include<bits/stdc++.h>
#define ll long long
#define pii pair<int , int>
using namespace std;
const int MAXN = 5e5 + 5;
int n , cnt[4] , a[MAXN] , b[MAXN] , c[MAXN] , tp[MAXN];
void solve() {
	cin >> n;
	int ans = 0;
	cnt[1] = cnt[2] = cnt[3] = 0;
	for (int i = 1 ; i <= n ; i ++) {
		cin >> a[i] >> b[i] >> c[i];
		int v = max({a[i] , b[i] , c[i]});
		ans += v;
		if (v == a[i]) cnt[1] ++ , tp[i] = 1;
		else if (v == b[i]) cnt[2] ++ , tp[i] = 2;
		else cnt[3] ++ , tp[i] = 3;
	}
	if (cnt[1] > n / 2) {
		priority_queue<int> q;
		for (int i = 1 ; i <= n ; i ++) {
			if (tp[i] == 1) {
				int v = max(b[i] - a[i] , c[i] - a[i]);
				q.push(v);
			}
		}
		while(cnt[1] > n / 2) ans += q.top() , q.pop() , cnt[1] --;
	}
	if (cnt[2] > n / 2) {
		priority_queue<int> q;
		for (int i = 1 ; i <= n ; i ++) {
			if (tp[i] == 2) {
				int v = max(a[i] - b[i] , c[i] - b[i]);
				q.push(v);
			}
		}
		while(cnt[2] > n / 2) ans += q.top() , q.pop() , cnt[2] --;
	}
	if (cnt[3] > n / 2) {
		priority_queue<int> q;
		for (int i = 1 ; i <= n ; i ++) {
			if (tp[i] == 3) {
				int v = max(a[i] - c[i] , b[i] - c[i]);
				q.push(v);
			}
		}
		while(cnt[3] > n / 2) ans += q.top() , q.pop() , cnt[3] --;
	}
	cout << ans << '\n';
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr) , cout.tie(nullptr);
	freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w" , stdout);
	int _;
	cin >> _;
	while(_ --) solve();
	return 0;
}
