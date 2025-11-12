#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll a[500005];
ll s[500005];
ll t[500005];
ll n,k,ans1,ans2;

int main(){
	
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	
	for(ll i=1;i<=n;i++) cin>>a[i];
	
	if(k==0){
		cout<<n/2;
		return 0;
	}
	
	for(ll i=1;i<=n;i++) s[i]=s[i-1]^a[i];
	for(ll i=1;i<=n;i++) t[i]=t[i-1]^a[n-i+1];
	
//	for(ll i=1;i<=n;i++) cout<<s[i]<<" ";
//	cout<<"\n";
	
	ll l=0,r=1;
	while(l<r && r<=n){
//		cout<<l<<" "<<r<<"\n";
		if((s[r]^s[l])==k){
			l=r;
			r++;
			ans1++;
//			cout<<ans<<"\n";
		}
		else{
			r++;
		}
	}
	
	l=0,r=1;
	while(l<r && r<=n){
//		cout<<l<<" "<<r<<"\n";
		if((t[r]^t[l])==k){
			l=r;
			r++;
			ans2++;
//			cout<<ans<<"\n";
		}
		else{
			r++;
		}
	}
	
	cout<<max(ans1,ans2);
	
	return 0;
}

