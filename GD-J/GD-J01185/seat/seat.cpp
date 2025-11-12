#include <bits/stdc++.h> 
using namespace std;
using ll=long long;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ll n,m,c,r,x=0;
	ll a[100]={0};
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
		x++;
	}
	ll a1=a[0],mac=0;
	for(ll i=0;i<x;i++){
		if(a[i]>a1){
			mac++;
		}
	}
	mac++;
	c=mac/n;
	r=mac%n;
	if(r%2==0){
		cout<<c<<' '<<n-r;
	}else{
		cout<<c<<' '<<r;
	}
	return 0;
}
