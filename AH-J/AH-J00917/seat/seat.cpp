#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[100+10];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ll n,m;
	ll b=0;
	cin>>n>>m;
	for(ll i=1;i<=n*m;i++){
		cin>>a[i];
	}
	b=a[1];
	sort(a+1,a+n*m+1);
	ll wz;
	for(ll i=n*m;i>=1;i--){
		if(b==a[i]){
			wz=n*m-i+1;
		}
	}
	ll wz1=wz,wz3=wz;
	double wz2=wz;
	wz%=n;
	if(wz2/(1.0*n)!=ll(wz2/n)){
		wz3/=n;
		wz3+=1;
	}else{
		wz3/=n;
	}
	if(wz2/(1.0*n)!=ll(wz2/n)){
		wz1/=n;
		wz1+=1;
	}else{
		wz1/=n;
	}
	wz1%=2;
	if(wz1==0){
		if(wz==0){
			wz=n;
		}
		cout<<wz3<<" "<<n-wz+1;
	}else{
		if(wz==0){
			wz=n;
		}
		cout<<wz3<<" "<<wz;
	}
	
	return 0;
}
