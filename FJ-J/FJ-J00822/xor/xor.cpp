#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k;
int a[500005];
int s[500005];
int dp[500005];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1];
		for(int j=i;j>=1;j--){
			int ss=s[i]^s[j-1];
			if(ss==k){
				if(dp[i]>=dp[j-1]+1){
					dp[i]=dp[i];
				}
				else {
					dp[i]=max(dp[i],dp[j-1]+1);
					break;
				}
			}
		}
	}
	int ma=0;
	for(int i=1;i<=n;i++){
		ma=max(ma,dp[i]);
	}
	cout<<ma;
	return 0;
}
