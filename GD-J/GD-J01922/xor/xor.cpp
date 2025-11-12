#include<bits/stdc++.h>
using namespace std;
int n,s,k,a[500001],dp[500005],f[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>k;
	map<int,int>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]^=a[i-1];
		m[a[i-1]^k]=i;
		if(f[m[a[i]]]==0)f[m[a[i]]]=i;
	}
	for(int i=n;i>=1;i--){
		dp[i]=dp[i+1];
		if(f[i]!=0)dp[i]=max(dp[i],dp[f[i]+1]+1);
	}
	cout<<dp[1];
	return 0;
}
