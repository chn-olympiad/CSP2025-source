#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long ask[500010];
long long dp[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>ask[i];
	}
	for(int i=1;i<=n;i++){
		long long w=ask[i];
		if(w==k){
			dp[i]=dp[i-1]+1;
		}else{
			for(int j=i-1;j>=1;j--){
				w^=ask[j];
				if(w==k){
					dp[i]=dp[j-1]+1;
					j=0;
				}
			}		
		}
		dp[i]=max(dp[i],dp[i-1]);
	}
	cout<<dp[n];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
