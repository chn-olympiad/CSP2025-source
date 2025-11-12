#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[105];
int lch(ll a,ll b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ll m,n,zqs;
	cin>>n>>m;
	for( ll i=1;i<=n*m;i++){
		cin>>a[i];
	}
	zqs=a[1];
	sort(a+1,a+1+n*m,lch);
	for(ll i=1;i<=n*m;i++){
		if(zqs==a[i]){
			zqs=i;
			break;
		}
	}
	if(zqs%n==0){
		if((zqs/n)%2==0){
			cout<<zqs/n<<" "<<1;
		}else{
			cout<<zqs/n<<" "<<n;
		}
	}else{
		if((zqs/n)%2==0){
			cout<<zqs/n+1<<" "<<zqs%n;
		}else{
			cout<<zqs/n+1<<" "<<n-zqs%n+1;
		}
	}
	return 0;
}
