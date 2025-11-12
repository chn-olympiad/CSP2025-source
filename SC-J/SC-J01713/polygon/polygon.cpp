#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,sum,mx,a[5005];
int main(){
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
		mx=max(mx,a[i]);
	}
	if(n<3){
		cout<<0;
	}else if(n==3){
		if(sum>mx*2){
			cout<<1;
		}
	}


	return 0;
}
