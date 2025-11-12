#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[m*n];
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int x=a[0];
	int y;
	sort(a,a+m*n);
	for(int i=0;i<m*n;i++){
		if(x==a[i]){
			y=m*n-i;
		}
	}
	int c;
	if(y%n==0){
		c=y/n;
		if(c==0){
			c=1;
		}
	}
	else if(y%n!=0){
		c=y/n+1;
	}
	int r;
	if(c%2==0){
		r=n-y%n+1;
		if(r==0){
			r=2;
		}
	}
	else if(c%2!=0){
		r=y%n;
		if(r==0){
			r=m;
		}
	}
	cout<<c<<" "<<r;
	return 0;
}
