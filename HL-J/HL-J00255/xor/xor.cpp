#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int n,k,ans=0;
int s[500005];
int dp[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		s[i]^=s[i-1];
	}
	dp[n+1]=0;
	for(int i=n;i>=1;i--){
		int l=i;
		int r=l;
		while(1){
			if(r>n){
				break;
			}
			else if((s[r]^s[l-1]) == k){
				dp[i]=max(dp[i],1+dp[r+1]);
				r++;
			}
			else{
				r++;
			}
		}
		dp[i]=max(dp[i],dp[i+1]);
	}
	cout<<dp[1];
	fclose(stdin);
	fclose(stdout);
	return 0;
}