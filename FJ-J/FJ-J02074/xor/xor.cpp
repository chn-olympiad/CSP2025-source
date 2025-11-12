#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ll n,k,ans=0;
	cin>>n>>k;
	vector<ll> a(n+1);
	vector<vector<ll>> b(n+1,vector<ll>(2));
	for(ll i=1;i<=n;i++) cin>>a[i];
	for(ll i=1;i<=n;i++){
		ll sum;
		for(ll j=n;j>=i;j--){
			if(i==j) sum=a[j];
			else{
				sum=a[i];
				for(ll p=i+1;p<=j;p++){
					sum=sum^a[p];
				}	
			}
			if(sum==k){
				ans++;
				cout<<i<<' '<<j<<' '<<sum<<endl;
				break;
			}
		}	
	}
	cout<<ans<<endl; 
	return 0;
}

