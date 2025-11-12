#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[100+10],xR;
bool cmp(ll x,ll y){
	return x>y;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1) xR=a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	ll p=0;
	for(ll i=1;i<=n*m;i++){
		if(a[i]==xR){
			p=i;
			break;
		}
	}
	ll c=p/n;
	if(p>n*c) c++;
	p=p%(2*n);
	ll r=0;
	if(p==0) r=1;
	else if(p<=n) r=p;
	else r=2*n-p+1;
	cout<<c<<" "<<r;
	return 0;
}