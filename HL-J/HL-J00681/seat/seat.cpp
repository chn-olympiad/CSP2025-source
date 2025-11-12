#include<bits/stdc++.h>
using namespace std;
int c,r,b;
int a[15],m,n;
int wzs;
int dh,dl;
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int z;
	z=n*m;;
	for(int i=1;i<=z;i++){
		cin>>a[i];
	}
	b=a[1];
	sort(a+1,a+z+1,cmp);
	for(int i=1;i<=z;i++){
		if(a[i]==b){
			wzs=i;
		}
	}
	if(wzs%n==0) c=wzs/n;
	else c=wzs/n+1;
	dh=wzs%n;
	if(dh==0){
		dh=n;
	}
	if(c%2==0) r=n-dh+1;
	else r=dh;
	cout<<c<<' '<<r;
	return 0;
}
