#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll zqq[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ll n;
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>zqq[i];
	}
	sort(zqq+1,zqq+1+n);
	if(n==3){
		if(zqq[1]+zqq[2]<=zqq[3]){
			cout<<0;
		}else cout<<1;
		return 0;
	}
	ll ans=0;
	if(zqq[1]+zqq[2]>zqq[n]){
		for(ll i=3;i<=n;i++){
			ll num=1;
			for(ll j=n;j>=n-i+1;j--){
				num*=j;
			}
			num/=i*(i-1);
			num%=998244353;
			ans+=num;
			ans%=998244353;
		}
		cout<<ans;
		return 0;
	} 
		for(ll i=3;i<=n;i++){
			ll num=1;
			for(ll j=n;j>=n-i+1;j--){
				num*=j;
			}
			num/=i*(i-1);
			num%=998244353;
			ans+=num;
			ans%=998244353;
		}
		cout<<ans-1;
	return 0;
}
