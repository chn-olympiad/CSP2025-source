#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[500001],b[500001],v[500001];
int s(ll p,ll q){
	for(ll i=q;i<=p;i++){
		if(v[i]==1)return 0;
	}
	for(ll i=q;i<=p;i++){
		v[i]=1;
	}
	return 1;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ll n,k,c=0;
	cin>>n>>k;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i]^b[i-1];
	}
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n;j++){
			ll t=b[j]^b[j-i];
			if(t==k&&s(j,j-i+1)){
				c++;
			}
		}	
	}
	cout<<c;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
