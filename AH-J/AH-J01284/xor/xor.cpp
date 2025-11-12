#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],s[500005],ans,dp[500005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	s[1]=a[1];
	for(int i=2;i<=n;i++){
		s[i]=s[i-1]^a[i];
	}
	for(int i=n;i>=1;i--){
		for(int j=i;j<=n;j++){
			if((s[j]^s[i-1])==k){
				dp[i]=max(dp[i],dp[j+1]+1);
			}
			else{
				dp[i]=max(dp[i],dp[j+1]);
			}
		}
		ans=max(ans,dp[i]);
	}
	cout<<ans;
	return 0;
}
