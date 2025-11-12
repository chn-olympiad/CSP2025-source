#include<bits/stdc++.h>
using namespace std;
const int N = 5010,P=998244353;
int n;
int a[N],dp[N*2],blk,amax,ret;
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for (int i = 1; i <= n; i++) {
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	amax = a[n];
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		ret = (ret + blk) % P;
		blk = (blk * 2) % P;
		for (int j = amax*2; j >= 0; j--) {
			if (j+a[i] > amax*2) {
				blk += dp[j];
				ret = (ret + dp[j]) % P;
				blk %= P;
			} else {
				dp[j+a[i]] += dp[j];
				if (j+a[i] > a[i]*2) ret = (ret + dp[j]) % P;
				dp[j+a[i]] %= P;
			}
		}
	}
	printf("%d\n",ret);
}
