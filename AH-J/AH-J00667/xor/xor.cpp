#include<bits/stdc++.h>
using namespace std;
int a[500005];
int s[500005];
int dp[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
        cin>>a[i];
	}
	for(int i=1;i<=n;i++){
        s[i]=(s[i-1]^a[i]);
	}
	int ans=0,cnt=0;
	for(int i=1;i<=n;i++){
        dp[i]=dp[i-1];
        if(a[i]==k){
            dp[i]=dp[i-1]+1;
            continue;
        }
        for(int j=1;j<=i;j++){
            if((s[i]^s[j-1])==k){
               dp[i]=max(dp[i],dp[j-1]+1);
            }
        }
	}
	cout<<dp[n];
	return 0;
}
