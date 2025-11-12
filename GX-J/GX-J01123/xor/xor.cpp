#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ll n,k;
	cin>>n>>k;
	ll sum=0;
	ll a[1086];
	ll b[1086]={0};
	for(ll i=0;i<n;i++){
		cin>>a[i];
		b[i]+=a[i];
	}
	for(ll i=0;i<n;i++){
		for(ll j=0;j<i ;j++){
			if(b[i]==k||b[i]-b[j]==k){
				sum++;
			}
		}
	}
	cout<<sum;
	return 0;
}
