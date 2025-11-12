#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[105];
ll cmp(const ll&x,const ll&y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ll n,m;
	scanf("%lld%lld",&n,&m);
	ll nm=n*m;
	for(ll i=1;i<=nm;i++) scanf("%lld",&a[i]);
	ll R=a[1];
	sort(a+1,a+1+nm,cmp);
	ll rpos=0;
	for(ll i=1;i<=nm;i++){
		if(a[i]==R){
			rpos=i;
			break;
		}
	}
	ll cnt=0;
	for(ll j=1;j<=m;j++){
		if(j%2!=0){
			for(ll i=1;i<=n;i++){
				cnt++;
				if(cnt==rpos) cout<<j<<" "<<i;
			}
		}
		else{
			for(ll i=n;i>=1;i--){
				cnt++;
				if(cnt==rpos) cout<<j<<" "<<i;
			}
		}
	}
	return 0;
}
