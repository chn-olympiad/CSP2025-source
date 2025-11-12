#include<bits/stdc++.h>
using namespace std;
int yzh,n,m,a[500005],dp[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i],a[i]=(a[i]^a[i-1]);
	for(int i=1;i<=n;i++){
		int mx=dp[0];
		for(int j=1;j<=i;j++){
			if((a[i]^a[j-1])==m) dp[i]=max(dp[i],mx+1);
			mx=max(mx,dp[j]);
		}
	}
	for(int i=1;i<=n;i++) yzh=max(yzh,dp[i]);
	cout<<yzh;
	return 0;
}
