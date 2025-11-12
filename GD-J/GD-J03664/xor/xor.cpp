#include<bits/stdc++.h>
using namespace std;
long long ans,a[1000001],n,cnt,m,sum,dp[100001];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++){
		sum=0;
		for(long long j=i;j<=n;j++){
			cnt=a[i];
			for(long long k=i+1;k<=j;k++){
				cnt^=a[k];
			}
			if(cnt==m){
				sum++;
				dp[j]=sum+dp[j-1];
				i=j;
				break;
			}
			else dp[j]=max(dp[j],dp[j-1]);
		}
	}
	cout<<dp[n];
	return 0;
}
