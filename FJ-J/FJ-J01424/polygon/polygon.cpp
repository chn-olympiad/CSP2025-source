#include <iostream>
using namespace std;
int n;
int a[5003];
int vis[5003];
long long ans = 0;
const int mod = 998244353;
void f(int p,int c) {
	if (p > n) {
		if (c < 3)    return;
		int s = 0,maxn = 0;
		for (int i = 1; i <= c; i++) {
			s += a[vis[i]];
			maxn = max(maxn,a[vis[i]]);
		}
		if (s > maxn * 2)    ans = (ans + 1) % mod;
		return;
	}
	f(p + 1,c);
	vis[++c] = p;
	f(p + 1,c);
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	f(1,0);
	cout << ans;
	return 0;
}
