#include<bits/stdc++.h>
#define rint register int
#define LL long long
using namespace std;
const int N=5e5+5,M=3e6+5;
int n,k;
int sum,a,dp[N],bz[M];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	memset(bz,-1,sizeof(bz)),bz[0]=0;
	cin>>n>>k;
	for(rint i=1;i<=n;++i){
		cin>>a,sum^=a;
		dp[i]=dp[i-1];
		if(bz[sum^k]!=-1) dp[i]=max(dp[i],dp[bz[sum^k]]+1);
		bz[sum]=i;
	}
	cout<<dp[n];
	return 0;
} 
