#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	ll a[10086];
	ll zj=n*m;
	ll kkksc03=0;
	ll ans=0;
	for(ll i=1;i<=zj;i++){
		cin>>a[i];
		kkksc03=a[1];
	}
	for(ll i=1;i<=zj;i++){
		if(a[i]>kkksc03){
			ans++;
		}	
	}
	float aaa=ans%n;
	if(ans%n!=0){
		cout<<ans%n<<" "<<ceil(ans/n);
	}else{
		cout<<n<<" "<<ans/n;
	}
	return 0;
}
