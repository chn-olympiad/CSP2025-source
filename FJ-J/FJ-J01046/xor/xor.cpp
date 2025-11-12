#include<bits/stdc++.h>
using namespace std;
long long n,k,a[1234],dp[1234][1234],c,ans=-1,s0,s1;
void dfs(long long p,long long q){
	if(p>n||q>n){ans=max(ans,c);return;}
	for(long long i=p;i<=n;i++){
		for(long long j=max(p,q);j<=n;j++){
			if(dp[i][j]==k){
				c++;
				dfs(i+1,j+1);
				c--;
			}
		}
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	memset(dp,-1,sizeof(dp));
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		dp[i][i]=a[i];
		if(a[i]==0){s0++;}
		if(a[i]==1){s1++;}
	}
	for(long long l=2;l<=n;l++){
		for(long long i=1;l+i-1<=n;i++){
			long long j=l+i-1;
			dp[i][j]=a[i]^dp[i+1][j];
		}
	}
	if(s1+s0==n){cout<<s1;return 0;}
	dfs(1,1);
	if(ans==-1)ans=0;
	cout<<ans;
	return 0;
}
