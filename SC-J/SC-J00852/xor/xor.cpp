#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int n,k,a[500005],dp[500005],s[500005];
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1];
		for(int j=i-1;j>=0;j--){
			if((s[i]^s[j])==k || dp[j]+1<=dp[i]){
				dp[i]=max(dp[i],dp[j]+1);
				break;
			}
		}
	}
	cout<<dp[n];
	return 0;
}