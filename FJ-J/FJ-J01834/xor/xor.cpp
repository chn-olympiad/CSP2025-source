#include <bits/stdc++.h>
using namespace std;

int n,k;
int nums[500000]={};
int dp[500001]={};

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>nums[i];
	}
	for(int i=1;i<=n;i++){
		int flag=-1;
		int count=nums[i-1];
		if(count==k){
			dp[i]=dp[i-1]+1;
			continue;
		}
		int j;
		for(j=i-2;j>=0;j--){
			count^=nums[j];
			if(count==k){
				flag=j;
				break;
			}
		}
		if(j!=-1){
			dp[i]=max(dp[j]+1,dp[i-1]);
		}else{
			dp[i]=dp[i-1];
		}
	}
	cout<<dp[n];
	return 0;
}
