#include <bits/stdc++.h>
#include <vector>
#define Long long long
#define NL 500001
using namespace std;

int n;
Long k,tmp;
Long arr[NL];
int dp[NL];

int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %lld",&n,&k);
	for (int i=1;i<=n;i++) {
		scanf("%lld",arr+i);
	}
	for (int i=1;i<=n;i++) {
		tmp = 0;
		dp[i] = dp[i-1];
		for (int j=i;j>0;j--) {
			tmp = tmp xor arr[j];
			if (tmp == k) dp[i] = max(dp[i],dp[j-1]+1);
		}
	}
	printf("%d",dp[n]);
	
	return 0;
}
