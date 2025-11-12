#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010],dp[500010],sum[500010],ans;
bool flag;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1)flag=1;
		sum[i]=sum[i-1]^a[i];
	}
	if(!flag){
		if(!k){
			for(int i=1;i<=n;i++){
				if(!a[i])ans++;
				if(a[i]&&a[i+1]){
					ans++;
					i++;
				}
			}
		}
		else {
			for(int i=1;i<=n;i++){
				if(a[i])ans++;
			}
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1];
		for(int j=i-1;j>=0;j--){
			if((sum[i]^sum[j])==k){
				dp[i]=max(dp[i],dp[j]+1);
				break;
			}
		}
	}
	cout<<dp[n];
	return 0;
} 
