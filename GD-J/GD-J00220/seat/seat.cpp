#include<bits/stdc++.h>
using namespace std;short n,m;
short a[114];
bool ss(short x,short y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);freopen("seat.out","w",stdout);
	cin>>n>>m;short nm=n*m;
	for(short i=1;i<=nm;i++){
		cin>>a[i];
	}short R=a[1];short seat;
	sort(a+1,a+1+nm,ss);
	for(short i=1;i<=nm;i++){
		if(a[i]==R){
			seat=i;
		}
	}
	short c=(seat-1)/n+1;short r;
	if(c%2==1){
		r=seat%n;
	}else{
		r=n-seat%n+1;
	}
	cout<<c<<' '<<r;
	return 0;
}
