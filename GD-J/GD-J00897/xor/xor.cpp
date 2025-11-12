#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 10,maxv = (1 << 20) + 10;
int dp[maxn];
int lst[maxv];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	scanf("%d%d",&n,&k);
	int x = 0;
	memset(lst,-1,sizeof(lst));
	lst[0] = 0;
	for(int i = 1;i <= n;i++){
		int a;
		scanf("%d",&a);
		x ^= a;
		dp[i] = dp[i-1];
		if(lst[x^k] != -1)dp[i] = max(dp[i],dp[lst[x^k]] + 1);
		lst[x] = i;
	}
	printf("%d",dp[n]);
}
