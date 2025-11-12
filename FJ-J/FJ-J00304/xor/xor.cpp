#include<bits/stdc++.h>
using namespace std;
int n,dp[1000005],sum[10000005],a[1000005],k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
	    cin>>a[i];
	    a[i]=a[i]^a[i-1];
	}
	memset(sum,-0x7f,sizeof(sum));
	sum[0]=0;
	for(int i=1;i<=n;i++){
		dp[i]=max(dp[i-1],sum[a[i]^k]+1);
		sum[a[i]]=max(dp[i],sum[a[i]]);
	}
	cout<<dp[n];
}
