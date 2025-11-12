#include<iostream>
#include<cstdio>
#include<algorithm>
#define ll long long 
using namespace std;
ll dp[500005],n,k,a[500005],sg[2000005];
int main(){
//	feropen(xor.in","r",stdin);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		dp[i]=dp[i-1];
		a[i]^=a[i-1];
//		cout<<a[i]<<' ';
		if(sg[a[i]^k]||((a[i]^k)==0))dp[i]=max(dp[i],dp[sg[a[i]^k]]+1);
		sg[a[i]]=i;
//		cout<<dp[i]<<endl;
	}
//	cout<<endl;
	printf("%lld",dp[n]);
	return 0;
}
