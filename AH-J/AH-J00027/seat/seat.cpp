#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=1e4+34;
ll a[N];
ll m,n;
ll cmp(ll x,ll y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	ll ji=m*n;
	for(ll i=0;i<ji;i++){
		cin>>a[i];
	}
	ll z=a[0];
	sort(a,a+ji,cmp);
	ll p=0,q=0;
	ll x,y;
	x=y=1;
	for(ll i=0;i<ji;i++){
		if(a[i]==z){
			cout<<x<<" "<<y;
			return 0;
		}
		if(p==0){
			y++;
		}else{
			if(q==1){
				y=n;
				q=0;
			}
			y--;
		}
		if((i+1)%n==0){
			x++;
			if(p==0){
				p=1;
				q=1;
				y--;
			}else{
				p=0;
				y++;
			}
		}
	}
	return 0;
}
