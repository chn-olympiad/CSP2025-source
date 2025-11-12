#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e3+3;
ll a[N];
ll dp[N][N];
ll s[N],v[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	ll n,k;
	cin>>n>>k;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		s[i]=(s[i-1]^a[i]);
	}	
	if(n==2){
		if((a[1]^a[2])==k)cout<<1;
		else cout<<0;
		return 0;
	}
	
//	for(ll i=1;i<=n;i++)cout<<s[i]<<" ";
		
	for(ll i=1;i<=n;i++){
		memset(v,0,sizeof v);
		ll sum=a[i];
		ll cnt=0;
		for(ll j=i;j<=n;j++){
			sum=(sum^a[j]);
			if(sum==k){
				dp[i][j]=max({dp[i][j],dp[i][j-1]});
			}
			else dp[i][j]=max({dp[i][j],dp[i-1][j],dp[i][j-1]});
		}
	}
	cout<<dp[n][n];
	return 0;
	fclose(stdin);
	fclose(stdout);
}
/*
4 2
2 1 0 3
2

100 1
1 0 1 1 0 0 0 1 1 1 1 1 1 0 0 1 1 1 1 1 0 0 1 1 1 0 0 1 1 1 1 0 1 0 1 1 1 0 1 1 1 1 0 1 0 0 1 1 1 0 1 1 1 0 1 0 0 1 0 1 0 1 1 1 0 1 0 1 0 1 0 1 1 1 0 1 0 1 1 0 1 1 0 1 1 1 1 0 1 1 0 1 0 1 1 0 0 0 0 1

*/
