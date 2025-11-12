#include<bits/stdc++.h>
using namespace std;
int n,k,a[500001],p,q,dp[500001];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n ,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]==k)dp[i]=1;
		a[i]=(a[i]^a[i-1]);
	}
	for(int l=2;l<=n;l++){
		for(int i=1;i+l-1<=n;i++){
			int j=i+l-1;
			for(int z=i;z<=j-1;z++){
				p=0,q=0;
				if((a[z]^a[i-1])==k){
					p=1;
				}
				if((a[j]^a[z])==k){
					q=1;
				}
				dp[j]=max(dp[j],dp[i-1]+p+q);
				dp[j]=max(dp[j],dp[z]+q);
				dp[j]=max(dp[j],dp[j]-dp[z]+p);
			}
		}
	}
	cout<<dp[n];
	return 0;
}
