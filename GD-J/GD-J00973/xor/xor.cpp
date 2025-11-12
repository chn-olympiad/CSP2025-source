#include<bits/stdc++.h>
using namespace std;
int lst[1050000],dp[500005];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a=0;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		int t;scanf("%d",&t);dp[i]=dp[i-1];
		a^=t;t=a^k;
		if(lst[t]||a==k) dp[i]=max(dp[i],dp[lst[t]]+1);
		lst[a]=i;
	}
	cout<<dp[n];
	return 0;
}
//	freopen("xor.in","r",stdin);
//	freopen("xor.out","w",stdout);
//刚刚，你不会被吓到了吧？（笑） 
