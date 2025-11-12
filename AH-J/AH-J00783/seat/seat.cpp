#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll a[110];
ll xr;
ll xrw;
ll o;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	o=n*m;
	for(ll i=1;i<=o;i++){
		cin>>a[i];
		if(i==1){
			xr=a[i];
		}
	}
	sort(a+1,a+o+1);
	for(ll i=o;i>=1;i--){
		if(a[i]==xr){
			xrw=o-i+1;
			break;
		}
	}
	if(xrw%n!=0){
		ll ls=xrw/n+1;
		ll sy=xrw%n;
		if(ls%2==0){
			cout<<ls<<" "<<n-sy+1;
		}else{
			if(sy==0){
				cout<<ls<<" "<<m;
			}else{
				cout<<ls<<" "<<sy;
			}
		}
	}else{
		ll ls=xrw/n;
		ll sy=xrw%n+1;
		if(ls%2==0){
			cout<<ls<<" "<<n-sy+1;
		}else{
			if(sy==0){
				cout<<ls<<" "<<m;
			}else{
				cout<<ls<<" "<<sy+1;
			}
		}
	}
	return 0;
}
