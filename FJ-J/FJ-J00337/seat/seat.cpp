#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[200],b[200];
ll n,m,r,c,k,l,h,s,p=1;
bool cmp(ll x,ll y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	l=n+n-1;
	for(ll i=1;i<=n*m;i++){
		cin>>a[i];
	}
	ll q=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(ll j=1;j<=n*m;j++){
		if(a[j]==q){
			h=j;
		}
	}
	b[p]=1;
	for(ll i=2;i<=n*m;i++){
		if(i%2==0){
			p++;
			b[p]=b[p-1]+l;
		}else if(i%2==1){
			p++;
			b[p]=b[p-1]+1;
		}
	}
	for(ll i=1;i<=p;i++){
		if(h>=b[i]&&h<b[i+1]){
			if(h>=b[i]&&h<=b[i]+n-1){
				c=i;
				r=h-b[i]+1;
			}else{
				c=i+1;
				r=b[i+1]-h+1;
			}
		}
	}
	cout<<c<<" "<<r;
	return 0;
}

