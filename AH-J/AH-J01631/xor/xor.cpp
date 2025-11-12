#include<bits/stdc++.h>
using namespace std;
int n,k,dp[500005],sum[500005],a[500005],mx[500005];
int mp[3000004];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=(sum[i-1]^a[i]);
	}
	mp[0]=1;
	for(int i=1;i<=n;i++){
		dp[i]=mp[sum[i]^k];
		mx[i]=max(mx[i-1],dp[i]);
		mp[sum[i]]=max(mp[sum[i]],mx[i]+1);
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		ans=max(ans,dp[i]);
	}cout<<ans<<"\n";
	return 0;
}
