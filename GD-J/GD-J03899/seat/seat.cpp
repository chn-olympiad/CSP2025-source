#include<bits/stdc++.h>
using ll=long long;
using namespace std;
ll n,m,x,sum;
ll a[105];
bool cmp(ll x,ll y){
	return x>y;
}
int main(){
	cin>>n>>m;
	for(ll i=1;i<=n*m;i++){
		cin>>a[i];
	}x=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(ll i=1;i<=n*m;i++){
		if(a[i]==x)x=i;
	}
	for(ll j=1;j<=m;j++){
		if(j%2){
			for(ll i=1;i<=n;i++){
				sum++;
				if(sum==x){
					cout<<j<<" "<<i;
					return 0;
				} 
			}
		}else{
			for(ll i=n;i>=1;i--){
				sum++;
				if(sum==x){
					cout<<j<<" "<<n-i+1;
					return 0;
				} 
			}
		}
	}
	return 0;
}
