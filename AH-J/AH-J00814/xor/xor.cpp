#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,k;
ll a[500005];
ll dp[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>k;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		a[i]^=a[i-1];
	}
	dp[0]=0;
	for(int i=1;i<=n;i++) {
		dp[i]=dp[i-1];
		for(int j=0;j<i;j++) 
			if((a[i]^a[j])==k) 
				dp[i]=max(dp[i],dp[j]+1);
	}
	cout<<dp[n]<<endl;
	return 0;
}
