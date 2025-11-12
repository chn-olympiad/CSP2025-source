#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5e5+5;
ll n,k;
ll a[N],sum[N],dp[N];
map<ll,ll>mx;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>k;
//	n=5e5;k=pow(2,20)-1;
	for(ll i=1;i<=n;i++)cin>>a[i];
//	for(int i=1;i<=n;i++)a[i]=k;
	for(ll i=1;i<=n;i++)sum[i]=sum[i-1]^a[i];
	dp[0]=0;mx[0]=0;
	for(ll i=1;i<=n;i++){
		dp[i]=dp[i-1];
		if(mx.count(sum[i]^k))dp[i]=max(dp[i],mx[sum[i]^k]+1);
		if(!mx.count(sum[i]))mx[sum[i]]=dp[i];
		else mx[sum[i]]=max(mx[sum[i]],dp[i]);
	}
	cout<<dp[n];
	return 0;
}
/*
4 0
2 1 0 3
*/