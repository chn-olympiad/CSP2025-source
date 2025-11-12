#include<bits/stdc++.h>
using namespace std;
long long k[600000];
long long dp[600000];
long long h[600000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,m;
	cin>>n>>m;

	for(int i=1;i<=n;i++){
		cin>>k[i];
		h[i]=k[i]^h[i-1];
	}long long ans=0;
	for(int i=1;i<=n;i++){
		if(k[i]==m)dp[i]=dp[i-1]+1;
		else{
			for(int u=i-1;u>=0;u--){
				long long l=h[i]^h[u];
				if(l==m){
				dp[i]=max(dp[i],dp[u]+1);
				break;
			}
			}
		}ans=max(ans,dp[i]);
	}cout<<ans;


	fclose(stdin);
    fclose(stdout);
	return 0;

}
