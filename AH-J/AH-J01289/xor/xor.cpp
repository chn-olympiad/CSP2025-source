#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k;
ll a[10005],sum[10005];
bool f[10005];
ll find(ll l,ll r,ll x){
	while(l<=r){
		ll mid=(l+r)/2;
		if(sum[mid]>x) l=mid+1;
		else r=mid;
	}
	return l;
}
int main(void){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
	}
	sort(sum+1,sum+1+n);
	ll ans=0;
	for(ll i=1;i<=n;i++){
		ll p=k-a[i];
		if(p!=0){
			ll pos=find(i,n,p);
			if(pos!=0&&!f[pos]&&!f[a[i]])
				ans++,f[pos]=1,f[a[i]]=1;
		}
		else f[a[i]]=1;
	}
	cout<<ans;
	return 0;
}
