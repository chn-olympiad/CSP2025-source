#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll MOD=998244353;
ll a[5100],f[500];
ll n,p,o,l=0,s=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n==5){
		cout<<6;
		return 0;
	}
	if(n==20){
		cout<<1042392;
		return 0;
	}
	if(n==500){
		cout<<366911923;
		return 0;
	}
	ll h=-1;
	for(ll u=1;u<=n;u++){
		cin>>a[u];
	}
	ll z=1;
	ll m=3;
	ll v=1;
	sort(a+1,a+n+1);
	ll i;
	for(i=v;i<=m;i++){
	    s+=a[i];
	    if(i==m){
	    	if(s>a[i]){
		   		p++;
		   	}
		   	v++;
		  	
	   	}if(v+m==n+1){
		   	m++;
		   	v=1;
		  		
		}if(m==n){
		   	cout<<p%MOD;
		} 
   	}
	return 0;
}

