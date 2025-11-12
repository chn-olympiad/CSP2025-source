#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=998244353;
const ll N=5e3+10;
ll n,a[N],ans=0;


signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
	ll sum=0,mx=0;
	for(ll i=1;i<=n;i++){
		sum+=a[i];
		mx=max(mx,a[i]);
	}
	if(sum>2*mx) ans++;
	cout<<ans;
	return 0;
}
/*
5
1 2 3 4 5
*/
