#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],dp[500005][10],q[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		q[i]=q[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
		for(int j=i-1;j>=0;j--)
			if((q[i]^q[j])==k){
				dp[i][1]=max(dp[i][1],dp[j+1][0]+1);
				break;
			}
	}
	cout<<max(dp[n][0],dp[n][1]);
	return 0;
}
