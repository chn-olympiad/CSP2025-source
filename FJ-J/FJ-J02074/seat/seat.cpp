#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	vector<ll> a(n*m+1,0);
	vector<vector<ll>> b(n+1,vector<ll>(m+1,0));
	for(ll i=1;i<=n*m;i++) cin>>a[i];
	ll sum=a[1];
	sort(a.begin(),a.end());
	ll ans=a.size()-1;
	for(ll i=1;i<=m;i++){
		if(i%2==1){
			for(ll j=1;j<=n;j++){
				b[j][i]=a[ans];
				ans--;
				if(b[j][i]==sum){
					cout<<i<<' '<<j<<endl; 
					break;
				} 
			}
			
		}
		if(i%2==0){
			for(ll j=n;j>=1;j--){
				b[j][i]=a[ans];
				ans--;
				if(b[j][i]==sum){
					cout<<i<<' '<<j<<endl; 
					break;
				} 
			}
			
		}
	}	
	return 0;
}

