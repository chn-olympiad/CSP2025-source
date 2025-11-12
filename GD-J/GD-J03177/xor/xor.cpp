#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005],xo[500005],dp[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		xo[i]=xo[i-1]^a[i];
	}
	dp[0]=0;
	xo[0]=0;
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1];
		if(a[i]==k){
			dp[i]+=1;
			continue;
		}
		for(int j=i;j>=1;j--){
			int mm=xo[i]^xo[j];
			if(mm==k){
				dp[i]=max(dp[i],dp[j]+1);
				break;
			}
		}
	}
	cout<<dp[n];
	return 0;
}
