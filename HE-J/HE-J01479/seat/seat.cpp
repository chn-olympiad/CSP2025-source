#include<bits/stdc++.h>
using namespace std;
int a[150];
int n,m,zs,pm=1,xr,c,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	zs=n*m;
	for(int i=0;i<zs;i++){
		cin>>a[i];
	}
	xr=a[0];
	for(int i=0;i<zs;i++){
		if(a[i]>xr){
			pm++;
		}
	}
	if(pm%n==0){
		c=pm/n;
		r=n;
	}
	else{
		c=pm/n+1;
		r=pm%n;
	}
	if(c%2==0){
		r=n-r+1;
	}
	cout<<c<<' '<<r;
	return 0;
}
