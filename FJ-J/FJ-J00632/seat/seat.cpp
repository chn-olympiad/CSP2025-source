#include<bits/stdc++.h>
using namespace std;
long long h,l,xr,t,pm,x,y;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>h>>l>>xr;
	pm=1;
	for(long long i=1;i<h*l;i++){
		cin>>t;
		if(xr<t)pm++;
	}
	x=pm/l;
	if(pm%l!=0)x++;
	cout<<x<<" ";
	if(x%2==1){
		cout<<pm-(x-1)*l;
	}
	else cout<<h-(pm-(x-1)*l)+1;
	return 0;
}

