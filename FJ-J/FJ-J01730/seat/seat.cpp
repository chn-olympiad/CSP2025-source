#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],ans,pos,c,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	ans=a[1];
	sort(a+1,a+1+n*m);
	for(int i=n*m;i>=1;i--){
		if(a[i]==ans){
			pos=n*m-i+1;
			break;
		}
	}
	r=pos%n;
	c=(pos-r)/n+1;
	if(c%2==0){
		if(r==0) c-=1;
		cout<<c<<' '<<n-r+1;
	}
	else{
		if(r==0) c-=1;
		cout<<c<<' '<<r;
	}
	return 0;
} 

