#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=10000+10;
ll a[N],c,r,R,n,m,op;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>a[1];
	R=a[1];
	for(ll i=2;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+n*m+1);
	for(ll i=n*m;i>=1;i--){
		if(a[i]==R)op=n*m-i+1;
	}
	r=op/n;
	if(op%n!=0)r++;
	if(r%2==1){
		c=op%n;
		if(c==0)c=n;
	}else{
		if(op%n==0)c=1;
		else c=n-(op%n)+1;
	}
	cout<<r<<" "<<c;
	return 0;
}
