#include<bits/stdc++.h>
#define ll long long 
using namespace std;


ll n,m,ans,x=1,y=1;
ll a[1000];


bool cmp(ll x,ll y){
	return x>y;
}


signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);

	
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n*m;i++){
		scanf("%lld",&a[i]);
	}
	
	
	ans=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(ll i=1;i<=n*m;i++){
		if(a[i]==ans){
			printf("%lld %lld\n",x,y);
			return 0;
		}
		if(x%2==1){
			if(y==n){
				x++;
			}
			else{
				y++;
			}
		}
		else{
			if(y==1){
				x++;
			}
			else{
				y--;
			}
		}
	}
	
	
	return 0;
}
