#include<bits/stdc++.h>
using namespace std;int a,k,i,b,c,d[1048600],dp[500001];
main(){
	freopen("xor.in","r",stdin);freopen("xor.out","w",stdout);
	scanf("%d%d",&a,&k);memset(d,-1,sizeof(d));
	d[0]=0;for(i=1;i<=a;i++){
		scanf("%d",&c);b^=c;dp[i]=dp[i-1];
		if(d[b^k]>=0)dp[i]=max(dp[i],dp[d[b^k]]+1);
		d[b]=i;
	}printf("%d",dp[a]);
}
