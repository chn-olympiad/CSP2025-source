//GZ-S000292 殷震轩 遵义市第四中学 
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,c,l,k;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	l=n;
	for(ll i=0;i<n;i++){
		cin>>c;
		if(c==0) l--;
	}
	for(ll j=0;j<=(l-m);j++){
		ll ans=1;
		for(ll i=l;i>(l-m-j);i--) ans*=i,ans%=998244353;
		k+=ans,k%=998244353;
	} 
	cout<<k;
	return 0;
}
//161088479
