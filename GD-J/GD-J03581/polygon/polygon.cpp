#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,ans,cnt;
ll a[5005],f[5005][5005],f1[2][5000 * 5000 + 1];
void dfs (ll x,ll ma,ll sum) {
	if (x == n + 1) {
		if (sum > ma * 2)
			cnt = (cnt + 1) % 998244353;
		return;
	}
	dfs (x + 1,ma,sum);
	dfs (x + 1,max(ma,a[x]),sum + a[x]);
}

int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	ll maxd = 0;
	for (int i = 1; i <= n; i++) scanf("%lld",&a[i]),maxd = max(maxd,a[i]);
	if (n <= 20) {
		dfs (1,0,0);
		cout << cnt;
		return 0;
	}
	if (maxd <= 1) {
		for (int i = 1; i <= n; i++) {
			f[i][0] = 1;
			for (int j = 1; j <= n; j++) {
				if (i == j) f[i][j] = 1;
				else f[i][j] = (f[i][j] + f[i - 1][j - 1] + f[i - 1][j]) % 998244353;
			}
		}
		for (int i = 3; i <= n; i++)
			ans = (ans + f[n][i]) % 998244353;
		cout << ans;
		return 0;
	}
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 2 * a[i] + 1; j <= sum; j++)
			ans += f1[1][j] - f1[0][j],f1[0][j] = f1[1][j];
		sum += a[i];
		for (int j = sum; j > 3 * a[i]; j--)
			f1[1][j] += f1[0][j - a[i]];
	}
	printf("%d\n",sum);
	return 0;
}
