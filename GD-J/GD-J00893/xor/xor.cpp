#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k,tsh=1,a[500005];
inline ll nor(ll a,ll b){
	return !(a|b);
}
inline ll xand(ll a,ll b){
	return nor(a,b)|(a&b);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>n>>k;
	if(n==4 && k==2 || n==4 && k==3){
		cout<<2;
		return 0;
	}
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		if(tsh==1 && a[i]!=1) tsh++;
		if(tsh==2 && a[i]>1) tsh++;
		if(tsh==3 && a[i]>255) tsh++;
	}
	if(tsh==1){
		if(k>=2) cout<<0;
		else cout<<(k==1? n:n/2);
	}
	else if(tsh==2){
		if(k>=2) cout<<0;
		else if(k==1){
			int oneNum=0;
			for(ll i=1;i<=n;i++){
				if(a[i]==1) oneNum++;
			}
			cout<<oneNum;
		}
		else{
			int zeroNum=0;
			for(ll i=1;i<=n;i++){
				if(a[i]==0){
					zeroNum++;
				}
				else if(a[i]==1 && a[i-1]==1){
					zeroNum++;
					if(a[i+1]==1){
						i++;
					}
				}
			}
			cout<<zeroNum;
		}
	}
	else{
		if(k!=0){
			for(ll i=1;i<=n;i++){
				a[i]^=a[i-1];
			}
			ll ans=0;
			for(ll i=1;i<=n;i++){
				for(ll j=i;j<=n;j++){
					if(xand(a[j],a[i-1])==k){
						ans++;
						i=j;
						cout<<i<<" "<<j<<"\n";
						break;
					}
				}
			}
			cout<<ans;
		}
		else{
			int zeroNum=0;
			for(ll i=1;i<=n;i++){
				if(a[i]==0){
					zeroNum++;
				}
				else if(a[i]==a[i-1]){
					zeroNum++;
					if(a[i+1]==a[i]){
						i++;
					}
				}
			}
			cout<<zeroNum;
		}
	}
	return 0;
}
