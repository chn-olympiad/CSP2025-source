#include<bits/stdc++.h>
using namespace std;
int n,m,l,a[1001],c,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;l=n*m;
	for(int i=1; i<=l; i++)cin>>a[i];
	int k=a[1];sort(a+1,a+l+1,greater<>());
	for(int i=1; i<=l; i++){
		if(k==a[i]){
			c=(i+n-1)/n;
			r=i%n;
			if(!r)r=n;
			if(c%2==0)r=m-r+1;
			cout<<c<<" "<<r;
			break;
		} 
	}
	return 0;
} 
