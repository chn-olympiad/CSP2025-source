#include<bits/stdc++.h>
#define pii pair < int, int >
#define ll long long
using namespace std;

const int N = 5e3 + 10, Mod = 998244353;
int n;
int a[N];
ll ans;

void dfs(int k, int id, int sum, int Max) {
	if ( k >= 3 ) {
		if ( sum > Max * 2 ) {
			ans++;
			ans %= Mod;
		}
	}
	for ( int i = id + 1; i <= n; i++ ) {
		dfs(k + 1, i, sum + a[i], max(a[i], Max));
	}
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for ( int i = 1; i <= n; i++ ) cin >> a[i];
	for ( int i = 1; i <= n; i++ ) dfs(1, i, a[i], a[i]);
	cout << ans;
	return 0;
}
