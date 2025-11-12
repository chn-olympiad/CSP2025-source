#include<bits/stdc++.h>
using namespace std;
int n,k,a[500001],dp[500001],ma=INT_MIN;
int dg(int l){
	dp[l]=a[l];
	if(a[l]==k)return dg(l+1)+1;
	for(int i=l+1;i<=n;i++){
		dp[i]=a[i]^dp[i-1];
		if(dp[i]==k){
			return dg(i+1)+1;
		}
	}
	return 0;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		ma=max(dg(i),ma);
	}
	cout<<ma;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
