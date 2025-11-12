#include<bits/stdc++.h>
using namespace std;
#define ll long long

const ll N=5e5+5;
ll n,k,maxn,flag=1;
ll a[N],sum[N];

int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(ll i=1; i<=n; i++) {
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
		if(a[i]!=1)flag=0; 
	}
	if(flag){
		cout<<n/2;
		return 0;
	}
	ll l=1,ans=0;
	while(l<=n) {
		ll flag=0;
		for(ll r=l; r<=n; r++) {
			ll x=sum[r]^sum[l-1];
			if(x==k) {
				flag=r;
				ans++;
				//cout<<l<<' '<<r<<' '<<x<<endl;
				break;
			}
		}
		if(flag)l=flag+1;
		else l++;
	}
	cout<<ans;
	return 0;
}/*
4 0
2 1 0 3
*/
