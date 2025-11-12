//GZ-S000292 殷震轩 遵义市第四中学 
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll t;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ll n,ans=0;
		cin>>n;
		while(n--){
			ll x,y,z;
			cin>>x>>y>>z;
			ll p=max(x,max(y,z));
			ans+=p;
		}
		cout<<ans<<endl;
	}
	return 0;
}
