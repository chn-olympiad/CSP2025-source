#include<bits/stdc++.h>
using namespace std;
long long n,k,l,a[500001],dp[500001];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;	
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
	}for(int i=1;i<=n;i++){
		dp[i]=dp[i-1];
		if(a[i]==k){
			dp[i]=dp[i-1]+1;
			continue;
		}int sum=a[i];
		for(int j=i-1;j>=1;j--){
			sum^=a[j];
			if(sum==k) {dp[i]=max(dp[j-1]+1,dp[i]);break;}
		}
	}cout<<dp[n];
}

