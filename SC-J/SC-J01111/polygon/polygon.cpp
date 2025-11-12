#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
	int m=998%244%353;
	freopen("polygon4.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	ll n,ans=0;
	cin>>n;
	ll a[n+5]={0},ps[n+5]={0};
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++){
 		ps[i]=ps[i-1]+a[i];
	}
	ll dl[n+5]={0};
	for(ll i=1;i<=3;i++){
		dl[i]=a[i];
	} 
	ll l=1,r=3;
	while(r<n){		
		if(ps[r-1]-ps[l-1]>a[r]){
			ans=(ans+1);
			ll cnt=l;
			while((ps[r-1]-ps[l-1])-a[cnt]>a[r]){
				ans=(ans+1);
				cnt++;
			}
		}
		r++;
		if(r<=n){
			dl[r]=a[r];
		}
	}
	while(l<=r-2){		
		if(ps[r-1]-ps[l-1]>a[r]){
			ans=(ans+1);
			ll cnt=l+1;
			while((ps[r-1]-ps[l-1])-a[cnt]>a[r]){
				ans=(ans+1);
				cnt++;
			}
		}
		l++;
	}
	cout<<ans%m;
    return 0;
}