#include<bits/stdc++.h>
#define int long long
#define fo(i, a, b) for(int i = a; i <= b; i ++)

using namespace std;

const int Mod = 998244353, N = 2e5 + 5;

int n;

int a[N], Max;

int f[N << 1], h[N << 1];
void solve() {
	f[0] = 1;
	int ans = 0;
	fo(i, 1, n) {
//		f[0] = 1;
//		f[a[i]] = 1;
		fo(j, 0, Max * 2 + 1)
		(h[min(Max * 2 + 1, j + a[i])] += f[j]) %= Mod;
//		fo(j, 0, Max * 2 + 1) {
//			cout << f[j] << " ";
//		}
//		cout << "\n";
//		fo(j, 0, Max * 2 + 1) {
//			cout << h[j] << " ";
//		}
//		cout << "\n";
		fo(j, a[i] * 2 + 1, Max * 2 + 1)
		(ans += h[j]) %= Mod;
		fo(j, 0, Max * 2 + 1)
		(f[j] += h[j]) %= Mod, h[j] = 0;
	}
	cout << ans << "\n";
	return; 
}

signed main() {
	
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);

	cin >> n;

	fo(i, 1, n)
		cin >> a[i];

	sort(a + 1, a + n + 1);
	Max = a[n];
//	cout << Max << "\n";

	solve();

	return 0;
}

