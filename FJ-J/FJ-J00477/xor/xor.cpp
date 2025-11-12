#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll zqs[500005];
ll zqq(ll a,ll b){
	int ans[22]={0};
	int i;
	for(i=1;a>0||b>0;i++){
		int k=a%2,l=b%2;
		if(k<l)swap(k,l);
		ans[i]=k-l;
		a/=2;
		b/=2;		
	}
	ll num=0,kl=1;
	for(ll j=1;j<=i;j++){
		num+=ans[j]*kl;
		kl*=2;
	}
	return num;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ll n,k;
	cin>>n>>k;
	
	ll ans=0;
	for(ll i=1;i<=n;i++){
		cin>>zqs[i];
		if(zqs[i]==k){
			ans++;
			zqs[i]=-1;
		}
	}
	ll noww=0,endd=1;
	for(ll i=1;i<=n;i++){
		if(zqs[i]==-1){
			noww=0;
			endd=i+1;
			continue;
		}
		noww=zqq(noww,zqs[i]);
		if(noww==k){
			noww=0;
			endd=i+1;
			ans++;
		}else{
			ll opo=noww;
			for(ll j=endd;j<i;j++){
				noww=zqq(noww,zqs[j]);
				if(noww==k){
					opo=0;
					endd=i+1;ans++;
					break;
				}
			}
			noww=opo;
		}
	}
	cout<<ans;
	return 0;
}
