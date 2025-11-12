#include<algorithm>
#include<iostream>
#define ll long long
using namespace std;
const ll N = 1e5 + 1;
ll T, n, Ans = -1, a[N][4];
ll sub2[N];
void dfs(ll id, ll cho, ll na, ll nb, ll nc, ll ans) {
	if(id == n) {
		Ans = max(Ans, ans);
		return;
	}
	if(na < n / 2) dfs(id + 1, 1, na + 1, nb, nc, ans + a[id + 1][1]);
	if(nb < n / 2) dfs(id + 1, 2, na, nb + 1, nc, ans + a[id + 1][2]);
	if(nc < n / 2) dfs(id + 1, 3, na, nb, nc + 1, ans + a[id + 1][3]);
	return;
}
void Subtask1() {
	dfs(1, 1, 1, 0, 0, a[1][1]);
	dfs(1, 2, 0, 1, 0, a[1][2]);
	dfs(1, 3, 0, 0, 1, a[1][3]);
	cout << Ans << "\n";
	return;
}
bool cmp(ll a, ll b) { return a > b; }
void Subtask2() {
	Ans = 0;
	for(int i = 1; i <= n; ++ i) sub2[i] = a[i][1];
	sort(sub2 + 1, sub2 + n + 1, cmp);
	for(int i = 1; i <= n / 2; ++ i) Ans += sub2[i];
	cout << Ans << "\n";
	return;
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> T;
	while(T --) {
		cin >> n;
		bool fa = 1;
		for(int i = 1; i <= n; ++ i) {
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			if(a[i][2] != 0  || a[i][3] != 0) fa = 0;
		}
		Ans = -1;
		if(n <= 10) Subtask1();
		else if(fa == 1) Subtask2();
	}
	return 0;
}
