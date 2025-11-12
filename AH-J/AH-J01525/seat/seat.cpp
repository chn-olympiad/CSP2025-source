#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,x,y,pm=1,xz,yz;
	cin>>n>>m>>x;
	for(int i=2;i<=n*m;i++){
		cin>>y;
		if(y>x) pm+=1;
	}
	yz=(pm-1)/m+1;
	if(yz%2){
		xz=pm%n;
		if(!xz) xz=n;
	}
	else{
		xz=n-pm%n+1;
		if(xz>n) xz=1;
	}
	cout<<yz<<" "<<xz;
	return 0;
}
