#include <bits/stdc++.h> 
using namespace std;
using ll=long long;
ll n,k,a[1000000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(ll i=0;i<n;i++){
		cin>>a[i];
	}
	ll c=0;
	if(k<=1){
		for(ll i=0;i<n;i++){
			if(a[i]==1 && a[i]==a[i+1]){
				c++;
				i++;
			}
			if(i==0){
				c++;
			}
		}
		cout<<c; 
	}
	if(k<=255){
		for(ll i=0;i<n;i++){
			if(a[i]==255 && (a[i-1]==0 || a[i+1]==0)){
				c++;
				i++;
			}
			if(i==0){
				c++;
			}
		}
		cout<<c; 
	}
	return 0;
}
