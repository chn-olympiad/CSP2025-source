#include <bits/stdc++.h>
#define PII pair<int, int>
#define ll long long
#define ft first
#define sd second
using namespace std;

const int N = 1e5 + 5;
int n;
int a[N][3];

priority_queue<int> q[3];
int sum[3];
PII getp(int limit, int i) {
	int maxx = -1, maxi = -1;
	for(int j = 0; j < 3; ++j) {
		if(j == limit) continue;
		if(a[i][j] > maxx) maxx = a[i][j], maxi = j;
		else if(a[i][j] == maxx && sum[j] < sum[maxi]) maxi = j;
	}
	return PII{maxx, maxi};
}
void init() {
	for(int i = 0; i < 3; ++i) {
		while(!q[i].empty()) q[i].pop();
		sum[i] = 0;
	}
	return ;
}
void solve() {
	init();
	cin >> n;
	int lt = n / 2;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i][0] >> a[i][1] >> a[i][2];
	}
	ll ans = 0;
	for(int i = 1; i <= n; ++i) {
		auto tp = getp(-1, i);
		int maxx = tp.ft, maxi = tp.sd;
		tp = getp(maxi, i);
		q[maxi].push(tp.ft - maxx);
		++sum[maxi];
		ans += maxx;
	}
	for(int i = 0; i < 3; ++i) {
		while(sum[i]-- > lt) {
			ans += q[i].top();
			q[i].pop();
		}
	}
	cout << ans << "\n";
	return ;
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T; 
	while(T--) solve();
	return 0;	
}
