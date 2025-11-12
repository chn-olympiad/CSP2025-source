#include <bits/stdc++.h>
using namespace std;
long long n,a[5005],mod = 998244353,ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i++)
		cin >> a[i];
	sort(a + 1,a + n + 1);
	for (int i = n;i >= 3;i--){
		int now = a[i],checknow;
		int checknum = pow(2,i - 1);
		for (int c = 3;c <= checknum;c++){
			int jj = 0;
			for (int j = 1;j <= checknum;j<<1){
				jj++;
				if (j & c)
					checknow += a[jj];
			}
			if (checknow > now)
				ans = ++ans % mod;
		}
	}
	cout << ans;
	return 0;
}
