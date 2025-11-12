#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll INF=5e5+5;
ll n,k;
ll a[INF];
ll ans;

ll xors(ll x,ll y){
	ll s=0;
	for(ll i=x;i<=y;i++)
		s^=a[i];
	return s;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>k;
	for(ll i=1;i<=n;i++)
		cin>>a[i];
	bool flag=true;
	for(ll i=1;i<=n;i++)
		if(a[i]!=1)
			flag=false;
	if(flag&&k==0){
		cout<<1;
		return 0;
	}
	
	for(ll i=1;i<=n;i++){
		ll sum=0;
		for(ll j=i;j<=n;j++)
			if(xors(i,j)==k)
				sum++;
		ans=max(ans,sum);
	}
	cout<<ans;
	
	return 0;
}
