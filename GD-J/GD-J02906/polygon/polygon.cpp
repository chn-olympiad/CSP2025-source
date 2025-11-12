#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;
int n,a[500006],f[500006][4],ans;
signed main(){
	freopen("polygon.in","r",stdin); 
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n; i++)
		cin >> a[i];
	sort(a+1,a+1+n);
	f[0][0] = 1;
	for(int i = 1;i <= n; i++){
		for(int j = (int)10001;j > a[i]; j--)
			ans = (ans+f[j][3]+f[j][2])%mod;
		for(int j = (int)10001;j >= 0; j--)
			for(int k = 1;k <= 3; k++)
				f[min(j+a[i],(int)10001)][k] = (f[j][k-1]+(k == 3?f[j][k]:0)+f[min(j+a[i],(int)10001)][k])%mod;

	}
	cout << ans;
	return 0;
}
