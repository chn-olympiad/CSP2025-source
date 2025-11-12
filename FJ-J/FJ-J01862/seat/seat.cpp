#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[125],res,c,r;
ll up(ll x,ll y){
	if(x%y) return x/y+1;
	return x/y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
    for(int i=1;i<=n*m;i++){
    	cin>>a[i];
    	if(a[i]>=a[1]){
    		res++;
		}
	}
	c=up(res,n);
	if(c&1) r=res-(c-1)*n;
	else r=n-(res-(c-1)*n)+1;
	cout<<c<<" "<<r;
    return 0;
}
