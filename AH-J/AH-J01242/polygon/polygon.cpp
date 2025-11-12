#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[10];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ll n;
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i]
	}
	if(n<3){
		cout<<'0';
		return 0;
	}
	if(a[1]+a[2]>a[3]&&a[2]+a[3]>a[1]&&a[1]+a[3]>a[2]){
		cout<<"1";
	}else{
		cout<<'0';
	}
	return 0;
}
