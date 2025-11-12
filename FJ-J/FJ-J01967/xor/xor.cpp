# include<bits/stdc++.h>
# define N 500005
using namespace std;
int n, k, a[N];
map<int, int> q;
int now, ans;
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin.tie(0) -> ios :: sync_with_stdio(false);
	cin >> n >> k;
	for(int i = 1; i <= n; i ++)
		cin >> a[i];
	q[0] = 1;
	for(int i = 1; i <= n; i ++) {
		now ^= a[i];
		if(q[now ^ k])
			q.clear(), now = 0, ans ++;
		q[now] ++;
	}
	cout << ans << "\n";
	return 0;
}