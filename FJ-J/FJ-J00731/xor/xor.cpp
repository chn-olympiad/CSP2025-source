#include<bits/stdc++.h>
using namespace std;
#define int long long
int dp[520000],s[520000];
int yh(int x,int y){
	int a[22],b[22];
	for(int i=0;i<=22;i++){
		a[i]=0,b[i]=0;
	}
	int i=0,j=0;
	while(x>=1){
		a[i]=x%2;
		x/=2;
		i++;
	}
	while(y>=1){
		b[j]=y%2;
		y/=2;
		j++;
	}
	int ans=0;
	for(int l=0;l<=21;l++){
		if(a[l]!=b[l]){
			ans=ans+pow(2,l);
		}
	}
	return ans;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	
	for(int i=n;i>=1;i--){
		int xx=0,flag=dp[i+1];
		for(int j=i;j<=n;j++){
			if(flag>dp[j]&&j!=i){
				dp[i]=dp[i+1];
				break;
			}
			xx=yh(xx,s[j]);
			if(xx==k){
				dp[i]=1+dp[j+1];
				break;
			}
		}
		
	}
	cout<<dp[1];
	return 0;
}
