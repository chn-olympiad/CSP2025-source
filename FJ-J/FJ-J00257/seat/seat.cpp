#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,xr=1,ls,hs,xrfs;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		int a;
		cin>>a;
		if(i==1){
			xrfs=a;
		}else if(a>xrfs){
			xr++;
		}
	}
	if(xr%n==0){
		ls=xr/n;	
	}else{
		ls=xr/n+1;
	}
	if(xr%n==0){
		if(ls&1)hs=n;
		else hs=1;
	}else{
		if(ls&1)hs=xr%n;
		else hs=n-(xr%n)+1;
	}
	cout<<ls<<" "<<hs;
	return 0;
}
