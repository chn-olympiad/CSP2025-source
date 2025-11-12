#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+5;
ll n,a[N],b[N],k,dp[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	for(ll i=n;i>=1;i--){
		ll x=0;
		for(ll j=i;j>=1;j--){
			x=x^a[j];
			if(x==k){
				b[i]=i-j+1;
				break;
			}
		}
	}
//	for(ll i=1;i<=n;i++){
//		 cout<<b[i]<<" ";
//	}
//	cout<<endl;
	for(ll i=1;i<=n;i++){
		if(b[i]) dp[i]=max(dp[i-1],dp[i-b[i]]+1);
		else dp[i]=dp[i-1];
//		cout<<dp[i]<<" ";
	}
//	cout<<endl;
	cout<<dp[n];
}