#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[105];
bool cmp(const ll& x,const ll& y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ll m,n,xr;
	cin>>n>>m;
	for(ll i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1) xr=a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	ll tot=0;
	for(ll i=1;i<=m;i++){
		if(i%2==1) {
			for(ll j=1;j<=n;j++){
				if(a[++tot]==xr){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		else {
			for(ll j=n;j>=1;j--){
				if(a[++tot]==xr){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
