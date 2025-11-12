#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[100+10];
bool cmp(const ll x,const ll y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	for(ll i=1;i<=n*m;i++){
		cin>>a[i];
	}
	ll R=a[1];
	ll f=0;
	sort(a+1,a+n*m+1,cmp);
	ll l=1,h=1;
	for(ll i=1;i<=n*m;i++){
		if(a[i]==R){
			cout<<l<<" "<<h;
			return 0;
		}
		if(f==0){
			if(h==n){
				l++;
				f=1;
			}else{
				h++;
			}	
		}else{
			if(h==1){
				l++;
				f=0;
			}else{
				h--;
			}
		}
	}
	return 0;
}
