#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[100005],b[100005],c[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ll T;
	cin>>T;
	while(T--){
		ll n;
		cin>>n;
		ll number=n/2;
		for(ll i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		sort(a+1,a+n+1);
		ll ans=0;
		for(ll i=n;i>number;i--){
			ans+=a[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}