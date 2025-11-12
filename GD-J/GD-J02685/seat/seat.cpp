#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 1e6+10;
ll n,m,a[1010],t[1010];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	ll o = n*m;
	for(int i=1;i<=o;i++){
		cin>>a[i];
		t[a[i]]++;
	}
	ll p = a[1];
	ll num=0;
	for(int i=100;i>=0;i--){
		if(t[i]>0)num+=t[i];
		if(i==p){
			p = num;
			break;
		}
	}
	ll x=0,y=0;
	if(p%n==0) {
		x= p/n;
	}else{
		x = p/n+1;
	} 
	
	if(x%2==0){
		if(p%n==0) y = 1;
		else y = n-p%n+1;
	}else{
		if(p%n==0)y = n;
		else y = p%n;
	}
	cout<<x<<" "<<y;
	return 0;
}
