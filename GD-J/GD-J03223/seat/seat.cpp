#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
ll n,m,sum;
int a[110];
bool x;
bool cmb(ll x,ll y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	ll op=n*m;
	for(ll i=1;i<=op;++i)
		cin>>a[i];
	ll t=a[1];
	sort(a+1,a+1+op,cmb);
	for(ll i=1;i<=op;++i){
		if(a[i]==t) {
			sum=i;
			break;
		}
	}
	ll c=1,r=0;
	x=1;
	while(sum){
		sum--;
		if(r==n && x) {
			x=0;
			c++;
			continue;
		}
		else if(r==1 && !x){
			x=1;
			c++;
			continue;
		}
		if(x) r++;
		else r--;
	}
	cout<<c<<" "<<r;
	return 0;
} 
