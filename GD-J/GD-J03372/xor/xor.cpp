#include<bits/stdc++.h>
using namespace std;
int pre[500005],dp[500005];
int n,k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0); 
	cin>>n>>k;
	dp[0]=0;
	for(int i=1;i<=n;i++){
		cin>>pre[i];
		pre[i]^=pre[i-1];
		
	}
	for(int i=1;i<=n;i++){
		int lst=-1;
		for(int j=i-1;j>=0;j--){
			if((pre[i]^pre[j])==k){
				lst=j;
				break;
			}
			if(pre[i]==pre[j]){
				break;
			}
		}
		if(lst!=-1){
			dp[i]=max(dp[i-1],dp[lst]+1);
		}else{
			dp[i]=dp[i-1];
		}
	}
	cout<<dp[n];
	return 0;
}
