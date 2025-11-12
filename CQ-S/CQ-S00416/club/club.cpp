#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e6 + 5;
int n;
struct node{
	int f1, f2, f3;
}a[maxn];
ll ans = 0, ans1;
bool cmp(node r, node l) {
	return r.f1 > l.f1;
}
void AAA() {
	sort(a + 1, a  + 1 + n, cmp);
	ll dd = 0;
	for (int i = 1; i <= n / 2; i++) dd += a[i].f1;
	cout << dd << endl;
}
void dfs(int now, ll sum, int x, int y, int z) {
	if(now > n) {
		ans = max(ans, sum);
		return ;
	}
	if(x < n / 2) dfs(now + 1, a[now].f1 + sum, x + 1, y, z);
	if(y < n / 2) dfs(now + 1, a[now].f2 + sum, x, y + 1, z);
	if(z < n / 2) dfs(now + 1, a[now].f3 + sum, x, y, z + 1);
}
void solve() {
	cin >> n;
	bool f = true;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].f1 >> a[i].f2 >> a[i].f3;
		if(a[i].f2 != 0 || a[i].f3 != 0) f = false;
	}
	if(f) {
		AAA();
	}
	else if(n < 20) {
		ans = 0, ans1 = 0;
		dfs(1, 0, 0, 0, 0);
		cout << ans << endl;
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	cin >> T;
	while(T--) solve();
	return 0;
} 
