#include<bits/stdc++.h>
using namespace std;
long long a[105],n,m,r,c,d,xs,t;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	d=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		if(a[i]==d){
			xs=n*m-i+1;
			break;
		}
	}
	if(xs%n==0) c=xs/n;
	else c=xs/n+1;
	t=c-1;
	t=t*n;
	xs-=t;
	if(c%2==0) r=n-xs+1;
	else r=xs;
	cout<<c<<" "<<r;
	return 0;
} 
