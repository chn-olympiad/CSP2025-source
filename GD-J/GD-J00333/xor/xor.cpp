#include<bits/stdc++.h>
using namespace std;
const int N=1050000;
int n,k,dp[N],head[N],bz[N],sum;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	head[k]=0,bz[k]=1;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		sum=(sum^x),dp[i]=dp[i-1];
		if(bz[sum]) dp[i]=max(dp[i],dp[head[sum]]+1);
		head[(sum^k)]=i,bz[(sum^k)]=1;
	}cout<<dp[n];
	return 0;
}
