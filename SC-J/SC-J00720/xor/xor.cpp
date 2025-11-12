#include<bits/stdc++.h>
using namespace std;
const int N=5e5+3;
int n,a[N],re,s[2],bj=1,dp[N],sum=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>re;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(sum&&a[i]==1){
			s[0]++;
			sum=0;
		}
		else if(a[i]==1) sum=1;
		else sum=0;
		if(a[i]>1) bj=0;
		else s[a[i]]++;
		a[i]^=a[i-1];
	}
	sum=0;
	if(bj&&re<=1){
		if(re) cout<<s[1];
		else cout<<s[0]; 
	}
	else{
		for(int i=n;i;i--){
			int k=i;
			for( ;k<=n;k++){
				if((a[k]^a[i-1])==re){
					sum++;
					break;
				}
			}
			dp[i]=max(dp[i+1],dp[k+1]+sum);
			sum=0;
		}
		cout<<dp[1];
	}
	return 0;
}