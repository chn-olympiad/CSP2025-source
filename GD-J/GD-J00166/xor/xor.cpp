#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,a[500005],q[500005];
ll qxor(ll l,ll r){
	return q[r]^q[l-1];
}
ll dp[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld %lld",&n,&k);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)q[i]=q[i-1]^a[i];
	dp[1]=(a[1]==k);
	for(int i=2;i<=n;i++){
		for(int j=0;j<i;j++){
			for(int l=j+1;l<=i;l++){
				dp[i]=max(dp[i],dp[j]+(qxor(l,i)==k));
			}
		}
	}
	cout<<dp[n];
	return 0;
}
