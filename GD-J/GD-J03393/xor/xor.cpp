#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[11451415],h1[11451415],h2[11451415],w,l[11451415],dp[11451415];
main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	h1[0]=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		h2[i]=(h2[i-1]^a[i]);
		l[i]=h1[h2[i]^m];
		h1[h2[i]]=i+1;
	}
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1];
		if(l[i])dp[i]=max(dp[i],dp[l[i]-1]+1);
	}
	cout<<dp[n];
} 
