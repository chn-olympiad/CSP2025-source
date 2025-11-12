#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k;
ll a[500015],x[500015];
ll dp[500015];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		x[i]=a[i]^x[i-1];
	}
	dp[0]=0;
	dp[1]=(a[1]==k?1:0);
	for(int i=2;i<=n;i++){
		dp[i]=dp[i-1];
		if(a[i]==k) dp[i]++;
		for(int j=i-1;j>=2;j--){
			if(x[i]^x[j-1]==k){
				dp[i]=max(dp[i],dp[j-1]+1);
			} 
		}
	}
	cout<<dp[n];
	return 0;
}

