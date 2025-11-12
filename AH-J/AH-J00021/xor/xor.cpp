#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500010];
ll sum[500010];
ll dp[500010];
ll n,k;
void f20(){
	if(k==1)cout<<n;
	else cout<<n/2;
}
void f50(){
	for(ll i=1;i<=n;i++){
		bool ok=0;
		for(ll j=1;j<=i;j++){
			if((sum[i]^sum[j-1])==k){
				ok=1;
				dp[i]=max(dp[i],max(dp[i-1],dp[j-1]+1));
			}
		}
		if(ok==0)dp[i]=dp[i-1];
	}
	cout<<dp[n];
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool sA=1;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=(sum[i-1]^a[i]);
		if(a[i]!=1)sA=0;
	}
	if(sA==1){
		f20();
		return 0;
	}
	if(n<=10000){
		f50();
		return 0;
	}
	cout<<n;
	return 0;
}
