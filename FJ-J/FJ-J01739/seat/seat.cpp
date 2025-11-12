#include<bits/stdc++.h>
#define ll  long long
using namespace std;
ll a[115];
bool cmp(ll x,ll y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ll n,m,c,r;cin>>n>>m;
	for(ll i=1;i<=n*m;i++)
		cin>>a[i];
	ll f=a[1],q;
	sort(a+1,a+n*m+1,cmp);
	for(ll i=1;i<=n*m;i++){
		if(a[i]==f){
			q=i;break;
		}
	}
	if(q%n==0){
		c=q/n;
		if(c%2==1)r=n;
		else r=1;
	}else{
		c=q/n+1;
		if(c%2==1)r=q%n;
		else r=n-(q%n)+1;
	}
	cout<<c<<" "<<r<<"\n";
	return 0;
}
