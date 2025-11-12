#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],sum[500005],dp[500005],ans;
vector<int>s[2097153];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
		s[sum[i-1]].push_back(i-1);
	}
	if(n<=10000){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++){
				if((sum[i]^sum[j-1])==k){
					dp[i]=max(dp[i],dp[j-1]+1);
				}
				else dp[i]=max(dp[i],dp[j-1]);
			}
		}
		cout<<dp[n]<<"\n";
	}
	else{
		if(k==0){
			for(int i=1;i<=n;i++){
				if(sum[i]==k){
					dp[i]=1;
				}
				else{
					for(int j:s[sum[i]^k]){
						if(j>=i) break;
						if(j<i) dp[i]=max(dp[i],dp[j]+1);
					}
				}
				dp[i]=max(dp[i],dp[i-1]);
			}
			cout<<dp[n]<<"\n";
		}
		else{
			for(int i=1;i<=n;i++){
				if(sum[i]==k){
					dp[i]=1;
				}
				else{
					for(int j:s[sum[i]^k]){
						if(j>i) break;
						if(j<=i) dp[i]=max(dp[i],dp[j]+1);
					}
				}
				dp[i]=max(dp[i],dp[i-1]);
				//cout<<dp[i]<<" ";
			}
			cout<<dp[n]<<"\n";
		}
	}
	return 0;
}