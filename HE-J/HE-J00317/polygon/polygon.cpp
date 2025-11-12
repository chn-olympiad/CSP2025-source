#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[5001],b[5001];
int s(int n){
	int m=1,o=3;
	for(ll i=2;i<n;i++){
		m+=o;
		o+=2*i;
	}
	return m;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ll n,m=0;
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(ll i=1;i<=n;i++){
		b[i]=a[i]+b[i-1];
	}
	for(ll i=2;i<n;i++){
		for(ll j=i;j<n;j++){
			ll t=b[j]-b[j-i];
			for(ll l=n;l>j;l--){
				if(a[l]<t){
					int o=j-i;
					if(o>0)o--;
					if(o>0)o=s(o);
					m=m+(l-j)*(o+1);
					m=m%998244353;
				}
			}
		}
	}
	cout<<m+1;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
