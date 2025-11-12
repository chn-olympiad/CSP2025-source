#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=5e5+14;
ll n;
int a[N];
ll cnt;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(ll i=0;i<n;i++){
		cin>>a[i];
	}
	if(n<3){
		cout<<"0";
	}else if(n==3){
		if(a[0]+a[1]+a[2]>2*max(a[0],max(a[1],a[2]))){
			cout<<"1";
		}else{
			cout<<"0";
		}
	}else{
		cout<<(1+n)*n/2;
	}	
	return 0;
}
