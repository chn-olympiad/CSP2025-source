#include<bits/stdc++.h>

using namespace std;
#define int long long

const int MOD = 998244353;
const int maxn = 5e3 + 10;
int a[maxn],dp[maxn][maxn];

signed main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,tmp = 0,maxx = 0;
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i],tmp += a[i],maxx = max(maxx,a[i]);
	if(n == 3) {
		if(tmp > maxx * 2) cout << 1;
		else cout << 0;
		return 0;
	}
	return 0;
}

