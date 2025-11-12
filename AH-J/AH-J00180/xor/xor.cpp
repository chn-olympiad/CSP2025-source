#include <bits/stdc++.h>
using namespace std;
//#define int long long
int n,k,dp[500005],t[2000000],a[500005],o[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
			cin>>a[i];
			o[i]=a[i]^o[i-1];
	}
	for(int i=1;i<=n;i++){
		if(o[i]==k)dp[i]=1;
		dp[i]=max(dp[i-1],dp[i]);
		if(t[k^o[i]]){
			dp[i]=max(dp[i],dp[t[k^o[i]]]+1);
		}
		t[o[i]]=i;
	}
	cout<<dp[n];
	return 0;
}
