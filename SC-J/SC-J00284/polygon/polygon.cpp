#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[5005];
const int mod=998244353;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ll n;
	cin>>n;
	ll op=0;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1) op=1;
	}
	sort(a+1,a+n+1);
	if(n<=3){
		if(n==3){
			if(a[1]+a[2]>a[3]){
				cout<<1;
			}else{
				cout<<0;
			}
		}else{
			cout<<0;
		}
		return 0;
	}
	if(op==0){
		ll sum=0;
		ll t=0,tt=0;
		for(ll i=1;i<=n-2;i++){
			t+=i;
//			cout<<t<<endl;
			sum+=t;
			sum+=tt;
			sum%=mod;
			tt=t;
		}
		cout<<sum%mod;
		return 0;
	}
	ll cnt=0,nb=0;
	for(ll i=1;i<=n;i++){
		for(ll g=i+1;g<=n;g++){
			nb=a[g]+a[i];
			for(ll q=g+1;q<=n;q++){
				nb=a[g]+a[i];
				for(ll j=q;j<=n;j++){
					for(ll k=j;k<=n;k++){
						if(a[k]<nb){
							cnt++;
//						cout<<i<<" "<<g<<" "<<q<<" ";
//						for(ll i=q+1;i<j;i++){
//							cout<<i<<" ";
//						}
//						cout<<k<<endl;
						}else{
							break;
						}
					}
					nb+=a[j];
				}
			}
			
		}
	}
	cout<<cnt%mod;
	return 0;
}