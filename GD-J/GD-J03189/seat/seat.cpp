#include<bits/stdc++.h>
using namespace std;
int a[110];
int ex(int x,int y){
	if(x>=y) return x;
	return y;
}
int f(int x,int y){
	if(x%y==0) return x/y;
	else return x/y+1;
}
int main(){
	freopen("seat.in");
	freopen("seat.out");
	int n,m,z,zz;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1) {
		z=a[i];
	}
	}
	sort(a+1,a+n*m+1,ex);
	for(int i=1;i<=n*m;i++){
		if(a[i]==z)  zz=i;
	}
	int r=f(zz,m);
	cout<<r<<' ';
	if(r%2!=0){
		if(zz%m==0){
			cout<<n;
		}
		else cout<<zz%m;
	}
	else{
		if(zz%m==0){
			cout<<1;
		}
		else{
			cout<<n+1-(zz%m);
		}
	}
	return 0;
}
