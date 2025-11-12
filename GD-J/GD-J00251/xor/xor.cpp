#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,k,s[500005],dp[500005],maxdp[1<<20];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	memset(maxdp,128,sizeof(maxdp));
	maxdp[0]=0;
	for(ll i=1;i<=n;i++){
		ll a;
		cin>>a;
		s[i]=s[i-1]^a;
		dp[i]=max(dp[i-1],maxdp[s[i]^k]+1);
		maxdp[s[i]]=max(maxdp[s[i]],dp[i]);
//		cout<<dp[i]<<' '<<s[i]<<'\n';
	}
	cout<<dp[n];
	return 0;
}
