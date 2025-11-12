#include<bits/stdc++.h>
using namespace std;
int a[600000];
int dp[600000];
int qzyhh[600000];
int yh(int a,int b){
	int ans=0;
	int now=1;
	while(a!=0 or b!=0){
		if(a%2!=b%2){
			ans+=now;
		}
		now*=2;
		a/=2;
		b/=2;
	}
	return ans;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	qzyhh[1]=a[1];
	for(int i=2;i<=n;i++){
		qzyhh[i]=yh(a[i],qzyhh[i-1]);
	}
	if(a[1]==k){
		dp[1]=1;
	}
	else{
		dp[1]=0;
	}
	for(int i=2;i<=n;i++){
		dp[i]=dp[i-1];
		for(int j=i;j>=1;j--){
			if(yh(qzyhh[i],qzyhh[j-1])==k){
				dp[i]=max(dp[i],dp[j-1]+1);
			}
		}
	}
	cout<<dp[n];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
