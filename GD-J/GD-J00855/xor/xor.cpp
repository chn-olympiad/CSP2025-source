#include<bits/stdc++.h>
using namespace std;
int n,k,a[500001],dp[500001],ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	dp[1]=a[1];
	for(int i=2;i<=n;i++){
		if(dp[i-1]==k)ans++;
		dp[i]=max(a[i],dp[i-1]^a[i]);
		if(dp[i]>k*2)dp[i]=a[i];
		if(a[i]==k)dp[i]=a[i];
	}
	cout<<ans;
	return 0;
}
