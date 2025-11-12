#include<bits/stdc++.h>
using namespace std;
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
int main(){
	int n,m,c,r,a[105],p,ci,q;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	a[1]=p;
	int tra;
	for(int i=1;i<=n*m;i++){
		for(int i=1;i<=n*m;i++){
		if(a[i]>a[i-1]){
			tra=a[i];
			a[i]=a[i-1];
			a[i-1]=a[i];
		}
	}
	}
	for(int i=1;i<=n*m;i++){
		if(a[i]==p){
			ci=i;
		}
	}
	if(ci%n==0){
		c=ci/n;
		if(c%2==1){
			r=1;
		}
		else{
			r=n;
		}
	}
	else{
		q=ci%n;
		c=ci/n+1;
		if(c%2==1){
			r=q;
		}
		else{
			r=n-q;
		}
	}
	cout<<c<<" "<<r;
	return 0£» 
}
