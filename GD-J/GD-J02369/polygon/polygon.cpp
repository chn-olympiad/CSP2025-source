#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=998244353;
ll zh[5050],jc[5050];
ll cmp(ll z,ll h){
	return z>h;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll s,szh=0;
	cin>>s;
	jc[0]=1;
	for(ll i=1;i<=5000;i++){
		jc[i]=jc[i-1]*i%mod;
	}
	for(ll i=0;i<s;i++){
		cin>>zh[i];
	}
	sort(zh,zh+s,cmp);
	if(s==3){
		cout<<"1";
		return 0;
	}else if(zh[0]==zh[s-1]){
		for(ll i=3;i<=s;i++){
			szh=(szh+(jc[s]/jc[s-i]/jc[i]))%mod;
		}
		cout<<szh;
		return 0;
	}else if(s<=20){
		for(ll i=0;i<s-2;i++){
			for(ll j=i+1;j<s-1;j++){
				for(ll k=j+1;k<s;k++){
					if(zh[i]+zh[j]+zh[k]-2*zh[i]>=0){
						szh=(szh+s-k)%mod;
					}
				}
			}
		}
		cout<<szh;
		return 0;
	}
	for(ll i=0;i<s-2;i++){
		for(ll j=i+1;j<s-1;j++){
			ll k=2*zh[i]-(zh[i]+zh[j]);
			if(k==0){
				szh=(szh+s-j)%mod;
			}else{
				ll l=j+1,r=s-1;
				while(l<r){
					ll mid=(l+r)/2;
					if(zh[mid]>k){
						l=mid;
					}else{
						r=mid-1;
					}
				}
				szh=(szh+s-l)%mod;
			}
		}
	}
	cout<<szh;
	return 0;
}
