#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int P = 998244353;
int n,ans,a[5005],dp[25000005][4];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	dp[0][0] = 1;
	for(int i = 1;i <= n;i++){
		for(int j = 50000;j >= a[i];j--){
			for(int k = 1;k <= 3;k++){
				dp[j][k] = (dp[j][k] + dp[j-a[i]][k-1]) % P;
				if(k == 3 && j > 2 * a[i]){
					ans = (ans + dp[j-a[i]][2]) % P;
				}
			}
			dp[j][3] = (dp[j][3] + dp[j-a[i]][3]) % P;
			if(j > 2 * a[i]) ans = (ans + dp[j-a[i]][3]) % P;
		}
	}
	printf("%d",ans);
	return 0;
}
