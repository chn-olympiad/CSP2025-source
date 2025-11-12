#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll f[500005],w[500005];
ll ans;
ll n,k;
ll num[500005],q[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(ll i=1;i<=n;i++){
		cin>>num[i];
		q[i]=q[i-1]^num[i];
	}
	for(ll i=1;i<=n;i++){
		for(ll l=1;l<=n-i+1;l++){
			if((q[i+l-1]^q[i-1])==k){
				f[i]=l;
				break;
			}
		}	
	}
	for(ll i=1;i<=n;i++){
		if(w[k])continue;
		ll cnt=0,k=i;
		while(k<=n){
			w[k]=1;
			if(f[k]>0){
				cnt++;
				k+=f[k];
			}
			else k++;
		}
		ans=max(ans,cnt);
	}
	cout<<ans;	
	return 0;
}
