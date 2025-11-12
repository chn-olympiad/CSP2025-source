#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010],s[500010],dp[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		s[i]=(s[i-1]^a[i]);
	}
	if(k==0)cout<<n/2;
	else if(k==1){
		int sum=0;
		for(int i=1;i<=n;i++)if(a[i]==1)sum++;
		cout<<sum;
	}else{
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++){
				if((s[j-1]^s[i])==k){
					dp[i]=max(dp[i],dp[j-1]+1);
				}else dp[i]=max(dp[i],dp[j-1]);
			}
		}
		int sum=0;
		for(int i=1;i<=n;i++)sum=max(sum,dp[i]);
		cout<<sum;
	}
	return 0;
}
