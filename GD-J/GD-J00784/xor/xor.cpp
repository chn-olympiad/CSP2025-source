#include<bits/stdc++.h>
using namespace std;
void fuck(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	return;
}
int n,k,a[1145140],dp[1145140],i,j;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	fuck();
	cin>>n>>k;
	for(i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k)dp[i]=1;
	}
	for(i=1;i<=n;i++){
		int k1=a[i];
		dp[i]=dp[i-1]+dp[i];
		for(j=i-1;j>=1;j--){
			k1=k1^a[j];
			if(k1==k){
				dp[i]=max(1+dp[j-1],dp[i]);
			}
		}
	}
	cout<<dp[n];
	return 0;
}
