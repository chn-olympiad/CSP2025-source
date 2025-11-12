#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500050],n,k,qz[500050],dp[5000050],g1,g0;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1) g1++;
		if(a[i]==0) g0++;
		qz[i]=qz[i-1]^a[i];
	}
//	dp[1][1]=(int)(a[1]==k);
//	
//	cout<<dp[1][n];
	if(g1+g0==n&&k==1){
		cout<<g1;
		return 0;
	}
	if(g1+g0==n&&k==0){
		cout<<g0;
		return 0;
	}
	if(g1+g0==n&&k!=1&&k!=0){
		cout<<0;
		return 0;
	}
	dp[1]=(int)(a[1]==k);
	//cout<<dp[1]<<" ";
	for(int i=2;i<=n;i++){
		for(int j=0;j<=i-1;j++){
			if((qz[i]^qz[i-j-1])==k) dp[i]=max(dp[i],dp[i-j]+1);
			else dp[i]=max(dp[i],dp[i-j]);
		}
		//cout<<dp[i]<<" ";
	}
	//cout<<endl;
	cout<<dp[n];
	return 0;
}