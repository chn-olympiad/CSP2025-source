#include<iostream>
#include<algorithm>

using namespace std;

const int N = 5e3 + 10, M = N*2, V = 1e4, mod = 998244353;
int n, a[N], f[M], ans = 0;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n; f[0] = 1;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	for(int i = 1; i <= n; i++){
		for(int j = V; j > a[i]; j--) ans = (ans + f[j]) % mod;
		for(int j = V; j > V-a[i]; j--) f[V] = (f[V] + f[j]) % mod;
		for(int j = V; j >= a[i]; j--) f[j] = (f[j] + f[j-a[i]]) % mod;
	}
	cout << ans;
	return 0;
}
