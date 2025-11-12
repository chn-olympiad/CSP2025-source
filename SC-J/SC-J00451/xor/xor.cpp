#include <bits/stdc++.h>
using namespace std;
int a[500005],dp[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	cin>>a[0];
	if(a[0]==k){
		dp[0]=1;
	}else{
		dp[0]=0;
	}
	for(int i=1;i<n;i++){
		cin>>a[i];
		int x=a[i];
		dp[i]=dp[i-1];
		if(a[i]==k){
			dp[i]=dp[i-1]+1;
			continue;
		}
		for(int j=i-1;j>=0;j--){
			x^=a[j];
			if(dp[j-1]<=dp[i]-2){
				break;
			}
			if(x==k){
				dp[i]=max(dp[i],dp[j-1]+1);
			}
		}
	}
	cout<<dp[n-1];
	return 0;
}