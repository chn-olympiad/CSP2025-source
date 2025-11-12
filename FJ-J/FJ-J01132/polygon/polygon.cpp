#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mod = 998244353;

ll n,ans;
ll a[5011],f[5011][5011];

int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a + 1,a + n + 1);
	for(int i=1;i<=n;i++) {
		for(int j=0;j<=5000;j++) {
			f[i][j] = f[i - 1][j];
			if (a[i] > j)
				f[i][j] = (f[i][j] + f[i - 1][0] + 1ll) % mod;
			else
				f[i][j] = (f[i][j] + f[i - 1][j - a[i]]) % mod;
		}
	}
	for(int i=3;i<=n;i++) {
		for(int j=2;j<i;j++)
			ans = (ans + f[j - 1][a[i] - a[j]]) % mod;
	}
	printf("%lld",ans);
	return 0;
}
