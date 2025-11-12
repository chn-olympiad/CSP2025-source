#include<bits/stdc++.h>
#define int long long
using namespace std;
const int p = 998244353;
int n, a[5005], ans;
bool A=1;
int poww(int x, int y) {
	if (y == 1) return x%p;
	int z = poww(x,y/2)%p;
	if (y & 1) return z*z%p*x%p;
	else return z*z%p;
}
signed main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] != 1) A = 0;
	}
	if (A) {
		cout << poww(2,n)-n-n*(n-1)/2;
		return 0; 
	}
	for (int i = 1; i <= (1<<n); i++) {
		int ii = i;
		int s = 0, m = 0, j = 0, cnt=0;
		while (ii) {
			if (ii & 1) {
				s += a[j];
				m = max(m, a[j]);
				cnt++;
			}
			ii = ii >> 1;
			j++;
		}
		if (cnt >= 3 && s > 2*m) ans = (ans+1)%998244353;
	}
	cout << ans;
	return 0;
}

