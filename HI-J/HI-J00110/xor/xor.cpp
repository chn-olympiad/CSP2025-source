#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int const N = 5E5 + 5;
ll n, k, a[N], xr[N], f[N];

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> a[i], xr[i] = xr[i - 1] ^ a[i];
	
	ll ans = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < i; j++) {
			if((xr[i] ^ xr[j]) == k) {
				f[i] = max(f[i], f[j] + 1);
			}else f[i] = max(f[i], f[j]);
		}
		ans = max(ans, f[i]);
	}
	cout << ans;
	
	return 0;
}

