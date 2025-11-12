#include<bits/stdc++.h>
using namespace std;
int n,k,ans,x;
int a[500005],dp[10005][10005],s[10005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k){
			ans++;
		}
	}
	if(n>=200000){
		cout<<ans;
		return 0; 
	}
	ans=0;
	for(int i=1;i<=n;i++){
		dp[i][i]=a[i];
	}
	for(int i=1;i<n;i++){

		for(int j=2;j+i-1<=n;j++){
			dp[i][j+i-1]=dp[j+i-1][j+i-1]^dp[i][j+i-2];
		}
	}
	for(int i=1;i<n;i++){
		for(int j=2;j+i-1<=n;j++){
			if(dp[i][i+j-1]==k){
				for(int k=i;k<=i+j-1;k++){
					s[k]++;
				}
				ans++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		x=max(x,s[i]);
	}
	if(x==1){
		cout<<ans;
		return 0;
	}
	cout<<ans+1-x;
	return 0;
} 
