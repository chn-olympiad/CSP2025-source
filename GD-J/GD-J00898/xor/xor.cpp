//2024tysc0092 
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k,a[500005],dp[500005];
map<int,int> mp;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	mp[0]=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]^=a[i-1];
		dp[i]=dp[i-1];
		if(mp[a[i]^k]){
			dp[i]=max(dp[i],dp[mp[a[i]^k]-1]+1);
		}
		mp[a[i]]=i+1;
	}
	cout<<dp[n];
	return 0;
}
/*
dpÅ£±Æ 
*/
