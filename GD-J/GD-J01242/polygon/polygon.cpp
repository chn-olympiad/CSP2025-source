#include<bits/stdc++.h>
using namespace std;
int a[5005],maxa[5005],sum[5005],dp[5005];
const int Mod=998244353;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxa[i]=max(maxa[i-1],a[i]);
		sum[i]=sum[i-1]+a[i];
	}
	
	for(int i=3;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i>j)continue;//i=4,j=4
			int l=sum[j]-sum[j-i-1];
			if(i==j&&sum[j]>maxa[j]*2){
				//cout<<i<<" "<<j<<" "<<sum[j]<<" "<<maxa[j]*2<<"\n";
				dp[i]=(dp[i]+1)%Mod;
			}
			for(int k=1;k<=j-1;k++){
				if(l-a[k]>maxa[j]*2){
				//	cout<<i<<" "<<j<<" "<<l-a[k]<<" "<<maxa[j]*2<<"\n";
					dp[i]=(dp[i]+1)%Mod;
				}
			}
		}
	}
	int b_ans=0;
	for(int i=3;i<=n;i++){
		b_ans+=dp[i];
		b_ans%Mod;
	}
	cout<<b_ans;
	return 0;
} 
