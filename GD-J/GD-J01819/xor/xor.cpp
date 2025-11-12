#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,k,a[N],ans,dp[N],sum[N],b[N<<2];
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i],sum[i]=sum[i-1]^a[i];
	for(int i=1;i<=n;i++){
		int x=a[i]^k,y=sum[i-1]^x;
//		if(b[y]!=0) cout<<i<<' '<<b[y]<<'\n';
		dp[i]=dp[i-1];
		if(a[i]==k||b[y]!=0) dp[i]=max(dp[i],dp[b[y]]+1);
		b[sum[i]]=i;
		ans=max(dp[i],ans);
	}
	cout<<ans;
	return 0;
}
