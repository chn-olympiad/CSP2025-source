#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 1e5 + 100, DPN = 250;
int po[N], n, ans, cntb, cntc;
struct __ {
	int ca, cb, cc;
}a[N];
bool ccc(__ a, __ b) {
	return a.ca > b.ca;
}
void A() {
	sort(a + 1, a + n + 1, ccc);
	for(int i = 1; i <= n / 2; i++) ans += a[i].ca;
}
void B() {
	priority_queue<int> q;
	for(int i = 1; i <= n / 2; i++) {
		ans += a[i].ca;
		q.push(a[i].cb - a[i].ca);
	}
	for(int i = n / 2 + 1; i <= n; i++) {
		int t = q.top();
		if(a[i].cb > t + a[i].ca) {
			ans += a[i].cb;
		}
		else {
			q.pop();
			ans += t;
			ans += a[i].ca;
			q.push(a[i].cb - a[i].ca);
		}
	}
}
void dfs(int ca, int cb, int cc, int np, int sum) {
	
	if(np > n) {
		ans = max(ans, sum);
		return;
	}
	if(ca < n / 2) dfs(ca + 1, cb, cc, np + 1, sum + a[np].ca);
	if(cb < n / 2) dfs(ca, cb + 1, cc, np + 1, sum + a[np].cb);
	if(cc < n / 2) dfs(ca, cb, cc + 1, np + 1, sum + a[np].cc);
}
void solve() {
	ans = 0;
	cin >> n;
	bool CA = true, CB = true;
	for(int i = 1; i <= n; i++) {
		cin >> a[i].ca >> a[i].cb >> a[i].cc;
		if(a[i].cb != 0) CA = false;
		if(a[i].cc != 0) CB = false, CA = false;
	}
	if(CA) {
		A();
	}
	if(CB) {
		B();
	}
	else {
		dfs(0, 0, 0, 1, 0);
	}
	
	cout << ans << "\n";
	
}
signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	cin >> T;
	while(T--) solve();
	
	return 0;
} 

/*
CCF, please, give me 1=, em¡­¡­ 180 pts is okay. It is important
because I need S1= to go to my favourite school. If you give me
1=, I will orz you forever.
*/
