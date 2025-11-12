#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],f[500005],dp[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		f[i]=f[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		int t=1;
		for(int j=i-1;j>=1;j--){
			if(dp[j]!=dp[j-1]){
				t=j+1;
				break;
			}
		}
		bool b=1;
		for(int j=i;j>=t;j--){
			if((f[i]^f[j-1])==k){
				dp[i]=dp[i-1]+1;
				b=0;
				break;
			}
		}
		if(b)dp[i]=dp[i-1];
	}
	cout<<dp[n];
	return 0;
}
