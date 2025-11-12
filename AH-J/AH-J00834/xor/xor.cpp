#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500000+10];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ll n,k;
	cin>>n>>k;
	for(ll i=1;i<=n;i++)cin>>a[i];
	ll sum=0,ans=0;
	for(ll l=1;l<=n;l++){
		for(ll r=l;r<=n;r++){
			for(ll k=l;k<=r;k++){
				sum^=a[k];
			}
			if(sum==k)ans++,l=r+1;
			sum=0;
		}
	}
	cout<<ans;
	return 0;
}
