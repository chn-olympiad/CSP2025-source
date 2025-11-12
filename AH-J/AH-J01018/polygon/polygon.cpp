#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ll n;
	cin>>n;
	if(n==3){
		ll a,b,c;
		cin>>a>>b>>c;
		if(a+b>c&&a+c>b&&b+c>a) cout<<1;
		else cout<<0;
	}
	else{
		ll ans=0;
		for(ll i=1;i<=n;i++) cin>>a[i];
		for(ll i=1;i<=(1<<n);i++){
			ll maxn=0,t=0,c=0; 
			for(ll j=1;j<=n;j++){
				if(i&(1<<j)){
					t+=a[j];
					c++;
					maxn=max(maxn,a[j]);
				}
			}
			if(c>=3&&t>maxn*2) ans++;
			ans%=998244353;
		}
		cout<<ans;
	}
	return 0;
}
