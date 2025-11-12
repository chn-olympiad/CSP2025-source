#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll mod=998244353;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	ll n,sum=0,ans=0;cin>>n;
	vector<ll> a(n+1);
	for(ll i=1;i<=n;i++)cin>>a[i],sum+=a[i];
	vector<vector<ll>> d(n+1,vector<ll>(sum+1));
	sort(begin(a)+1,end(a));
	d[0][0]=1;
	for(ll i=1;i<=n;i++){
		d[i]=d[i-1];
		for(ll j=a[i];j<=sum;j++)d[i][j]=(d[i-1][j]+d[i-1][j-a[i]])%mod;
	}
	for(ll j=a[3]*2+1;j<=sum;j++)(ans+=d[3][j])%=mod;
	for(ll i=4;i<=n;i++)
		for(ll j=a[i]*2+1;j<=sum;j++)(ans+=d[i][j]-d[i-1][j])%=mod;
	cout<<ans;
	return 0;
}