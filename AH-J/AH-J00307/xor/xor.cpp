#include<bits/stdc++.h>
using namespace std; 
int dp[500005];
int a[500005];
int s[500005];
int dp1[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout); 
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dp1[0]=0;
	for(int i=1;i<=n;i++){
	    s[i]=s[i-1]^s[i];
	}
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1];
		if((s[i]^k)>=0 ||dp1[s[i]^k]==0){
		    dp[i]=max(dp[i],dp[dp1[s[i]]^k]+1);  
		}
		dp1[s[i]]=i; 
	} 
	cout<<dp[n];
    return 0;
}
