#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5231;
const int p = 998244353;

int n,a[N];
ll dp[N][N];

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i = 1;i <= n;i++)
		scanf("%d",&a[i]);
	sort(a + 1,a + n + 1);
	dp[0][0] = 1;
	for(int i = 0;i < n;i++)
		for(int j = 0;j <= 5001;j++){
			dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % p;
			dp[i + 1][min(5001,j + a[i + 1])] = (dp[i + 1][min(5001,j + a[i + 1])] + dp[i][j]) % p; 
		}
	ll ans = 0;
	for(int i = 3;i <= n;i++)
		for(int j = a[i] + 1;j <= 5001;j++)
			ans = (ans + dp[i - 1][j]) % p;
	printf("%lld\n",ans);
	return 0;
}
