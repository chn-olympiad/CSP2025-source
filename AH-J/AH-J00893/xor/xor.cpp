#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
int b[500005];
int ans=0;
int dp[500005];
int main(){
freopen ("xor.in","r",stdin);
freopen ("xor.out","w",stdout);
ios::sync_with_stdio(0);
cin>>n>>k;
for (int i=1;i<=n;i++){
	cin>>a[i];
	b[i]=a[i]^b[i-1];
}
int cnt=1;
for (int i=1;i<=n;i++){
	dp[i]=dp[i-1];
	for (int j=cnt;j<=i;j++){
		if (dp[j-1]<dp[i])continue;
		int v=b[i]^b[j-1];
		if (v==k){
			//dp[i]=max(dp[i],dp[j-1]+1);
			if (dp[i]<dp[j-1]+1)
			dp[i]=dp[j-1]+1,cnt=j;
		}
	}
}
//for (int i=1;i<=n;i++)cout<<dp[i]<<" ";
//cout<<endl;
    cout<<dp[n]<<endl;
	return 0;
}
/*
for (int i=1;i<=n;i++){
	dp[i]=dp[i-1];
	
}
}
* */
