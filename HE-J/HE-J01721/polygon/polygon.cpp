#include<bits/stdc++.h>
#define ll long long
using namespace std;


const ll MOD=998244353;
ll n,ans;
ll a[6000];
bool f[6000];


void dg(ll x,ll y,ll z){
	if(y>a[x]){
		ans++;
	}
	for(ll i=z+1;i<x;i++){
		if(f[i]==false){
			f[i]=true;
			dg(x,y+a[i],i);
			f[i]=false;
		}
	}
	return;
}


signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);


	scanf("%lld",&n);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	
	
	sort(a+1,a+1+n);
	for(ll i=3;i<=n;i++){
		dg(i,0,0);
	}
	
	
	printf("%lld\n",ans);
	
	
	return 0;
}
