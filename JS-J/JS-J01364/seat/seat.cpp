#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	
	freopen("seat.in","w",stdin);
	freopen("seat.out","r",stdout);
	int c,r,m,n,a[105],count=1;
	cin>>m>>n;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	for(int i=1;i<n*m;i++){
		if(a[i]>a[0]){
			count++;
		}
	}
	c=count/n+1;
	if(c%2==0){
		r=n-count%n;
	}
	else{
		r=count%n;
	}
	cout<<c<<r;
	return 0;
}
