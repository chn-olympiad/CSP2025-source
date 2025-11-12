#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int W = 1e5 + 5;
ll n, a[W][4], v[5], ans, a1[W], sum;
void dfs(int x, ll sum){
	if (x == n + 1){
		ans = max(ans, sum);
		return ;
	}
	for (int i = 1; i <= 3; i++){
		if (v[i] + 1 > n / 2){
			continue;
		}
		v[i]++;
		dfs(x + 1, sum + 1ll * a[x][i]);
		v[i]--;
	}
}
bool cmp (ll x, ll y){
	return x > y;
}
int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	cin >> T;
	while (T--){
		cin >> n;
		ans = sum = 0;
		for (int i = 1; i <= n; i++){
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			a1[i] = a[i][1];
			if (a[i][2] == 0 ){
				sum++;
			}
			if (a[i][3] == 0){
				sum++;
			}
		}
		if (sum == n * 2){
			sort(a1 + 1, a1 + n + 1, cmp);
			for (int i = 1; i <= n / 2; i++){
				ans += a1[i];
			}
			cout << ans << '\n';
			continue;
		}
		fill(v, v + 5, 0);
		dfs(1, 0);
		cout << ans << '\n';
	}
	return 0;
}
