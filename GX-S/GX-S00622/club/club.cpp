#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		ll sum=0;
		ll a[100005],b[100005],c[100005];
		for(ll i=0;i<n;i++){
			cin>>a[i]>>b[i]>>c[i];
			sum+=max(max(a[i],b[i]),c[i]);
		}
		cout<<sum<<"\n";
	}
	return 0;
}
