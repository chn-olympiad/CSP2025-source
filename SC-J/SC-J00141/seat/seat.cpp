#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll zz[130];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	ll n,m,c,r;
	cin>>n>>m;
	for(ll i=1;i<=n*m;i++){
		cin>>zz[i];
	}
	ll a=zz[1],i;
	sort(zz+1,zz+1+n*m);
	for(i=1;i<=n*m;i++){
		if(zz[i]==a){
			break;
		}
	}
	i=n*m+1-i;
	c=(i-1)/n+1;
	if((i-1)%(n*2)<n){
		r=(i-1)%n+1;
	}else{
		r=n+1-((i-1)%n+1);
	}
	cout<<c<<" "<<r;
	return 0;
}
