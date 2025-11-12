#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[105];
bool cmp(ll x,ll y){
	return x>y;
}
int main(){
	//freopen("seat1.in","r",stdin);
	//freopen("seat1.out","w",stdout);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n*m;i++){
		cin>>a[i];
	}
	ll rr=a[1];
	ll x,y;
	sort(a+1,a+1+n*m,cmp);
	for(ll i=1;i<=n*m;i++){
		if(a[i]==rr){
			ll j=i%(2*n);
			y=(i+(n-1))/n;
			if(j>n){
				x=n-(j-n)+1;
			}else{
				x=j;
			}
			break;
		}
	}
	cout<<y<<' '<<x;
	return 0;
} 
