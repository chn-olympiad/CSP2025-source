#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
int a[maxn],n,k;
int dp[maxn],lst[1100005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;++i) scanf("%d",a+i);
	int sum=0;
	for(int i=1;i<=1100000;++i) lst[i]=-1;
	lst[0]=0;
	for(int i=1;i<=n;++i){
		sum^=a[i];
		if(lst[sum^k]!=-1) dp[i]=max(dp[lst[sum^k]]+1,dp[i-1]);
		else dp[i]=dp[i-1];
		lst[sum]=i;
	}
	printf("%d",dp[n]);
	return 0;
}
