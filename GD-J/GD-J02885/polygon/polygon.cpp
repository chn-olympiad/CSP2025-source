#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e3 + 5,mod = 998244353;

int n,maxn;
int a[N];
int f[N][N][4];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> n;
	for (int i = 1;i <= n;i++) cin >> a[i];
	sort(a + 1,a + 1 + n);reverse(a + 1,a + 1 + n);
	maxn = a[1] + 1;f[n + 1][0][0] = 1;
	for (int i = n + 1;i >= 2;i--){
		for (int j = 0;j <= maxn;j++) for (int k = 0;k <= 3;k++) f[i - 1][j][k] = f[i][j][k];
		for (int j = 0;j <= maxn;j++) for (int k = 0;k <= 3;k++) if (f[i][j][k]) (f[i - 1][min(j + a[i - 1],maxn)][min(3ll,k + 1)] += f[i][j][k]) %= mod;
	}int ans = 0;
	for (int i = 1;i <= n;i++) for (int j = a[i] + 1;j <= maxn;j++) (ans += f[i + 1][j][2] + f[i + 1][j][3]) %= mod;
	cout << ans << "\n";
	return 0;
}
