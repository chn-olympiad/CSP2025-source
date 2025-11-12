#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=110;
ll n,m,a[N];
bool cmp(ll x,ll y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	ll nm=n*m;
	for(ll i=1;i<=nm;i++) cin>>a[i];
	ll num=a[1];
	sort(a+1,a+nm+1,cmp);
	ll l=1,r=nm;
	while(l<r){
		ll mid=l+r>>1;
		if(a[mid]>num) l=mid+1;
		else r=mid;
	}
	ll L=ceil(1.0*l/n);
	cout<<L<<' ';
	if(L&1) cout<<(l-1)%n+1;
	else cout<<n-(l-1)%n;
	return 0;
}
