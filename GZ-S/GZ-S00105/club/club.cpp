//GZ-S00105 贵阳市第三中学 周忠杰  
#include<bits/stdc++.h>
using namespace std;
//Ren5Jie4Di4Ling5%
#define ll long long
ll a[100005][4];
ll oi(ll n,ll x,ll y,ll z,ll l,ll ans){
	ll b=0,c=0,d=0;
	if(n<l){
		return ans;
	}
	if(x>0){
		ans+=a[l][1];
		b=oi(n,x-1,y,z,l+1,ans);
		ans-=a[l][1];
	}
	if(y>0){
		ans+=a[l][2];
		c=oi(n,x,y-1,z,l+1,ans);
		ans-=a[l][2];
	}
	if(z>0){
		ans+=a[l][3];
		d=oi(n,x,y,z-1,l+1,ans);
		ans-=a[l][3];
	}
	return max(d,max(b,c));
}
void solve(){
	ll n;
	cin>>n;
	ll x=n/2,y=n/2,z=n/2;
	for(ll i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
	}
	ll l=1;
	ll ans=0;
	cout<<oi(n,x,y,z,l,ans)<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ll t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
