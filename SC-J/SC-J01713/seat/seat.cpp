#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m;
struct ST{
	ll x,y;
}a[1005];
bool cmp(ST l,ST r){
	return l.x<r.x;
}
int main(){
	cin>>n>>m;
	for(ll i=1;i<=n*m;i++){
		cin>>a[i].x;
		a[i].y=i;
	}
	sort(a+1,a+n*m+1,cmp);
	ll y=0,j=1;
	bool b=0;
	for(ll i=n*m;i>=1;i--){
		if(b==0){
			y++;
		}else{
			y--;
		}
	    if(y>n){
	    	y--;
	    	j++;
	    	b=1;
		}
		if(y<1){
			y++;
			j++;
			b=0;
		}
		if(a[i].y==1){
			cout<<j<<" "<<y;
			return 0;	
		}
	}

	
	
	
	return 0;
} 