#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[300];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>a[0];
	int s=a[0],mid=1;
	for(int i=1;i<n*m;i++){
		cin>>a[i];
		if(a[i]>s)mid++;
	}
	int x,y;
	if(mid%n==0){
		x=mid/n;
	}
	else {
		x=mid/n+1;
	}
	y=mid%(2*n);
	if(y==n+1){
		
	}
	if(y>n){
		y=n-(y%n)+1;
	}
	cout<<x<<" "<<y;
	return 0;
} 
