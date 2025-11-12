#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[10];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ll n;
	cin>>n;
	ll zs=0,maxn=0;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		zs+=a[i];
		if(maxn<=a[i]) maxn=a[i];
	}
	if(n<3) cout<<0;
	else{
		if(zs>2*maxn) cout<<1;
		else cout<<0;
	}
	return 0;
}