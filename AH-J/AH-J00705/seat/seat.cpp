#include<bits/stdc++.h>
using namespace std;
int a[105],s=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,xr;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		xr=a[1];
		if(a[i]>xr){s++;}
	}int c,l;
	if(s%n==0){c=s/n;}
	else {c=s/n+1;}
	if(c%2==1){l=n-(c*n-s);}
	if(c%2==0){
		if(s%n==0){l=1;}
		else{l=n*c-s+1;}
	}cout<<c<<" "<<l;
}
